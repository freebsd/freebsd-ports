# Created by: Joris Dedieu <joris.dedieu@gmail.com>

PORTNAME=	tinyows
PORTVERSION=	1.1.0
PORTREVISION=	4
CATEGORIES=	graphics www geography
MASTER_SITES=	https://download.osgeo.org/mapserver/

MAINTAINER=	joris.dedieu@gmail.com
COMMENT=	High Performance WFS-T server

DEPRECATED=	Depends on expired databases/postgis25
EXPIRATION_DATE=2022-03-31

LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		liblwgeom.so:databases/postgis25

USES=		pgsql tar:bzip2

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	FASTCGI
OPTIONS_DEFAULT=FASTCGI

FASTCGI_LIB_DEPENDS=	libfcgi.so:www/fcgi
FASTCGI_CONFIGURE_WITH=	fastcgi=${LOCALBASE}

post-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/cgi-bin/
	${INSTALL_PROGRAM} ${WRKSRC}/tinyows ${STAGEDIR}${WWWDIR}/cgi-bin/tinyows

.include <bsd.port.mk>
