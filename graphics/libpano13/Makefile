# Created by: Vasil Dimov <vd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libpano13
PORTVERSION=	2.9.19
PORTREVISION=	1
CATEGORIES=	graphics java
MASTER_SITES=	SF/panotools/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	grog@FreeBSD.org
COMMENT=	Cross-platform library behind Panorama Tools and other photo stitchers

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng16.so:graphics/png \
		libtiff.so:graphics/tiff

USE_GNOME=	gtk20 glib20 pango atk

USES=		autoreconf jpeg libtool pathfix
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include/gtk-2.0 \
		-I${LOCALBASE}/include/glib-2.0 \
		-I${LOCALBASE}/include/pango-1.0 \
		-I${LOCALBASE}/include/atk-1.0
CONFIGURE_ARGS=	--with-png=${LOCALBASE} \
		--with-jpeg=${LOCALBASE} \
		--with-tiff=${LOCALBASE}
INSTALL_TARGET=	install-strip

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	JAVA
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJAVA}
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native
CONFIGURE_ARGS+=	--with-java=${JAVA_HOME}
.else
CONFIGURE_ARGS+=	--without-java
.endif

.include <bsd.port.mk>
