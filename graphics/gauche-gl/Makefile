PORTNAME=	gl
PORTVERSION=	0.6
PORTREVISION=	5
CATEGORIES=	graphics scheme
MASTER_SITES=	SF/gauche/Gauche-gl
PKGNAMEPREFIX=	gauche-
DISTNAME=	Gauche-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL binding for Gauche
WWW=		https://practical-scheme.net/gauche/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gosh:lang/gauche
RUN_DEPENDS=	gosh:lang/gauche

USES=		gl localbase tar:tgz xorg
USE_CSTD=	gnu99
USE_GL=		gl glu glut
USE_XORG=	ice sm x11 xext xmu xi

GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=	yes

DOCSDIR=	${PREFIX}/share/doc/gauche/${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/gauche/${PORTNAME}

PLIST_SUB=	TARGET="${CONFIGURE_TARGET}" ABI_VER=${GAUCHE_ABI}

OPTIONS_DEFINE=	DOCS EXAMPLES INFO
OPTIONS_DEFAULT=	INFO

INFO_USES=	makeinfo
INFO_INFO=		gauche-gl-refe gauche-gl-refj

GAUCHE_ABI=	0.98

post-patch:
.for i in configure src/gauche-gl.h src/glut-lib.stub
	@${REINPLACE_CMD} -e '/glut.h/s|GLUT|GL|' ${WRKSRC}/${i}
.endfor

do-install:
.for i in src lib
	@(cd ${WRKSRC}/${i} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endfor
	@(cd ${STAGEDIR}${PREFIX}/lib/gauche-${GAUCHE_ABI}/site/${CONFIGURE_TARGET} && \
		${CHMOD} u+w libgauche-*.so && ${STRIP_CMD} libgauche-*.so && \
		${CHMOD} u-w libgauche-*.so)

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
