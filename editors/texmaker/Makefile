# Created by: ijliao
# $FreeBSD$

PORTNAME=	texmaker
PORTVERSION=	4.1
PORTEPOCH=	2
CATEGORIES=	editors
MASTER_SITES=	http://www.xm1math.net/texmaker/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	LaTeX Development Environment

LIB_DEPENDS=	libpoppler.so:${PORTSDIR}/graphics/poppler \
		libpoppler-qt4.so:${PORTSDIR}/graphics/poppler-qt4

USES=		desktop-file-utils pkgconfig qmake
USE_BZIP2=	yes
USE_GHOSTSCRIPT_RUN=	yes
USE_QT4=	gui network xml webkit \
		moc_build qmake_build rcc_build uic_build
USE_TEX=	latex dvipsk
QMAKE_ARGS=	ICONDIR=${PREFIX}/share/pixmaps \
		DESKTOPDIR=${DESKTOPDIR}

OPTIONS_DEFINE=	GV XDVI

GV_DESC=	View ps files with gv
GV_RUN_DEPENDS+=	gv:${PORTSDIR}/print/gv

XDVI_DESC=	View dvi files with xdvi
XDVI_RUN_DEPENDS+=	xdvi:${PORTSDIR}/print/xdvik

STRIP_FILES=	bin/texmaker

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${STAGEDIR}${PREFIX}/,}

.include <bsd.port.mk>
