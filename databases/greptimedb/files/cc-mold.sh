#!/bin/sh
# Wrapper: use cc for compilation, mold for linking
# Used to reduce memory during final binary linking
for arg in "$@"; do
	case "$arg" in
		-c|-E|-S|-xc|-x\ c*|-x\ assembler*|--version|-v|-print-*|-dump*)
			exec /usr/bin/cc "$@"
			;;
	esac
done
exec /usr/bin/cc -fuse-ld=mold "$@"
