# $FreeBSD$

SUBDIR	 = src util test

hdf-test: all
	cd util && ${MAKE} test
	cd test && ${MAKE} test

.include <bsd.subdir.mk>
