# $FreeBSD$

SUBDIR		= fortran libsrc ncgen ncdump nctest dumper

.include <bsd.subdir.mk>

test: all
	@for d in ${SUBDIR} ; do \
		echo "===> testing in $$d"; \
		cd $$d; \
		${MAKE} test; \
		cd ..; \
	done
