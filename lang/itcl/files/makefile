all:
	for f in ../generic/*.o; do ln -sf $$f; done
	make -f Makefile itclsh
test:
	make -f Makefile test
install:
	make -f Makefile install

