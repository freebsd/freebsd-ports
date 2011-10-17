# New ports collection makefile for:	okular
# Date created:				1 September 2011
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	okular
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 universal document viewer

LIB_DEPENDS=	qimageblitz.4:${PORTSDIR}/x11/qimageblitz \
		djvulibre.24:${PORTSDIR}/graphics/djvulibre-nox11 \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		qca.2:${PORTSDIR}/devel/qca \
		tiff.4:${PORTSDIR}/graphics/tiff \
		poppler-qt4.3:${PORTSDIR}/graphics/poppler-qt4 \
		spectre.1:${PORTSDIR}/print/libspectre \
		chm.0:${PORTSDIR}/misc/chmlib \
		freetype.9:${PORTSDIR}/print/freetype2 \
		epub.0:${PORTSDIR}/textproc/ebook-tools

CONFLICTS=	kdegraphics-4.[0-6].*

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui xml qmake_build moc_build uic_build rcc_build
USE_BZIP2=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS=	DVI "Support DVI files (requires teTeX)" off

.include <bsd.port.options.mk>

.ifdef(WITH_DVI)
RUN_DEPENDS+=	kpsewhich:${PORTSDIR}/print/teTeX-base
.endif

.include <bsd.port.mk>
