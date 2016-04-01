# Created by: ijliao
# $FreeBSD$

PORTNAME=	qfsm
PORTVERSION=	0.54.0
DISTVERSIONSUFFIX=	-Source
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical tool for designing finite state machines

LICENSE=	GPLv3+

OPTIONS_DEFINE=	GRAPHVIZ DOCS EXAMPLES

USE_XORG=	xi
USE_QT4=	corelib gui qt3support svg xml \
		moc_build qmake_build rcc_build uic_build
USES=		tar:bzip2 cmake desktop-file-utils
INSTALLS_ICONS=	yes

GRAPHVIZ_BUILD_DEPENDS=	graphviz>=2.22:graphics/graphviz
GRAPHVIZ_RUN_DEPENDS=	graphviz>=2.22:graphics/graphviz
GRAPHVIZ_CMAKE_OFF=	-DQFSM_AVOID_GRAPHVIZ:BOOL=ON

pre-configure:
	${REINPLACE_CMD} -e \
		'/\/usr\//d' ${WRKSRC}/FindGraphViz.cmake
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|'			\
		-e '/examples/s|share/qfsm|share/examples/${PORTNAME}|'	\
		${WRKSRC}/CMakeLists.txt
pre-configure-DOCS-on:
	${REINPLACE_CMD} -e 's|%%PD%%||' ${WRKSRC}/CMakeLists.txt
pre-configure-DOCS-off:
	${REINPLACE_CMD} -e 's|%%PD%%|#|' ${WRKSRC}/CMakeLists.txt
pre-configure-EXAMPLES-on:
	${REINPLACE_CMD} -e 's|%%PE%%||' ${WRKSRC}/CMakeLists.txt
pre-configure-EXAMPLES-off:
	${REINPLACE_CMD} -e 's|%%PE%%|#|' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
