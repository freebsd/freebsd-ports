# Created by: Tim Cas <ports@stdrand.com>
# $FreeBSD$

PORTNAME=	ChipmunkPhysics
PORTVERSION=	7.0.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://chipmunk-physics.net/release/Chipmunk-7.x/ \
		http://files.slembcke.net/chipmunk/release/Chipmunk-7.x/ \
		http://files.libsiege.org/chipmunk/
DISTNAME=	Chipmunk-${PORTVERSION}

MAINTAINER=	ports@stdrand.com
COMMENT=	2D physics engine written in C

LICENSE=	MIT

USES=		cmake tar:tgz
USE_LDCONFIG=	yes
PLIST_SUB=	VERSION=${PORTVERSION}

OPTIONS_DEFINE=	DOCS EXAMPLES DEMOS
OPTIONS_SUB=	yes

PORTDOCS=	*
PORTEXAMPLES=	*.c *.h

DEMOS_DESC=	Install the demo program (requires GLFW and GLEW)
DEMOS_USE=		GL=glew
DEMOS_LIB_DEPENDS=	libglfw.so:${PORTSDIR}/graphics/glfw2
DEMOS_CMAKE_OFF=	-DBUILD_DEMOS=OFF

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "README.textile VERSION.txt" ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/demo && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} "-name *\.c -or -name *\.h")
.endif

.if ${PORT_OPTIONS:MDEMOS}
	${INSTALL_PROGRAM} ${WRKSRC}/demo/chipmunk_demos ${STAGEDIR}${PREFIX}/bin
.endif

.include <bsd.port.mk>
