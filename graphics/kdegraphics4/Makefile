# New ports collection Makefile for:	kdegraphics
# Date created:				2008-01-31
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdegraphics
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Graphics utilities for the KDE4 integrated X11 desktop

BUILD_DEPENDS=	kpsewhich:${PORTSDIR}/print/teTeX-base
LIB_DEPENDS=	art_lgpl_2.5:${PORTSDIR}/graphics/libart_lgpl \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		freetype.9:${PORTSDIR}/print/freetype2 \
		fribidi.0:${PORTSDIR}/converters/fribidi \
		lcms.1:${PORTSDIR}/graphics/lcms \
		paper.2:${PORTSDIR}/print/libpaper \
		poppler-qt4.3:${PORTSDIR}/graphics/poppler-qt4 \
		exiv2.7:${PORTSDIR}/graphics/exiv2 \
		chm.0:${PORTSDIR}/misc/chmlib \
		sane.1:${PORTSDIR}/graphics/sane-backends \
		gphoto2.2:${PORTSDIR}/graphics/libgphoto2 \
		djvulibre.21:${PORTSDIR}/graphics/djvulibre-nox11 \
		qimageblitz.4:${PORTSDIR}/x11/qimageblitz \
		spectre.1:${PORTSDIR}/print/libspectre \
		qca.2:${PORTSDIR}/devel/qca \
		epub.0:${PORTSDIR}/textproc/ebook-tools

LATEST_LINK=	${PORTNAME}4

USE_GL=			glut
USE_GHOSTSCRIPT=	yes
USE_KDE4=	kdelibs kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	opengl gui svg iconengines pixeltool \
		moc_build rcc_build uic_build qmake_build
MAKE_JOBS_UNSAFE=	yes

post-extract:
	${MKDIR} ${WRKSRC}

post-patch:
	${FIND} ${WRKSRC}/.. -type f -name CMakeLists.txt | ${XARGS} \
		${REINPLACE_CMD} -e 's|pkgconfig|../libdata/pkgconfig|'

.include <bsd.port.mk>
