# Created by: G. Adam Stanislav <adam@whizkidtech.net>
# $FreeBSD$

PORTNAME=	tifmerge
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.whizkidtech.redprince.net/fports/
DISTNAME=	tiff

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to merge TIFF files into multi-page TIFF files

USES=		dos2unix zip
DOS2UNIX_GLOB=	*.[ch]
USE_LDCONFIG=	yes
NO_WRKSUBDIR=	yes
DIST_SUBDIR=	tifmerge

PLIST_FILES=	lib/libtifmerge.a \
		include/tifmerge.h \
		lib/libtifmerge.so \
		lib/libtifmerge.so.1 \
		man/man3/tifmerge.3.gz

post-extract:
	@${MV} ${WRKSRC}/TIFMERGE.H ${WRKSRC}/tifmerge.h
	@${MV} ${WRKSRC}/TIFMERGE.C ${WRKSRC}/tifmerge.c
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}
	@${SED} -e 's|@PREFIX@|${PREFIX}|g' ${FILESDIR}/tifmerge.3 > \
		${WRKSRC}/tifmerge.3

do-install:
	${INSTALL_LIB} ${WRKSRC}/libtifmerge.so.1 ${STAGEDIR}${PREFIX}/lib
	${LN} -fs libtifmerge.so.1 ${STAGEDIR}${PREFIX}/lib/libtifmerge.so
	${INSTALL_DATA} ${WRKSRC}/libtifmerge.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/tifmerge.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/tifmerge.3 ${STAGEDIR}${MAN3PREFIX}/man/man3

.include <bsd.port.mk>
