PORTNAME=	tinyows
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	graphics www geography
MASTER_SITES=	https://download.osgeo.org/mapserver/

MAINTAINER=	joris.dedieu@gmail.com
COMMENT=	High Performance WFS-T server
WWW=		https://mapserver.org/tinyows/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	shp2pgsql:databases/postgis33
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		autoreconf gnome pgsql
USE_GNOME=	libxml2

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	FASTCGI
OPTIONS_DEFAULT=FASTCGI

FASTCGI_LIB_DEPENDS=	libfcgi.so:www/fcgi
FASTCGI_CONFIGURE_WITH=	fastcgi=${LOCALBASE}

post-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/cgi-bin/
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${WWWDIR}/cgi-bin

.include <bsd.port.mk>
