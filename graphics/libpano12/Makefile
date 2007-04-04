# New ports collection makefile for:   panorama-tools
# Date created:        26 august 2004
# Whom:                cartola (Carlos E. G. Carvalho)
#
# $FreeBSD$
# This port has been made as a building and running dependence for the
# hugin port.
# The hugin port is a gui interface to interact with this and other
# tools.

PORTNAME=	libpano12
PORTVERSION=	2.8.4
CATEGORIES=	graphics java
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	panotools

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Panorama Tools to make panorama pictures

BUILD_DEPENDS=	gimp>0:${PORTSDIR}/graphics/gimp
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	tiff:${PORTSDIR}/graphics/tiff \
		png:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		cairo:${PORTSDIR}/graphics/cairo

USE_GNOME=	gtk20 glib20 pango atk

USE_AUTOTOOLS=	autoconf:259:env autoheader:259:env aclocal:19:env \
		automake:19:env libtool:15:env
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/gtk-2.0 \
			-I${LOCALBASE}/include/gimp-2.0 \
			-I${LOCALBASE}/include/glib-2.0 \
			-I${LOCALBASE}/include/cairo \
			-I${LOCALBASE}/include/pango-1.0 \
			-I${LOCALBASE}/include/atk-1.0"

USE_LDCONFIG=	yes

.if !defined(WITHOUT_JAVA)
USE_JAVA=	yes
JAVA_VERSION=	1.3+
JAVA_OS=	native
CONFIGURE_ARGS+=	--with-java=${JAVA_HOME}
.else
CONFIGURE_ARGS+=	--without-java
.endif

pre-configure:
	cd ${WRKSRC} && \
	${SETENV} ${AUTOTOOLS_ENV} \
	ACLOCAL="${ACLOCAL} -I ${LOCALBASE}/share/aclocal" \
	./bootstrap

.include <bsd.port.mk>
