error() {
	echo -e "$*" > /dev/stderr
}

pre_commit_error() {
	error "[pre-commit] ERROR: $*"
}
