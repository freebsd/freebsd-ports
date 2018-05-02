# $FreeBSD$

PORTNAME=	siril
DISTVERSION=	0.9.8
PORTREVISION=	2
CATEGORIES=	astro graphics
MASTER_SITES=	https://free-astro.org/download/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Astronomical image processing software

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN_i386=	undefined reference to `__atomic_load' and `__atomic_compare_exchange'

LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
		libcfitsio.so:astro/cfitsio \
		libconfig.so:devel/libconfig \
		libffms2.so:multimedia/ffms2 \
		libfftw3.so:math/fftw3 \
		libgsl.so:math/gsl \
		liblcms2.so:graphics/lcms2 \
		libopencv_core.so:graphics/opencv-core \
		libpng.so:graphics/png \
		libraw.so:graphics/libraw \
		libtiff.so:graphics/tiff
LIB_DEPENDS+=	libopencv_photo.so:graphics/opencv # for some reason, configure fails without opencv, but executable only links to opencv-core

USES=		autoreconf desktop-file-utils gettext gmake localbase pkgconfig jpeg shared-mime-info tar:bz2
GNU_CONFIGURE=	yes
USE_GNOME=	atk cairo gdkpixbuf2 gtk30 intltool pango
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=			OPENMP
OPTIONS_DEFAULT=		OPENMP

OPENMP_CONFIGURE_ENABLE=	openmp
OPENMP_LIB_DEPENDS=		libomp.so:devel/openmp

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/appdata ${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${WRKSRC}/platform-specific/linux/org.free-astro.siril.desktop ${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}.desktop
	${INSTALL_DATA} ${WRKSRC}/platform-specific/linux/org.free-astro.siril.appdata.xml ${STAGEDIR}${PREFIX}/share/appdata/${PORTNAME}.appdata.xml
	${INSTALL_DATA} ${WRKSRC}/platform-specific/linux/siril.xml ${STAGEDIR}${PREFIX}/share/mime/packages/
	cd ${WRKSRC}/pixmaps && ${COPYTREE_SHARE} icons ${STAGEDIR}${PREFIX}/share/

.include <bsd.port.mk>
