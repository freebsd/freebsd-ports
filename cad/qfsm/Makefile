# Created by: ijliao
# $FreeBSD$

PORTNAME=	qfsm
PORTVERSION=	0.53.0
DISTVERSIONSUFFIX=	-Source
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical tool for designing finite state machines

LICENSE=	GPLv3 # (or later)

OPTIONS_DEFINE=	GRAPHVIZ DOCS EXAMPLES

USE_BZIP2=	yes
USE_XORG=	xi
USE_QT4=	corelib gui qt3support svg xml \
		moc_build qmake_build rcc_build uic_build
USES=		cmake desktop-file-utils
INSTALLS_ICONS=	yes

GRAPHVIZ_BUILD_DEPENDS=	graphviz>=2.22:${PORTSDIR}/graphics/graphviz
GRAPHVIZ_RUN_DEPENDS=	graphviz>=2.22:${PORTSDIR}/graphics/graphviz
GRAPHVIZ_CMAKE_OFF=	-DQFSM_AVOID_GRAPHVIZ:BOOL=ON

post-patch:
	@${REINPLACE_CMD} -e \
		'/\/usr\//d' ${WRKSRC}/FindGraphViz.cmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qfsm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/desktop/qfsm.desktop \
		${STAGEDIR}${PREFIX}/share/applications
.for i in 32x32 48x48 64x64
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}/apps
	${INSTALL_DATA} ${WRKSRC}/desktop/${i}/apps/qfsm.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}/apps
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}/mimetypes
	${INSTALL_DATA} ${WRKSRC}/desktop/${i}/mimetypes/x-qfsm.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}/mimetypes
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mimelnk/application
	${INSTALL_DATA} ${WRKSRC}/desktop/x-qfsm.desktop \
		${STAGEDIR}${PREFIX}/share/mimelnk/application
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/po/*.qm ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/user && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
