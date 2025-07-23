PORTNAME=	virtualpg
PORTVERSION=	2.0.1
CATEGORIES=	databases geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Loadable dynamic extension to both SQLite and SpatiaLite
WWW=		https://www.gaia-gis.it/fossil/virtualpg/index

LICENSE=	MPL11 LGPL21 GPLv2
LICENSE_COMB=	dual
LICENSE_FILE_MPL11=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		gmake iconv pkgconfig libtool pgsql sqlite
USE_LDCONFIG=	yes

CFLAGS+=	-I${WRKSRC}/src/headers -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
CONFIGURE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libvirtualpg.so.0.1.1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mod_virtualpg.so.0.1.1

.include <bsd.port.mk>
