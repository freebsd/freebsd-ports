.SUFFIXES:  .py .pyc

SITE_PACKAGES=${PREFIX}/lib/python1.5/site-packages

all: _pgmodule.so pg.pyc pgtools.pyc

install: 
	@${MKDIR} ${SITE_PACKAGES}
	${BSD_INSTALL_PROGRAM} _pgmodule.so ${SITE_PACKAGES}
	${BSD_INSTALL_DATA} pg.py pg.pyc pgtools.py pgtools.pyc \
		${SITE_PACKAGES}

clean:
	rm -f *.so *.o *.pyc pgtools.py

pgtools.py: tutorial/pgtools.py
	${LN} -fs ${.ALLSRC} ${.TARGET}

_pgmodule.so: pgmodule.o
	${LD} -Bshareable -lc_r -L${PREFIX}/lib/python1.5/config -lpython1.5 \
		-L${PREFIX}/pgsql/lib -lpq ${.ALLSRC} -o ${.TARGET}

pgmodule.o: pgmodule.c
	${CC} -c -I${PREFIX}/include/python1.5 -I${PREFIX}/pgsql/include \
		 ${.ALLSRC}

.py.pyc:
	${SETENV} PYTHONPATH=${.CURDIR} ${PYTHON} -c 'import ${.IMPSRC:.py=}'
