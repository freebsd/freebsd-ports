# $FreeBSD$

PROG		 = ncgen
MANDIR		 = ${PREFIX}/man/man
LDFLAGS		+= -L${.CURDIR}/../libsrc -L${.CURDIR}/../../hdf/src -lmfhdf -ldf
CFLAGS		+= -I${.CURDIR}/../libsrc -I${.CURDIR}/../../hdf/src -DNDEBUG
SRCS		 = main.c generate.c load.c ncgentab.c escapes.c \
		  getfill.c init.c close.c genlib.c

ENVIR		 = env LD_LIBRARY_PATH=${.CURDIR}/../libsrc:${.CURDIR}/../../hdf/src
NCDUMP		 = ${.CURDIR}/../ncdump/ncdump

test:           $(PROG) test0.cdl btest ctest ftest

ncgenyy.c: ncgen.l
	${LEX} ${LFLAGS} ncgen.l
	mv lex.yy.c ncgenyy.c
	
ncgentab.c: ncgenyy.c ncgen.y
	${YACC} ${YFLAGS} ncgen.y
	mv y.tab.c ncgentab.c
	mv y.tab.h ncgentab.h

.include <bsd.prog.mk>

#
# test "-b" option of ncgen
#
btest:		$(PROG) test0.cdl test1.cdl
	${ENVIR} ./$(PROG) -b test1.cdl
	${ENVIR} $(NCDUMP) test1.nc > test2.cdl
	@diff test1.cdl test2.cdl && \
	    echo "*** $(PROG) -b test successful ***"

#
# test "-c" option of ncgen
#
ctest:		test1.cdl ctest0
	${ENVIR} ./ctest0		# tests `-c' option, creates ctest0.nc
	${ENVIR} $(NCDUMP) -n test1 ctest0.nc > ctest1.cdl
	@diff test1.cdl ctest1.cdl && \
	    echo "*** $(PROG) -c test successful ***"

ctest0:		ncgen test0.cdl
	${ENVIR} ./$(PROG) -c -o ctest0.nc test0.cdl > test0.c
	$(CC) $(CFLAGS) -o $@ test0.c ${LDFLAGS}

#
# test "-f" option of ncgen
#
ftest:	test1.cdl ftest0
	${ENVIR} ./ftest0
	${ENVIR} $(NCDUMP) -n test1 ftest0.nc > ftest1.cdl
	@if diff test1.cdl ftest1.cdl; then \
		echo "*** ncgen -f test successful ***"; \
	else \
		echo "*** ncgen -f test failed " \
		    "(but roundoff differences are OK) ***"; \
	fi

ftest0:	$(PROG) test0.cdl netcdf.inc
	${ENVIR} ./$(PROG) -f -o ftest0.nc test0.cdl > test0.f; \
	$(FC) $(FFLAGS) ${CFLAGS} -o $@ test0.f ${LDFLAGS}

test1.cdl:	test0.nc
	${ENVIR} $(NCDUMP) -n test1 test0.nc > $@

test0.nc:	$(PROG) test0.cdl
	${ENVIR} ./$(PROG) -b -o test0.nc test0.cdl

netcdf.inc:
	ln -s ../fortran/config/netcdf-fbsd.inc $@
