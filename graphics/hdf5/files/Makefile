# $FreeBSD$

SUBDIR	 = hdf mfhdf man
#PREFIX	?= /usr/local
LIBDIR	?= ${PREFIX}/lib
BINDIR	?= ${PREFIX}/bin

.MAKEFLAGS: PREFIX=${PREFIX} LIBDIR=${LIBDIR} BINDIR=${BINDIR}

test: all
	# testing in hdf
	@cd hdf && ${MAKE} hdf-test
	# testing in mfhdf
	@cd mfhdf && ${MAKE} test

.include <bsd.subdir.mk>
