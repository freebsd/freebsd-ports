# grr, commit_prep wants the next line
# $FreeBSD$
.SUFFIXES:  .py .pyc

all: _pgmodule.so pg.pyc pgdb.pyc

install: 
	@${MKDIR} ${PYTHON_SITELIBDIR}
	${BSD_INSTALL_PROGRAM} _pgmodule.so ${PYTHON_SITELIBDIR}
	${BSD_INSTALL_DATA} pg.py pg.pyc pgdb.py pgdb.pyc \
	    ${PYTHON_SITELIBDIR}

clean:
	rm -f *.so *.o *.pyc

_pgmodule.so: pgmodule.o
	${LD} -Bshareable -lc_r -L${PYTHON_LIBDIR}/config \
	    -l${PYTHON_VERSION} -L${PREFIX}/pgsql/lib -lpq \
	    ${.ALLSRC} -o ${.TARGET}

pgmodule.o: pgmodule.c
	${CC} -c -I${PREFIX}/include/${PYTHON_VERSION} \
	    -I${PREFIX}/pgsql/include ${.ALLSRC}

.py.pyc:
	${SETENV} PYTHONPATH=${.CURDIR} ${PYTHON} -c 'import ${.IMPSRC:.py=}'
