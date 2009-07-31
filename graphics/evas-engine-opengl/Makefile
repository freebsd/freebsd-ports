# New ports collection makefile for:	evas-engine-opengl
# Date created:		15 September 2007
# Whom:			Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	engine-opengl
PORTVERSION=	0.9.9.042
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/ \
		http://download.enlightenment.org/snapshots/2008-01-25/
PKGNAMEPREFIX=	evas-
DISTNAME=	evas-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A hardware accelerated canvas API (OpenGL engine)

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_EFL=	evas
USE_XORG=	x11 xext
USE_GL=		gl glu
BUILD_WRKSRC=	${WRKSRC}/src/modules/engines/gl_x11
INSTALL_WRKSRC=	${BUILD_WRKSRC}

CONFIGURE_ARGS=	--disable-software-x11 \
		--disable-software-16-x11 \
		--disable-software-xcb \
		--disable-directfb \
		--disable-sdl \
		--disable-buffer \
		--disable-software-qtopia \
		--enable-gl-x11 \
		--disable-cairo-x11 \
		--disable-xrender-x11 \
		--disable-xrender-xcb \
		--disable-glitz-x11 \
		--disable-image-loader-gif \
		--disable-image-loader-png \
		--disable-image-loader-jpeg \
		--disable-image-loader-eet \
		--disable-image-loader-edb \
		--disable-image-loader-tiff \
		--disable-image-loader-xpm \
		--disable-image-loader-svg

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's,\$$\(top_builddir\)/src/lib/\.libs,${LOCALBASE}/lib,' \
		-e 's,\$$\(top_builddir\)/src/lib/libevas\.la,-levas,' \
		${BUILD_WRKSRC}/Makefile.in \
		${WRKSRC}/src/modules/engines/gl_common/Makefile.in

pre-build:
	@(cd ${WRKSRC}/src/modules/engines/gl_common; ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

post-install:
	${INSTALL_DATA} ${WRKSRC}/evas-opengl-x11.pc \
		${PREFIX}/libdata/pkgconfig/

.include <bsd.port.mk>
