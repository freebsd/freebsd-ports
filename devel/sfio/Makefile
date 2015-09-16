# Created by: jraynard
# $FreeBSD$

PORTNAME=	sfio
PORTVERSION=	1999
CATEGORIES=	devel
MASTER_SITES=	NETBSD
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.src.unix.cpio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Safe/Fast I/O Library

EXTRACT_CMD=	${CPIO}
EXTRACT_BEFORE_ARGS=	-idF
EXTRACT_AFTER_ARGS=	# empty
NO_WRKSUBDIR=	yes

# Remove a test that's too clever for its own good
post-extract:
	@${MV} ${WRKDIR}/src/lib/sfio/Sfio_t/tmmap2read.c \
		${WRKDIR}/src/lib/sfio/Sfio_t/.tmmap2read.c

do-build:
	@cd ${WRKDIR}/src/lib/sfio && ${MAKE} all -f makefile

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/sfio
	${INSTALL_DATA} ${WRKDIR}/include/* ${STAGEDIR}${PREFIX}/include/sfio
	(cd ${WRKDIR}/lib && ${INSTALL_DATA} libsfio.a libstdio.a ${STAGEDIR}${PREFIX}/lib)
	${INSTALL_MAN} ${WRKDIR}/man/man1/iffe.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKDIR}/man/man3/sfio.3 ${STAGEDIR}${PREFIX}/man/man3

.include <bsd.port.mk>
