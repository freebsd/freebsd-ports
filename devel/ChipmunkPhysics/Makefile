# Created by: Tim Cas <ports@stdrand.com>
# $FreeBSD$

PORTNAME=	ChipmunkPhysics
PORTVERSION=	6.2.1
CATEGORIES=	devel
MASTER_SITES=	http://chipmunk-physics.net/release/Chipmunk-6.x/ \
		http://files.slembcke.net/chipmunk/release/Chipmunk-6.x/ \
		http://files.libsiege.org/chipmunk/
DISTNAME=	Chipmunk-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@stdrand.com
COMMENT=	2D physics engine written in C

LICENSE=	MIT

USES=		cmake
USE_LDCONFIG=	yes
PLIST_SUB=	VERSION=${PORTVERSION}

OPTIONS_DEFINE=	DOCS EXAMPLES DEMOS
DEMOS_DESC=	Install the demo program (requires GLFW and GLEW)

PORTDOCS=	*
PORTEXAMPLES=	*.c *.h

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEMOS}
USE_GL=		glew
LIB_DEPENDS+=	libglfw.so:${PORTSDIR}/graphics/glfw
PLIST_SUB+=	DEMOS=""
.else
CMAKE_ARGS=	-DBUILD_DEMOS=OFF
PLIST_SUB+=	DEMOS="@comment "
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "README.textile VERSION.txt" ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/Demo && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} "-name *\.c -or -name *\.h")
.endif

.if ${PORT_OPTIONS:MDEMOS}
	${INSTALL_PROGRAM} ${WRKSRC}/Demo/chipmunk_demos ${STAGEDIR}${PREFIX}/bin
.endif

.include <bsd.port.mk>
