# New ports collection makefile for:	evas-loader-jpeg
# Date created:		15 September 2007
# Whom:			Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	loader-jpeg
PORTVERSION=	0.9.9.042
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/ \
		http://download.enlightenment.org/snapshots/2008-01-25/
PKGNAMEPREFIX=	evas-
DISTNAME=	evas-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A hardware accelerated canvas API (JPEG engine)

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		freetype.9:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_EFL=	evas

MAKEDIRS=	${WRKSRC}/src/modules/loaders/jpeg \
		${WRKSRC}/src/modules/savers/jpeg

CONFIGURE_ARGS=	--disable-software-x11 \
		--disable-software-16-x11 \
		--disable-software-xcb \
		--disable-directfb \
		--disable-sdl \
		--disable-buffer \
		--disable-software-qtopia \
		--disable-gl-x11 \
		--disable-cairo-x11 \
		--disable-xrender-x11 \
		--disable-xrender-xcb \
		--disable-glitz-x11 \
		--disable-image-loader-gif \
		--disable-image-loader-png \
		--enable-image-loader-jpeg \
		--disable-image-loader-eet \
		--disable-image-loader-edb \
		--disable-image-loader-tiff \
		--disable-image-loader-xpm \
		--disable-image-loader-svg

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's,\$$\(top_builddir\)/src/lib/\.libs,${LOCALBASE}/lib,' \
		-e 's,\$$\(top_builddir\)/src/lib/libevas\.la,-levas,' \
		${MAKEDIRS:S,$,/Makefile.in,}

do-build:
	@(for DIR in ${MAKEDIRS}; do cd $${DIR}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}; done)

do-install:
	@(for DIR in ${MAKEDIRS}; do cd $${DIR}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}; done)

.include <bsd.port.mk>
