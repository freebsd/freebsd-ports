D=examples/
all:
	make -f Makefile.flib
	make -f Makefile.clib
	make -f Makefile.bin 
	make -f Makefile.doc

install:
	install -c *.a *.so.5* ${PREFIX}/lib
	mkdir -p ${PREFIX}/share/pgplot
	install -c grfont.dat rgb.txt pgplot.doc pgplot.html pgplot-routines.tex cpg/cpgplot.doc ${PREFIX}/share/pgplot
	install -c cpgplot.h ${PREFIX}/include
	install -c  Makefile.demo examples/pgdemo*.f cpg/cpgdemo.c  ${PREFIX}/share/pgplot
	cp pgdispd/aaaread.me ${PREFIX}/share/pgplot/readme.pgdisp
	install -c -s  pgxwin_server pgdisp ${PREFIX}/bin

