# Created by: Loïc BARTOLETTI <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	virtualpg
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	databases geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Loadable dynamic extension to both SQLite and SpatiaLite

LICENSE=	MPL11 LGPL21 GPLv2
LICENSE_COMB=	dual
LICENSE_FILE_MPL11=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		gmake iconv pathfix pkgconfig libtool pgsql sqlite
USE_LDCONFIG=	yes

CFLAGS+=	-I${WRKSRC}/src/headers -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
CONFIGURE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

PLIST_FILES=	lib/mod_virtualpg.so \
		lib/mod_virtualpg.so.1 \
		lib/mod_virtualpg.so.1.0.0

.include <bsd.port.mk>
