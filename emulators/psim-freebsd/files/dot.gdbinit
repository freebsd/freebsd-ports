display/i $pc
define pglobal
	print *(struct globaldata *)$sprg0
end
target sim -e chirp -r 33554432
set architecture powerpc:604
load
