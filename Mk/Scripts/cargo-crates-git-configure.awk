# MAINTAINER: rust@FreeBSD.org

function parse_sources(		sources_len, raw_sources, i, j, k, original_crate_source, url, crate_source, crate_names, crate_name) {
	sources_len = 0
	split(GIT_SOURCES, raw_sources)
	for (i = 1; i <= length(raw_sources); i++) {
		j = index(raw_sources[i], "@")
		if (j == 0) {
			warn("invalid source: %s\n", raw_sources[i])
			continue
		}
		original_crate_source = substr(raw_sources[i], j + 1)
		split_url(url, original_crate_source)
		sub(/^git\+/, "", url["scheme"])
		delete url["fragment"]
		delete url["query"]
		#sub(/\.git$/, "", url["path"])
		crate_source = join_url(url)

		split(substr(raw_sources[i], 1, j - 1), crate_names, ",")
		for (k = 1; k <= length(crate_names); k++) {
			crate_name = crate_names[k]
			if (!source_crates[crate_source]) {
				sources[++sources_len] = crate_source
			}
			source_crates[crate_source] = source_crates[crate_source] " " crate_name
			original_crate_sources[crate_source, crate_name] = original_crate_source
		}
	}
}

function get_source_dir(crate_source, crate_name,		git_info, path, in_package, pattern, cmd, cargotoml, line) {
	if (!split_git_url(git_info, original_crate_sources[crate_source, crate_name])) {
		exit 1
	}
	path = WRKDIR "/" git_info["dir"]
	# Try to find the first Cargo.toml that defines our crate
	# We are looking for
	# [package]
	# name = "$crate_name"
	in_package = 0
	pattern = sprintf("^[ \t]*name[ \t]*=[ \t]*['\"]%s['\"]", crate_name)
	cmd = FIND " " path " -name Cargo.toml -type f"
	while ((cmd | getline cargotoml) > 0) {
		while (getline line <cargotoml) {
			if (in_package && line ~ pattern) {
				path = cargotoml
				sub(/\/Cargo\.toml$/, "", path)
				close(cmd)
				close(cargotoml)
				return path
			} else if (line ~ /^[ \t]*\[[ \t]*package[ \t]*\][ \t]*$/) {
				in_package = 1
			} else if (line ~ /^[ \t]*\[/) {
				in_package = 0
			}
		}
		close(cargotoml)
	}
	close(cmd)

	return path
}

function find_replaced_crates(input, output,		in_patch_crates_io, line, cols) {
	delete replaced_crates
# When Cargo.toml has constructs like this (e.g., www/miniserve, x11/wezterm )
# [patch.crates-io]
# mime_guess = { git = "https://github.com/svenstaro/mime_guess.git" }
# cargo fails to find the replacements we setup.  Check for this
# and replace with our own [patch.crates-io] section.
# Note that we need to filter out the original patch section.
	in_patch_crates_io = 0
	while (getline line <input) {
		if (in_patch_crates_io) {
			if (line ~ /[ \t]*git[ \t]*=/ && line !~ /^[ \t]*#/) {
				split(line, cols)
				replaced_crates[cols[1]] = 1
				print "# " line >output
				continue
			}
		} else if (line ~ /^[ \t]*\[[ \t]*patch\.crates-io[ \t]*\][ \t]*$/) {
			in_patch_crates_io = 1
		} else if (line ~ /^[ \t]*\[/) {
			in_patch_crates_io = 0
		}
		print line >output
	}
	close(input)
	close(output)
}

function add_crates_io_patches(		header_printed, cmd, cargotoml, source, crates) {
	header_printed = 0
# --exclude-dir not supported on FreeBSD < 13
#	cmd = GREP " --include='*/Cargo.toml' --exclude-dir='" CARGO_VENDOR_DIR "' -Flr 'patch.crates-io' " WRKSRC
	cmd = FIND " " WRKSRC " -name Cargo.toml -not -path '" CARGO_VENDOR_DIR "/*' -exec " GREP " -Flr 'patch.crates-io' {} \\\+"
	while (cmd | getline cargotoml) {
		if (0 != system(CP " " cargotoml " " cargotoml ".orig-cargo")) {
			exit 1
		}
		find_replaced_crates(cargotoml ".orig-cargo", cargotoml)
		if (length(replaced_crates) > 0) {
			for (i in sources) {
				source = sources[i]
				split(source_crates[source], crates)
				for (j in crates) {
					if (replaced_crates[crates[j]]) {
						if (!header_printed) {
							printf("[patch.crates-io]\n")
							header_printed = 1
						}
						printf("%s = { path = '%s' }\n", crates[j], get_source_dir(source, crates[j]))
					}
				}
			}
		}
	}
	close(cmd)
}

function add_git_patches(		i, j, source, crates) {
	for (i = 1; i <= length(sources); i++) {
		source = sources[i]
		split(source_crates[source], crates)
		printf("[patch.'%s']\n", source)
		for (j = 1; j <= length(crates); j++) {
			printf("%s = { path = '%s' }\n", crates[j], get_source_dir(source, crates[j]))
		}
	}
}

END {
	parse_sources()
	add_crates_io_patches()
	add_git_patches()
}
