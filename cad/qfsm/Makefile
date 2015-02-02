# Created by: ijliao
# $FreeBSD$

PORTNAME=	qfsm
PORTVERSION=	0.54.0
DISTVERSIONSUFFIX=	-Source
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical tool for designing finite state machines

LICENSE=	GPLv3 # (or later)

OPTIONS_DEFINE=	GRAPHVIZ DOCS EXAMPLES

USE_XORG=	xi
USE_QT4=	corelib gui qt3support svg xml \
		moc_build qmake_build rcc_build uic_build
USES=		tar:bzip2 cmake desktop-file-utils
INSTALLS_ICONS=	yes

GRAPHVIZ_BUILD_DEPENDS=	graphviz>=2.22:${PORTSDIR}/graphics/graphviz
GRAPHVIZ_RUN_DEPENDS=	graphviz>=2.22:${PORTSDIR}/graphics/graphviz
GRAPHVIZ_CMAKE_OFF=	-DQFSM_AVOID_GRAPHVIZ:BOOL=ON

.include <bsd.port.options.mk>

pre-configure:
	${REINPLACE_CMD} -e \
		'/\/usr\//d' ${WRKSRC}/FindGraphViz.cmake
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|'			\
		-e '/examples/s|share/qfsm|share/examples/${PORTNAME}|'	\
		${WRKSRC}/CMakeLists.txt
.if ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e 's|%%PD%%||' ${WRKSRC}/CMakeLists.txt
.else
	${REINPLACE_CMD} -e 's|%%PD%%|#|' ${WRKSRC}/CMakeLists.txt
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${REINPLACE_CMD} -e 's|%%PE%%||' ${WRKSRC}/CMakeLists.txt
.else
	${REINPLACE_CMD} -e 's|%%PE%%|#|' ${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.mk>
