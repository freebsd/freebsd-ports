# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	spatialite_gui
PORTVERSION=	1.7.1
PORTREVISION=	4
CATEGORIES=	databases geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Graphical User Interface (GUI) tool supporting SpatiaLite

LICENSE=	GPLv3

LIB_DEPENDS=	libgaiagraphics.so:${PORTSDIR}/graphics/libgaiagraphics \
		libfreexl.so:${PORTSDIR}/textproc/freexl \
		libspatialite.so:${PORTSDIR}/databases/spatialite

USE_WX=		2.8
WANT_UNICODE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	libxml2
USES=		gmake pkgconfig iconv

CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include `${WX_CONFIG} --cppflags`
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB} `${WX_CONFIG} --libs`
CONFIGURE_ARGS=	CFLAGS="${CFLAGS} ${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

PLIST_FILES=	bin/spatialite_gui

.include <bsd.port.mk>
