# $FreeBSD$
all:
	make -f Makefile.flib X11BASE="${X11BASE}"
	make -f Makefile.clib
	make -f Makefile.bin X11BASE="${X11BASE}"
	make -f Makefile.doc

install:
	install -c *.a *.so.5* ${PREFIX}/lib
	mkdir -p ${PREFIX}/share/pgplot
	install -c grfont.dat rgb.txt pgplot.doc pgplot.html pgplot-routines.tex cpg/cpgplot.doc ${PREFIX}/share/pgplot
	install -c cpgplot.h ${PREFIX}/include
	install -c  Makefile.demo examples/pgdemo*.f cpg/cpgdemo.c  ${PREFIX}/share/pgplot
	cp pgdispd/aaaread.me ${PREFIX}/share/pgplot/readme.pgdisp
	install -c -s  pgxwin_server pgdisp ${PREFIX}/bin
