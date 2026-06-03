# MAINTAINER: tagattie@FreeBSD.org

function oct2dec(octstr, i, c, val) {
	val = 0
	for (i = 1; i <= length(octstr); i++) {
		c = substr(octstr, i, 1)
		if (c < "0" || c > "7") {
			break
		}
		val = val * 8 + (c - "0")
	}
	return val
}

{
	if (match($0, /mode=[0-7]+/)) {
		mode_str = substr($0, RSTART+5, RLENGTH-5)
		mode = oct2dec(mode_str)
		exec_bits = 73				# 0o111
		special_bits = 3584			# 0o7000
		special = and(mode, special_bits)
		if (and(mode, exec_bits) != 0) {
			newmode = or(special, 493)	# 0o755
		} else {
			newmode = or(special, 420)	# 0o644
		}
		sub(/mode=[0-7]+/, "mode=" sprintf("%04o", newmode))
	}
	print
}
