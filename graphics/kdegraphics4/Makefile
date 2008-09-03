# New ports collection Makefile for:	kdegraphics
# Date created:				2008-01-31
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdegraphics
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Graphics utilities for the KDE4 integrated X11 desktop

BUILD_DEPENDS=	kpsewhich:${PORTSDIR}/print/teTeX-base
LIB_DEPENDS=	art_lgpl_2:${PORTSDIR}/graphics/libart_lgpl \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		freetype:${PORTSDIR}/print/freetype2 \
		fribidi:${PORTSDIR}/converters/fribidi \
		lcms:${PORTSDIR}/graphics/lcms \
		paper:${PORTSDIR}/print/libpaper \
		poppler-qt4:${PORTSDIR}/graphics/poppler-qt4 \
		exiv2.3:${PORTSDIR}/graphics/exiv2 \
		chm.0:${PORTSDIR}/misc/chmlib \
		sane.1:${PORTSDIR}/graphics/sane-backends \
		gphoto2.2:${PORTSDIR}/graphics/libgphoto2 \
		djvulibre:${PORTSDIR}/graphics/djvulibre-nox11 \
		qimageblitz.4:${PORTSDIR}/x11/qimageblitz \
		spectre.1:${PORTSDIR}/print/libspectre \
		qca.2:${PORTSDIR}/devel/qca \
		epub.0:${PORTSDIR}/textproc/ebook-tools

LATEST_LINK=	${PORTNAME}4

USE_GL=			glut
USE_GHOSTSCRIPT=	yes
USE_KDE4=	kdelibs workspace kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	opengl gui moc rcc uic svg iconengines pixeltool

post-extract:
	${MKDIR} ${WRKSRC}

post-patch:
	${FIND} ${WRKSRC}/.. -type f -name CMakeLists.txt | ${XARGS} \
		${REINPLACE_CMD} -e 's|pkgconfig|../libdata/pkgconfig|'

.include <bsd.port.mk>
