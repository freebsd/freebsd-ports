# Created by: Michael Reifenberger <mr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openscad
PORTVERSION=	2021.02.09
PORTREVISION=	2
#PORTREVISION=	1
CATEGORIES=	cad
PKGNAMESUFFIX=	-devel

#PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
#PATCHFILES+=	b6c170cc5dd1.patch:-p1

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Programmer's solid 3D CAD modeller #'

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=  cgal>0:math/cgal
LIB_DEPENDS=	libzip.so:archivers/libzip \
		libhidapi.so:comms/hidapi \
		libboost_regex.so:devel/boost-libs \
		libqscintilla2_qt5.so:devel/qscintilla2-qt5 \
		libopencsg.so:graphics/opencsg \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libfontconfig.so:x11-fonts/fontconfig \
		libdouble-conversion.so:devel/double-conversion

CONFLICTS=	openscad

USES=		bison compiler:c++14-lang desktop-file-utils eigen:3 gettext \
		gl gnome pkgconfig qmake qt:5 shared-mime-info xorg
USE_GITHUB=	yes
USE_GL=		gl glu glew
USE_GNOME=	glib20 libxml2
USE_QT=		buildtools_build core concurrent_build dbus gui multimedia widgets
USE_XORG=	x11
GH_TAGNAME=	63a7c77740030c63d646eb0684ba6947eecb0db7
QMAKE_ARGS=	CONFIG+="experimental" VERSION=${PORTVERSION}
# Avoid overlinking: kvm, procstat, boost(thread, system), Qt5(concurrent, network, printsupport)
LDFLAGS+=	-Wl,--as-needed

post-patch:
	@${REINPLACE_CMD} 's/-libusb//' ${WRKSRC}/features/hidapi.prf
	@${REINPLACE_CMD} -e 's,share/man,man,' \
		${WRKSRC}/openscad.pro

.include <bsd.port.mk>
