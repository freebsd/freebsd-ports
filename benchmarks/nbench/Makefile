# New ports collection makefile for:	nbench
# Version required:			2.1
# Date created:				17 December 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		nbench-byte-2.1
PKGNAME=		nbench-2.1
CATEGORIES=		benchmarks
MASTER_SITES=		ftp://ftp.tux.org/pub/tux/mayer/ \
			${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/benchmark

MAINTAINER=		andy@icc.surw.chel.su

ALL_TARGET=

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/nbench ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/nbench
	@ ${INSTALL_DATA} ${WRKSRC}/NNET.DAT ${PREFIX}/share/nbench
	@ ${MKDIR} ${PREFIX}/share/doc/nbench
.for file in README README.submit RESULTS bdoc.txt
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/nbench
.endfor

.include <bsd.port.mk>
