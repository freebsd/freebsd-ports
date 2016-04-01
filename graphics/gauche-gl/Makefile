# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	gl
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	graphics scheme
MASTER_SITES=	SF/gauche/Gauche-gl
PKGNAMEPREFIX=	gauche-
DISTNAME=	Gauche-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL binding for Gauche

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gosh:lang/gauche
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		makeinfo tar:tgz
USE_XORG=	ice sm x11 xext xmu xi
USE_GL=		glut
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DOCSDIR=	${PREFIX}/share/doc/gauche/${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/gauche/${PORTNAME}

PLIST_SUB=	TARGET="${CONFIGURE_TARGET}"

INFO=		gauche-gl-refe gauche-gl-refj

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
.for i in configure src/gauche-gl.c src/gauche-gl.h src/glut-lib.stub
	@${REINPLACE_CMD} -e '/glut.h/s|GLUT|GL|' ${WRKSRC}/${i}
.endfor

do-install:
.for i in src lib
	@(cd ${WRKSRC}/${i} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endfor
.for i in ${INFO}
	${GZCAT} ${WRKSRC}/doc/${i}.info.gz \
		> ${STAGEDIR}${PREFIX}/${INFO_PATH}/${i}.info
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README \
		${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR})
	@(cd ${STAGEDIR}${PREFIX}/lib/gauche-0.9/site/${CONFIGURE_TARGET} && \
		${CHMOD} u+w libgauche-*.so && ${STRIP_CMD} libgauche-*.so && \
		${CHMOD} u-w libgauche-*.so)

.include <bsd.port.mk>
