# Created by: ijliao
# $FreeBSD$

PORTNAME=	texmaker
PORTVERSION=	4.3
PORTEPOCH=	2
CATEGORIES=	editors
MASTER_SITES=	http://www.xm1math.net/texmaker/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	LaTeX Development Environment

LIB_DEPENDS=	libpoppler.so:${PORTSDIR}/graphics/poppler

USES=		desktop-file-utils pkgconfig qmake tar:bzip2
USE_GHOSTSCRIPT_RUN=	yes
_USE_QT4=	gui network xml webkit \
		moc_build rcc_build uic_build
_USE_QT5=	concurrent network printsupport script webkit widgets \
		xml buildtools_build
USE_TEX=	latex dvipsk
QMAKE_ARGS=	ICONDIR=${PREFIX}/share/pixmaps \
		DESKTOPDIR=${DESKTOPDIR}

OPTIONS_DEFINE=	GV XDVI
OPTIONS_SINGLE=	TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	QT4 QT5
OPTIONS_DEFAULT=	QT5

TOOLKIT_DESC=	Qt toolkit
QT4_USE=	${_USE_QT4:S/^/QT4=/}
QT4_LIB_DEPENDS=	libpoppler-qt4.so:${PORTSDIR}/graphics/poppler-qt4
QT5_USE=	${_USE_QT5:S/^/QT5=/}
QT5_LIB_DEPENDS=	libpoppler-qt5.so:${PORTSDIR}/graphics/poppler-qt5

GV_DESC=	View ps files with gv
GV_RUN_DEPENDS=	gv:${PORTSDIR}/print/gv

XDVI_DESC=	View dvi files with xdvi
XDVI_RUN_DEPENDS=	xdvi:${PORTSDIR}/print/xdvik

.include <bsd.port.mk>
