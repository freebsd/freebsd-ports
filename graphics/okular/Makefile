# $FreeBSD$

PORTNAME=	okular
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 universal document viewer

LIB_DEPENDS=	djvulibre:${PORTSDIR}/graphics/djvulibre \
		jpeg:${PORTSDIR}/graphics/jpeg \
		qca:${PORTSDIR}/devel/qca \
		tiff:${PORTSDIR}/graphics/tiff \
		poppler-qt4:${PORTSDIR}/graphics/poppler-qt4 \
		spectre:${PORTSDIR}/print/libspectre \
		chm:${PORTSDIR}/misc/chmlib \
		freetype:${PORTSDIR}/print/freetype2 \
		epub:${PORTSDIR}/textproc/ebook-tools

CONFLICTS=	kdegraphics-4.[0-6].*

USE_KDE4=	kdehier kdelibs kdeprefix automoc4 qimageblitz kactivities
USES=		cmake:outsource
USE_QT4=	corelib declarative gui opengl xml \
		qmake_build moc_build uic_build rcc_build
USE_XZ=		yes
USE_LDCONFIG=	yes

MAN1=		okular.1

OPTIONS_DEFINE=	DVI
DVI_DESC=	Support DVI files (requires teTeX)

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDVI}
USE_TEX=	latex
.endif

.include <bsd.port.mk>
