#!/bin/sh

# Tool to find work (such as unassigned Bugzilla PRs) to port committers or
# perhaps other developers based on the list of locally installed ports.
# More sources can be added later (such as GitHub pull requests).
#
# SPDX-License-Identifier: BSD-2-Clause
# Copyright (c) 2025 René Ladan <rene@FreeBSD.org>
# MAINTAINER=rene@FreeBSD.org

set -eu

# Look for PRs in Bugzilla having $1 in the summary line (as opposed to the full
# PR content), and add each such PR to the output (PR number, assignee, summary)
# if it is not assigned some FreeBSD.org, with the exception of
# ports-bugs@FreeBSD.org. The matching is case-insensitive.
get_PRs()
{
	catport=${1}
	category="$(echo "${catport}" | cut -f 1 -d /)"
	port="$(echo "${catport}" | cut -f 2 -d /)"
	timeout=20 # seconds

	echo "getting Bugzilla PRs having ${catport} in the synopsis" >&2
	# content= looks for the search string in all of the pr content,
	# summary= only looks in the summary line
	url="https://bugs.freebsd.org/bugzilla/rest/bug?bug_status=__open__&product=Ports%20%26%20Packages&summary=${category}%2f${port}"
	raw="$(fetch -q -T ${timeout} -o - "${url}")"
	# Enable the next line to get full JSON output in per-port files for debugging
	# echo "${raw}" > "${category}-${port}.json"
	if [ -z "${raw}" ] ; then
		echo "${catport}: no REST reply within ${timeout} seconds from URL: ${url}" >&2
		exit 67
	fi
	pr_list="$(echo "${raw}" | jq '[.bugs | map(select(.assigned_to | test("ports-bugs@freebsd.org";"i") or test("@freebsd.org";"i") == false)).[] | {id,assigned_to,summary}]')"

	# The below code is just to get one line per PR in the output.
	num_prs=$(echo "${pr_list}" | jq length)
	if [ ${num_prs} -gt 0 ] ; then
		for i in $(jot ${num_prs} 0) ; do
			echo "${pr_list}" | jq -r --argjson i ${i} '[.[$i].id,.[$i].assigned_to,.[$i].summary] | @tsv'
		done
	fi
}

if ! which jq >/dev/null ; then
	echo "Please install textproc/jq" >&2
	exit 66
fi

# Iterate through all installed ports which are not maintained by a FreeBSD.org
# address (this includes ports-bugs and possibly you), and for each such port
# see if there is output from get_PR() and if so, report it grouped by the port
# maintainer.
for p in $(pkg query -e '%m !~ *@FreeBSD.org' %o,%m) ; do
	origin=$(echo "${p}" | cut -f 1 -d ,)
	maintainer=$(echo "${p}" | cut -f 2 -d ,)

	# see if there is a Bugzilla report for ${origin}
	bz="$(get_PRs "${origin}")"
	if [ -n "${bz}" ] ; then
		printf "** %s\n%s\n" "${maintainer}" "${bz}"
	fi
done
