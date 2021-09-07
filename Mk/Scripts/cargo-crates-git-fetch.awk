# MAINTAINER: rust@FreeBSD.org
#
# Return (index, site, filename, wrksrc, crates) 5-tuples from git URL specs in CARGO_CRATES

END {
	split(GIT_SOURCES, git_sources)
	for (i = 1; i <= length(git_sources); i++) {
		git_source = git_sources[i]
		j = index(git_source, "@")
		if (j == 0) {
			warn("invalid source: %s", git_source)
		} else {
			crate_source = substr(git_source, j + 1)
			crates = substr(git_source, 0, j - 1)
			if (split_git_url(git_info, crate_source)) {
				printf("%d %s %s %s %s\n", group++, git_info["site"], git_info["filename"], git_info["dir"], crates)
			}
		}
	}
}
