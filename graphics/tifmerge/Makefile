# New ports collection makefile for:	tifmerge
# Version required:	1.0
# Date created:		29 April 1999
# Whom:			G. Adam Stanislav <adam@whizkidtech.net>
#
# $FreeBSD$
#

DISTNAME=	tiff
PKGNAME=	tifmerge-1.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.whizkidtech.net/fports/

MAINTAINER=	adam@whizkidtech.net

BUILD_DEPENDS=	tuc:${PORTSDIR}/converters/tuc

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

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
