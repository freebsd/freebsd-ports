# Created by: cartola (Carlos E. G. Carvalho)
# $FreeBSD$

# This port has been made as a building and running dependence for the
# hugin port.
# The hugin port is a gui interface to interact with this and other
# tools.

PORTNAME=	libpano12
PORTVERSION=	2.8.6
PORTREVISION=	7
CATEGORIES=	graphics java
MASTER_SITES=	SF/panotools/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Panorama Tools to make panorama pictures

LIB_DEPENDS=	tiff:${PORTSDIR}/graphics/tiff \
		png15:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg

USE_GNOME=	gtk20 glib20 pango atk

USE_AUTOTOOLS=	autoconf:env autoheader:env aclocal:env \
		automake:env libtool:env
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include/gtk-2.0 \
		-I${LOCALBASE}/include/glib-2.0 \
		-I${LOCALBASE}/include/libpng15 \
		-I${LOCALBASE}/include/pango-1.0 \
		-I${LOCALBASE}/include/atk-1.0
CONFIGURE_ARGS=	--with-png=${LOCALBASE} \
		--with-jpeg=${LOCALBASE} \
		--with-tiff=${LOCALBASE}

USE_LDCONFIG=	yes

.if !defined(WITHOUT_JAVA)
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native
CONFIGURE_ARGS+=	--with-java=${JAVA_HOME}
.else
CONFIGURE_ARGS+=	--without-java
.endif

NO_STAGE=	yes
pre-configure:
	cd ${WRKSRC} && ./bootstrap

.include <bsd.port.mk>
