# Created by: Vasil Dimov <vd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libpano13
PORTVERSION=	2.9.18
PORTREVISION=	1
CATEGORIES=	graphics java
MASTER_SITES=	SF/panotools/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Cross-platform library behind Panorama Tools and other photo stitchers

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff

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

.if !defined(WITHOUT_JAVA)
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native
CONFIGURE_ARGS+=	--with-java=${JAVA_HOME}
PLIST_SUB=	JAVA=""
.else
CONFIGURE_ARGS+=	--without-java
PLIST_SUB=	JAVA="@comment "
.endif

pre-configure:
	cd ${WRKSRC} && ./bootstrap

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpano13.so.2

.include <bsd.port.mk>
