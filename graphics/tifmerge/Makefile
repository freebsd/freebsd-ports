# New ports collection makefile for:	tifmerge
# Date created:		29 April 1999
# Whom:			G. Adam Stanislav <adam@whizkidtech.net>
#
# $FreeBSD$
#

PORTNAME=	tifmerge
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.whizkidtech.redprince.net/fports/
DISTNAME=	tiff

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to merge TIFF files into multi-page TIFF files

EXTRACT_DEPENDS=	tuc:${PORTSDIR}/converters/tuc

INSTALLS_SHLIB=	yes
USE_ZIP=	yes
DIST_SUBDIR=	tifmerge
MAN3=		tifmerge.3

post-extract:
	@${MKDIR} ${WRKSRC}
	@tuc ${WRKDIR}/TIFMERGE.H ${WRKSRC}/tifmerge.h
	@tuc ${WRKDIR}/TIFMERGE.C ${WRKSRC}/tifmerge.c
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}
	@${SED} -e 's|@PREFIX@|${PREFIX}|g' ${FILESDIR}/tifmerge.3 > \
		${WRKSRC}/tifmerge.3

do-install:
	${INSTALL_DATA} ${WRKSRC}/libtifmerge.so.1 ${PREFIX}/lib
	${LN} -fs ${PREFIX}/lib/libtifmerge.so.1 ${PREFIX}/lib/libtifmerge.so
	${INSTALL_DATA} ${WRKSRC}/libtifmerge.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/tifmerge.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/tifmerge.3 ${PREFIX}/man/man3

.include <bsd.port.mk>
