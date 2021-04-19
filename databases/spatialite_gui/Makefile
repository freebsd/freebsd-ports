# Created by: lbartoletti <lbartoletti@FreeBSD.org>

PORTNAME=	spatialite_gui
PORTVERSION=	1.7.1
PORTREVISION=	9
CATEGORIES=	databases geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Graphical User Interface (GUI) tool supporting SpatiaLite

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgaiagraphics.so:graphics/libgaiagraphics \
		libfreexl.so:textproc/freexl \
		libspatialite.so:databases/spatialite

USES=		compiler:c++11-lang gmake gnome iconv localbase:ldflags \
		pkgconfig
USE_WX=		2.8
GNU_CONFIGURE=	yes
USE_GNOME=	libxml2

CPPFLAGS+=	`${WX_CONFIG} --cppflags` "-DACCEPT_USE_OF_DEPRECATED_PROJ_API_H=1"
LDFLAGS+=	${ICONV_LIB} `${WX_CONFIG} --libs` -lsqlite3
CONFIGURE_ARGS=	CFLAGS="${CFLAGS} ${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

PLIST_FILES=	bin/spatialite_gui

.include <bsd.port.mk>
