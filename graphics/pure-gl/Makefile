# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	pure-gl
PORTVERSION=	0.8
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	https://cdn.bitbucket.org/purelang/pure-lang/downloads/
DIST_SUBDIR=	pure

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pure language interface to OpenGL

LICENSE=	BSD3CLAUSE

BROKEN=		No public distfiles
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26

USES=		pure:ffi
USE_GL=		glut
MAKE_ARGS+=	LinkGL="-lglut -lGLU -lGL"
PORTDOCS=	README
PORTEXAMPLES=	*
OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pure/pure-gl.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
