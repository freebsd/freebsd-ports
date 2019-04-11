package require tcltest

source test.setup

namespace import ::tcltest::*

foreach c {hasZlib hasSSL hasBz} {
	testConstraint $c 1
}

proc defblock {name hexdata} {
	upvar $name x

	regsub -all { *} $hexdata {} hexdata
	regsub -all "\n" $hexdata {} hexdata
	# single long hex string now

	set x $hexdata
}

configure -singleproc true -verbose bel

testsDirectory tests
runAllTests
