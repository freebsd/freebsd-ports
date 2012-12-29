# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	converseen
PORTVERSION=	0.5.1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/Converseen/Converseen%200.5/${PORTVERSION}

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Easy to use graphics conversion utility

LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		pcre:${PORTSDIR}/devel/pcre \
		Magick++:${PORTSDIR}/graphics/ImageMagick \
		lcms2:${PORTSDIR}/graphics/lcms2 \
		lqr-1:${PORTSDIR}/graphics/liblqr-1 \
		png15:${PORTSDIR}/graphics/png \
		fftw3:${PORTSDIR}/math/fftw3 \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		xcb:${PORTSDIR}/x11/libxcb \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig

USE_BZIP2=	yes
USE_AUTOTOOLS=	libltdl
USE_CMAKE=	yes
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_XORG=	ice sm x11 xau xdmcp xext xrender xt
USE_QT4=	corelib gui linguist_build moc_build qmake_build \
		rcc_build uic_build
USE_GNOME=	glib20
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
