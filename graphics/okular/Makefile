# $FreeBSD$

PORTNAME=	okular
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 universal document viewer

LIB_DEPENDS=	djvulibre:${PORTSDIR}/graphics/djvulibre \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		qca.2:${PORTSDIR}/devel/qca \
		tiff.4:${PORTSDIR}/graphics/tiff \
		poppler-qt4.3:${PORTSDIR}/graphics/poppler-qt4 \
		spectre.1:${PORTSDIR}/print/libspectre \
		chm.0:${PORTSDIR}/misc/chmlib \
		freetype.9:${PORTSDIR}/print/freetype2 \
		epub.0:${PORTSDIR}/textproc/ebook-tools

CONFLICTS=	kdegraphics-4.[0-6].*

USE_KDE4=	kdehier kdelibs kdeprefix automoc4 qimageblitz
KDE4_BUILDENV=	yes
USE_QT4=	gui xml qmake_build moc_build uic_build rcc_build
USE_XZ=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	DVI
DVI_DESC=	Support DVI files (requires teTeX)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDVI}
RUN_DEPENDS+=	kpsewhich:${PORTSDIR}/print/teTeX-base
.endif

.include <bsd.port.mk>
