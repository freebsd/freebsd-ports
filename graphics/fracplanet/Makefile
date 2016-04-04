# Created by: Igor Pokrovsky <ip@doom.homeunix.org>
# $FreeBSD$

PORTNAME=	fracplanet
PORTVERSION=	0.4.0
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	SF \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons.tar.gz:icons

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive tool for creating random fractal planets and terrain

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	xsltproc:textproc/libxslt
LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake
USE_GL=		glu
USE_QT4=	corelib moc_build qmake_build gui opengl
QT_NONSTANDARD=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	QTDIR="${QT_PREFIX}"
CONFIGURE_ARGS=	-spec ${QMAKESPEC}

CXXFLAGS+=	-include ${WRKSRC}/precompiled.h

PORTDOCS=	*

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96

DESKTOP_ENTRIES="Fracplanet" "" "${PORTNAME}" \
		"${PORTNAME}" "Graphics;" ""

OPTIONS_DEFINE=	DOXYGEN DOCS

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MDOXYGEN}
BUILD_DEPENDS+=	doxygen:devel/doxygen
.endif

post-patch:
.for f in BUILD VERSION configure
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|g' \
		${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -e 's|qmake-qt4|${QMAKE} ${QMAKE_ARGS}|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|-lboost_program_options|-lboost_program_options -lGLU|' \
		${WRKSRC}/fracplanet.pro

.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MDOXYGEN}
post-build:
	cd ${WRKSRC} && doxygen .
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/man1/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/

.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} BUGS NEWS README THANKS \
		fracplanet.css fracplanet.htm ${STAGEDIR}${DOCSDIR}
. if ${PORT_OPTIONS:MDOXYGEN}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "html latex" ${STAGEDIR}${DOCSDIR})
. endif
.endif

.include <bsd.port.post.mk>
