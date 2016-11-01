#!/bin/sh
# $FreeBSD$
#
# MAINTAINER: portmgr@FreeBSD.org

set -e

. "${dp_SCRIPTSDIR}/functions.sh"

validate_env dp_ECHO_MSG dp_GID_FILES dp_GID_OFFSET dp_GROUPS_BLACKLIST \
	dp_INSTALL dp_OPSYS dp_OSVERSION dp_PREFIX dp_PW dp_SCRIPTSDIR \
	dp_UG_DEINSTALL dp_UG_INSTALL dp_UID_FILES dp_UID_OFFSET \
	dp_USERS_BLACKLIST

[ -n "${DEBUG_MK_SCRIPTS}" -o -n "${DEBUG_MK_SCRIPTS_DO_USERS_GROUPS}" ] && set -x

set -u

USERS=$1
GROUPS=$2

error() {
	${dp_ECHO_MSG} "${1}"

	exit 1
}

rm -f "${dp_UG_INSTALL}" "${dp_UG_DEINSTALL}" || :

# Before FreeBSD 10.2, PW did not have -R support.
if [ "${dp_OPSYS}" = FreeBSD ] && [ "${dp_OSVERSION}" -ge 1002000 ]; then
	cat >> "${dp_UG_INSTALL}" <<-eot
	if [ -n "\${PKG_ROOTDIR}" ] && [ "\${PKG_ROOTDIR}" != "/" ]; then
	  PW="${dp_PW} -R \${PKG_ROOTDIR}"
	else
	  PW=${dp_PW}
	fi
	eot
else
	echo "PW=${dp_PW}" >> "${dp_UG_INSTALL}"
fi

# Both scripts need to start the same, so
cp -f "${dp_UG_INSTALL}" "${dp_UG_DEINSTALL}"

if [ -n "${GROUPS}" ]; then
	for file in ${dp_GID_FILES}; do
		if [ ! -f "${file}" ]; then
			error "** ${file} doesn't exist. Exiting."
		fi
	done
	${dp_ECHO_MSG} "===> Creating groups."
	echo "echo \"===> Creating groups.\"" >> "${dp_UG_INSTALL}"
	for group in ${GROUPS}; do
		# _bgpd:*:130:
		if ! grep -q "^${group}:" ${dp_GID_FILES}; then \
			error "** Cannot find any information about group \`${group}' in ${dp_GID_FILES}."
		fi
		o_IFS=${IFS}
		IFS=":"
		while read -r group _ gid _; do
			if [ -z "${gid}" ]; then
				error "Group line for group ${group} has no gid"
			fi
			gid=$((gid+dp_GID_OFFSET))
			cat >> "${dp_UG_INSTALL}" <<-eot2
			if ! \${PW} groupshow $group >/dev/null 2>&1; then
			  echo "Creating group '$group' with gid '$gid'."
			  \${PW} groupadd $group -g $gid
			else
			  echo "Using existing group '$group'."
			fi
			eot2
		done <<-eot
		$(grep -h "^${group}:" ${dp_GID_FILES} | head -n 1)
		eot
		IFS=${o_IFS}
	done
fi

if [ -n "${USERS}" ]; then
	for file in ${dp_UID_FILES}; do
		if [ ! -f "${file}" ]; then
			error "** ${file} doesn't exist. Exiting."
		fi
	done

	${dp_ECHO_MSG} "===> Creating users"
	echo "echo \"===> Creating users\"" >> "${dp_UG_INSTALL}"

	for user in ${USERS}; do
		# _bgpd:*:130:130:BGP Daemon:/var/empty:/sbin/nologin
		if ! grep -q "^${user}:" ${dp_UID_FILES} ; then
			error "** Cannot find any information about user \`${user}' in ${dp_UID_FILES}."
		fi
		o_IFS=${IFS}
		IFS=":"
		while read -r login _ uid gid class _ _ gecos homedir shell; do
			if [ -z "$uid" ] || [ -z "$gid" ] || [ -z "$homedir" ] || [ -z "$shell" ]; then
				error "User line for ${user} is invalid"
			fi
			uid=$((uid+dp_UID_OFFSET))
			gid=$((gid+dp_GID_OFFSET))
			if [ -n "$class" ]; then
				class="-L $class"
			fi
			homedir=$(echo "$homedir" | sed "s|^/usr/local|${dp_PREFIX}|")
			cat >> "${dp_UG_INSTALL}" <<-eot2
			if ! \${PW} usershow $login >/dev/null 2>&1; then
			  echo "Creating user '$login' with uid '$uid'."
			  \${PW} useradd $login -u $uid -g $gid $class -c "$gecos" -d $homedir -s $shell
			else
			  echo "Using existing user '$login'."
			fi
			eot2
			case $homedir in
				/|/nonexistent|/var/empty)
					;;
				*)
					group=$(awk -F: -v gid=${gid} '$3 == gid { print $1 }' ${dp_GID_FILES})
					echo "${dp_INSTALL} -d -g $group -o $login $homedir" >> "${dp_UG_INSTALL}"
					;;
			esac
		done <<-eot
		$(grep -h "^${user}:" ${dp_UID_FILES} | head -n 1)
		eot
		IFS=${o_IFS}
	done
fi

if [ -n "${GROUPS}" ]; then
	for group in ${GROUPS}; do
		# mail:*:6:postfix,clamav
		o_IFS=${IFS}
		IFS=":"
		while read -r group _ gid members; do
			gid=$((gid+dp_GID_OFFSET))
			oo_IFS=${IFS}
			IFS=","
			for login in $members; do
				for user in ${USERS}; do
					if [ -n "${user}" ] && [ "${user}" = "${login}" ]; then
						cat >> "${dp_UG_INSTALL}" <<-eot2
						if ! \${PW} groupshow ${group} | grep -qw ${login}; then
						  echo "Adding user '${login}' to group '${group}'."
						  \${PW} groupmod ${group} -m ${login}
						fi
						eot2
					fi
				done
			done
			IFS=${oo_IFS}
		done <<-eot
		$(grep -h "^${group}:" ${dp_GID_FILES} | head -n 1)
		eot
		IFS=${o_IFS}
	done
fi

if [ -n "${USERS}" ]; then
	for user in ${USERS}; do
		if ! echo "${dp_USERS_BLACKLIST}" | grep -qw "${user}"; then
			cat >> "${dp_UG_DEINSTALL}" <<-eot
			if \${PW} usershow ${user} >/dev/null 2>&1; then
			  echo "==> You should manually remove the \"${user}\" user. "
			fi
			eot
		fi
	done
fi

if [ -n "${GROUPS}" ]; then
	for group in ${GROUPS}; do
		if ! echo "${dp_GROUPS_BLACKLIST}" | grep -qw "${group}"; then
			cat >> "${dp_UG_DEINSTALL}" <<-eot
			if \${PW} groupshow ${group} >/dev/null 2>&1; then
			  echo "==> You should manually remove the \"${group}\" group "
			fi
			eot
		fi
	done
fi
