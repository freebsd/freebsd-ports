# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	spatialite_gui
PORTVERSION=	1.7.1
PORTREVISION=	6
CATEGORIES=	databases geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Graphical User Interface (GUI) tool supporting SpatiaLite

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgaiagraphics.so:graphics/libgaiagraphics \
		libfreexl.so:textproc/freexl \
		libspatialite.so:databases/spatialite

USE_WX=		2.8
WX_UNICODE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	libxml2
USES=		gmake pkgconfig iconv

CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include `${WX_CONFIG} --cppflags`
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB} `${WX_CONFIG} --libs` -lsqlite3
CONFIGURE_ARGS=	CFLAGS="${CFLAGS} ${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

PLIST_FILES=	bin/spatialite_gui

.include <bsd.port.mk>
