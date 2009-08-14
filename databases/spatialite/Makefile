# New ports collection makefile for:	spatialite
# Date created:				11 July 2008
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	spatialite
PORTVERSION=	2.2
PORTREVISION=	2
CATEGORIES=	databases geography
MASTER_SITES=	http://www.gaia-gis.it/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	wenheping@gmail.com
COMMENT=	Spatial Extensions for SQLite

LIB_DEPENDS=	geos_c.7:${PORTSDIR}/graphics/geos/ \
		proj.5:${PORTSDIR}/graphics/proj/ \
		iconv.3:${PORTSDIR}/converters/libiconv/

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -liconv
CONFIGURE_ARGS+=CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's#-ldl##g' ${WRKSRC}/src/sqlite3/Makefile.in
	@${REINPLACE_CMD} -e 's#-ldl##g' ${WRKSRC}/src/shell/Makefile.in

.include <bsd.port.mk>
