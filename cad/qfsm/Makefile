# Created by: ijliao
# $FreeBSD$

PORTNAME=	qfsm
PORTVERSION=	0.53.0
DISTVERSIONSUFFIX=	-Source
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical tool for designing finite state machines

LICENSE=	GPLv3 # (or later)

OPTIONS_DEFINE=	GRAPHVIZ DOCS EXAMPLES

USE_BZIP2=	yes
USE_XORG=	xi
USE_QT4=	corelib gui qt3support svg xml \
		moc_build qmake_build rcc_build uic_build
USE_GNOME=	desktopfileutils
USES=		cmake
INSTALLS_ICONS=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGRAPHVIZ}
BULID_DEPENDS+=	graphviz>=2.22:${PORTSDIR}/graphics/graphviz
RUN_DEPENDS+=	graphviz>=2.22:${PORTSDIR}/graphics/graphviz
.else
CMAKE_ARGS+=	-DQFSM_AVOID_GRAPHVIZ:BOOL=ON
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/\/usr\//d' ${WRKSRC}/FindGraphViz.cmake

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} qfsm ${PREFIX}/bin)
	(cd ${WRKSRC}/desktop && ${INSTALL_DATA} qfsm.desktop \
		${PREFIX}/share/applications)
.for i in 32x32 48x48 64x64
	@${MKDIR} ${PREFIX}/share/icons/hicolor/${i}/apps
	(cd ${WRKSRC}/desktop/${i}/apps && ${INSTALL_DATA} qfsm.png \
		${PREFIX}/share/icons/hicolor/${i}/apps)
	@${MKDIR} ${PREFIX}/share/icons/hicolor/${i}/mimetypes
	(cd ${WRKSRC}/desktop/${i}/mimetypes && ${INSTALL_DATA} x-qfsm.png \
		${PREFIX}/share/icons/hicolor/${i}/mimetypes)
.endfor
	@${MKDIR} ${PREFIX}/share/mimelnk/application
	(cd ${WRKSRC}/desktop && ${INSTALL_DATA} x-qfsm.desktop \
		${PREFIX}/share/mimelnk/application)
	@${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/po && ${INSTALL_DATA} *.qm ${DATADIR})
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc/user && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif
	@-update-desktop-database

.include <bsd.port.mk>
