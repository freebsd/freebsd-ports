# MAINTAINER: rust@FreeBSD.org

BEGIN {
	# No approval required to add a new gitlab instance here
	gitlab_hosts["code.videolan.org"] = 1
	gitlab_hosts["foss.heptapod.net"] = 1
	gitlab_hosts["framagit.org"] = 1
	gitlab_hosts["gitlab.com"] = 1
	gitlab_hosts["gitlab.common-lisp.net"] = 1
	gitlab_hosts["gitlab.cs.fau.de"] = 1
	gitlab_hosts["gitlab.dune-project.org"] = 1
	gitlab_hosts["gitlab.freedesktop.org"] = 1
	gitlab_hosts["gitlab.gnome.org"] = 1
	gitlab_hosts["gitlab.howett.net"] = 1
	gitlab_hosts["gitlab.inria.fr"] = 1
	gitlab_hosts["gitlab.isc.org"] = 1
	gitlab_hosts["gitlab.linphone.org"] = 1
	gitlab_hosts["gitlab.mathematik.uni-stuttgart.de"] = 1
	gitlab_hosts["gitlab.mn.tu-dresden.de"] = 1
	gitlab_hosts["gitlab.mpcdf.mpg.de"] = 1
	gitlab_hosts["gitlab.redox-os.org"] = 1
	gitlab_hosts["gitlab.torproject.org"] = 1
	gitlab_hosts["gitlab.xfce.org"] = 1
	gitlab_hosts["invent.kde.org"] = 1
	gitlab_hosts["salsa.debian.org"] = 1
	gitlab_hosts["source.puri.sm"] = 1
}

function warn(fmt, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z) {
	printf("WARNING: " fmt "\n", a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z) >"/dev/stderr"
}

function commit_from_git_url(url) {
	if (url["query", "tag"]) {
		return url["query", "tag"]
	} else {
		return url["fragment"]
	}
}

function split_git_url(info, git_url,		url, path, account, project, commit, i, dir_ver, host, tag, fragment) {
	delete info
	split_url(url, git_url)
	url["scheme"] = tolower(url["scheme"])
	url["host"] = tolower(url["host"])
	if (url["scheme"] ~ /^git(\+https?)?$/) {
		if (url["host"] == "github.com") {
			split(url["path"], path, "/")
			account = path[2]
			project = path[3]
			sub(/\.[gG][iI][tT]$/, "", project)
			commit = commit_from_git_url(url)

			delete url
			url["scheme"] = "https"
			url["host"] = "codeload.github.com"
			url["path"] = sprintf("/%s/%s/tar.gz/%s", account, project, commit)
			url["query"] = "dummy"
			url["query", "dummy"] = "/"
			info["site"] = join_url(url)

			info["filename"] = sprintf("%s-%s-%s_GH0.tar.gz", account, project, commit)

			# Per bsd.sites.mk:
			# "GitHub silently converts tags starting with v to not have v in the filename
			# and extraction directory.  It also replaces + with -."
			dir_ver = commit
			if (dir_ver ~ /^[vV][0-9]/) {
				sub(/^[vV]/, "", dir_ver)
			}
			gsub(/\+/, "-", dir_ver)
			gsub(/--/, "-", dir_ver)
			info["dir"] = sprintf("%s-%s", project, dir_ver)

			return 1
		} else if (url["host"] == "codeberg.org") {
		    split(url["path"], path, "/")
			account = path[2]
			project = path[3]
			sub(/\.[gG][iI][tT]$/, "", project)
			commit = commit_from_git_url(url)

			delete url
			url["scheme"] = "https"
			url["host"] = "codeberg.org"
			url["path"] = sprintf("/%s/%s/archive/%s.tar.gz", account, project, commit)
			url["query"] = "dummy"
			url["query", "dummy"] = "/"
			info["site"] = join_url(url)

			info["filename"] = sprintf("%s-%s-%s_CB0.tar.gz", account, project, commit)

			info["dir"] = sprintf("%s", project)

			return 1
		} else if (gitlab_hosts[url["host"]]) {
			split(url["path"], path, "/")
			account = path[2]
			for (i = 3; i < length(path); i++) {
				account = account "/" path[i]
			}
			project = path[i]
			sub(/\.[gG][iI][tT]$/, "", project)
			commit = commit_from_git_url(url)
			fragment = url["fragment"]
			tag = url["query", "tag"]

			host = url["host"]
			delete url
			url["scheme"] = "https"
			url["host"] = host
			url["path"] = sprintf("/%s/%s/-/archive/%s.tar.gz", account, project, commit)
			url["query"] = "dummy"
			url["query", "dummy"] = "/"
			info["site"] = join_url(url)

			gsub(/\//, "-", account)
			info["filename"] = sprintf("%s-%s-%s_GL0.tar.gz", account, project, commit)

			# c.f. https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=266724
			if (tag) {
				info["dir"] = sprintf("%s-%s-%s", project, tag, fragment)
			} else {
				info["dir"] = sprintf("%s-%s", project, commit)
			}

			return 1
		}
	}

	warn("Do not know how to handle %s", git_url)
	warn("If it points to a GitLab instance try adding the hostname to gitlab_hosts[] at the top of cargo-crates-git-common.awk")
	return 0
}
