.SUFFIXES:  .py .pyc

all: pgmodule.so pgext.pyc pgtools.pyc

install: 
	@${MKDIR} ${PREFIX}/lib/site-python
	${BSD_INSTALL_PROGRAM} pgmodule.so ${PREFIX}/lib/site-python
	${BSD_INSTALL_DATA} pgext.py pgext.pyc pgtools.py pgtools.pyc \
		${PREFIX}/lib/site-python

clean:
	rm -f *.so *.o *.pyc pgtools.py

pgtools.py: tutorial/pgtools.py
	${LN} -fs ${.ALLSRC} ${.TARGET}

pgmodule.so: pgmodule.o
	${LD} -Bshareable -lc_r -L${PREFIX}/lib/python1.5/config -lpython1.5 \
		-L${PREFIX}/pgsql/lib -lpq ${.ALLSRC} -o ${.TARGET}

pgmodule.o: pgmodule.c
	${CC} -c -I${PREFIX}/include/python1.5 -I${PREFIX}/pgsql/include \
		 ${.ALLSRC}

.py.pyc:
	${SETENV} PYTHONPATH=${.CURDIR} ${PYTHON} -c 'import ${.IMPSRC:.py=}'
