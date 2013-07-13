# Created by: ijliao
# $FreeBSD$

PORTNAME=	texmaker
PORTVERSION=	4.0.2
PORTEPOCH=	2
CATEGORIES=	editors
MASTER_SITES=	http://www.xm1math.net/texmaker/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	LaTeX Development Environment

LIB_DEPENDS=	poppler:${PORTSDIR}/graphics/poppler \
		poppler-qt4:${PORTSDIR}/graphics/poppler-qt4
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

USE_BZIP2=	yes
USE_GHOSTSCRIPT=yes
USE_QT4=	gui network xml webkit \
		moc_build qmake_build rcc_build uic_build
USE_TEX=	latex dvipsk
HAS_CONFIGURE=	yes
QMAKE_ARGS=	PREFIX=${PREFIX} ICONDIR=${PREFIX}/share/pixmaps \
		DESKTOPDIR=${DESKTOPDIR}
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	GV XDVI
GV_DESC=	View ps files with gv
XDVI_DESC=	View dvi files with xdvi

STRIP_FILES=	bin/texmaker

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXDVI}
RUN_DEPENDS+=	xdvi:${PORTSDIR}/print/xdvik
.endif

.if ${PORT_OPTIONS:MGV}
RUN_DEPENDS+=	gv:${PORTSDIR}/print/gv
.endif

pre-configure:
	${REINPLACE_CMD} -e 's,/usr/include,${LOCALBASE}/include,g' \
		-e 's,/usr/lib,${LOCALBASE}/lib,g' \
		${WRKSRC}/texmaker.pro

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS} texmaker.pro

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${PREFIX}/,}

.include <bsd.port.mk>
