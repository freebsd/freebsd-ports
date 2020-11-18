# $FreeBSD$

PORTNAME=	art
PORTVERSION=	1.5.4.20201118
CATEGORIES=	graphics
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/
PKGNAMESUFFIX=	-raw-image-editor

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Raw image processing program

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libexiv2.so:graphics/exiv2 \
		libexpat.so:textproc/expat2 \
		libfftw3f.so:math/fftw3-float \
		liblensfun.so:graphics/lensfun \
		liblcms2.so:graphics/lcms2 \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		cmake compiler:c++11-lang desktop-file-utils gnome jpeg pkgconfig xorg
USE_GNOME=	atk atkmm cairo cairomm glibmm gtkmm30 librsvg2
USE_XORG=	x11

INSTALLS_ICONS=	yes

BB_ACCOUNT=	agriggio
BB_PROJECT=	art
BB_COMMIT=	b2d77c8f0080

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share/doc/ART

.include <bsd.port.mk>
