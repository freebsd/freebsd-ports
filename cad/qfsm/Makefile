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

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

OPTIONS_DEFINE=	GRAPHVIZ DOCS EXAMPLES

USES=		qt:4 tar:bzip2 cmake desktop-file-utils
USE_XORG=	xi
USE_QT=		corelib gui qt3support svg xml \
		moc_build qmake_build rcc_build uic_build
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
