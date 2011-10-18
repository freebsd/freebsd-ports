# New ports collection makefile for:	libpano13
# Date created:				8 October 2007
# Whom:					Vasil Dimov <vd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libpano13
PORTVERSION=	2.9.18
CATEGORIES=	graphics java
MASTER_SITES=	SF/panotools/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Cross-platform library behind Panorama Tools and other photo stitchers

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff

USE_GNOME=	gtk20 glib20 pango atk

USE_AUTOTOOLS=	autoconf:env autoheader:env aclocal:env \
		automake:env libtool:env
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include/gtk-2.0 \
		-I${LOCALBASE}/include/glib-2.0 \
		-I${LOCALBASE}/include/pango-1.0 \
		-I${LOCALBASE}/include/atk-1.0
CONFIGURE_ARGS=	--with-png=${LOCALBASE} \
		--with-jpeg=${LOCALBASE} \
		--with-tiff=${LOCALBASE}

USE_LDCONFIG=	yes

MAN1=		\
		PTAInterpolate.1 \
		PTblender.1 \
		PTcrop.1 \
		PTinfo.1 \
		PTmasker.1 \
		PTmender.1 \
		PToptimizer.1 \
		PTroller.1 \
		PTtiff2psd.1 \
		PTtiffdump.1 \
		PTuncrop.1 \
		panoinfo.1

.if !defined(WITHOUT_JAVA)
USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_OS=	native
CONFIGURE_ARGS+=	--with-java=${JAVA_HOME}
PLIST_SUB=	JAVA=""
.else
CONFIGURE_ARGS+=	--without-java
PLIST_SUB=	JAVA="@comment "
.endif

pre-configure:
	cd ${WRKSRC} && ./bootstrap

.include <bsd.port.mk>
