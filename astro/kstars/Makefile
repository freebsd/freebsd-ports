# $FreeBSD$

PORTNAME=	kstars
DISTVERSION=	2.8.9
PORTEPOCH=	1
CATEGORIES=	astro kde
MASTER_SITES=	KDE/stable/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE desktop planetarium

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcfitsio.so:astro/cfitsio \
		libwcs.so:astro/wcslib
BUILD_DEPENDS=	xplanet:astro/xplanet
RUN_DEPENDS=	xplanet:astro/xplanet

USES=		cmake:outsource compiler:c++11-lib eigen:3 gettext kde:5 \
		pkgconfig tar:xz
USE_KDE=	config dbusaddons doctools ecm guiaddons i18n iconthemes init \
		jobwidgets kio newstuff notifications parts plotting \
		texteditor widgetsaddons xmlgui
USE_QT5=	buildtools_build core gui multimedia network opengl \
		printsupport qmake_build qml quick sql svg testlib widgets \
		xml

post-patch:
# climits defines ULLONG_MAX and LLONG_MAX
	${REINPLACE_CMD} -e 's#ULONG_LONG_MAX#ULLONG_MAX#g' \
			 -e 's#LONG_LONG_MAX#LLONG_MAX#g' \
		${WRKSRC}/kstars/fitsviewer/fitsdata.cpp

.include <bsd.port.mk>
