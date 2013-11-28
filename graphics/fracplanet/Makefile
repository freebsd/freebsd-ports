# Created by: Igor Pokrovsky <ip@doom.homeunix.org>
# $FreeBSD$

PORTNAME=	fracplanet
PORTVERSION=	0.4.0
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons.tar.gz:icons

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Interactive tool for creating random fractal planets and terrain

LICENSE=	GPLv2

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	libboost_program_options.so:${PORTSDIR}/devel/boost-libs

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake
USE_GL=		glu
USE_QT4=	corelib moc_build qmake_build gui opengl
QT_NONSTANDARD=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	QTDIR="${QT_PREFIX}"
CONFIGURE_ARGS=	-spec ${QMAKESPEC}

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	 BUGS NEWS README THANKS TODO ${PORTNAME}.css ${PORTNAME}.htm

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96

DESKTOP_ENTRIES="Fracplanet" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Graphics;" false

OPTIONS_DEFINE=	DOCS
OPTIONS_GROUP=	DOXYGEN
OPTIONS_GROUP_DOXYGEN=	HTML LATEX

OPTIONS_DEFAULT=	HTML

HTML_DESC=	Install HTML Doxygen files
LATEX_DESC=	Install LaTeX Doxygen files

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHTML} || ${PORT_OPTIONS:MLATEX}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
.endif

post-patch:
.for f in BUILD VERSION configure
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|g' \
		${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -e 's|qmake-qt4|${QMAKE} ${QMAKE_ARGS}|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-lboost_program_options|-lboost_program_options -lGLU|' \
		${WRKSRC}/fracplanet.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/man1/fracplanet.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MHTML} || ${PORT_OPTIONS:MLATEX}
	@cd ${WRKSRC} && doxygen .
.endif

.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MHTML}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MLATEX}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} latex ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
