# ex:ts=8
# Ports collection makefile for:  sfio
# Date created:			  8 November 1997
# Whom:				  jraynard
#
# $FreeBSD$
#

PORTNAME=	sfio
PORTVERSION=	1999
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_NETBSD}
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.src.unix.cpio

MAINTAINER=	obrien@FreeBSD.org

EXTRACT_CMD=	cpio
EXTRACT_BEFORE_ARGS=	-idF
EXTRACT_AFTER_ARGS=	# empty
NO_WRKSUBDIR=	yes
MAN1=		iffe.1
MAN3=		sfio.3

# Remove a test that's too clever for its own good
post-extract:
	@${MV} ${WRKDIR}/src/lib/sfio/Sfio_t/tmmap2read.c \
		${WRKDIR}/src/lib/sfio/Sfio_t/.tmmap2read.c

do-build:
	@cd ${WRKDIR}/src/lib/sfio && ${MAKE} all -f makefile

do-install:
	${MKDIR} ${PREFIX}/include/sfio
	${INSTALL_DATA} ${WRKDIR}/include/* ${PREFIX}/include/sfio
	cd ${WRKDIR}/lib ; ${INSTALL_DATA} libsfio.a libstdio.a ${PREFIX}/lib
	${INSTALL_MAN} ${WRKDIR}/man/man1/iffe.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKDIR}/man/man3/sfio.3 ${PREFIX}/man/man3

.include <bsd.port.mk>
