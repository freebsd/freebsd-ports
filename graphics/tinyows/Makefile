# Created by: Joris Dedieu <joris.dedieu@gmail.com>
# $FreeBSD$

PORTNAME=		tinyows
PORTVERSION=		1.1.0
PORTREVISION=		1
CATEGORIES=		graphics www geography
MASTER_SITES=		http://download.osgeo.org/mapserver/

MAINTAINER=		joris.dedieu@gmail.com
COMMENT=		High Performance WFS-T server

LIB_DEPENDS=		libxml2.so:textproc/libxml2
BUILD_DEPENDS=		${LOCALBASE}/lib/postgresql/postgis-2.1.so:databases/postgis21

USES=		tar:bzip2
GNU_CONFIGURE=		YES

OPTIONS_DEFINE=		FASTCGI
OPTIONS_DEFAULT=	FASTCGI

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFASTCGI}
BUILD_DEPENDS+=	${LOCALBASE}/bin/cgi-fcgi:www/fcgi
CONFIGURE_ARGS+=	--with-fastcgi=${LOCALBASE}
.endif

post-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/cgi-bin/
	${INSTALL_PROGRAM} ${WRKSRC}/tinyows ${STAGEDIR}${WWWDIR}/cgi-bin/tinyows

.include <bsd.port.mk>
