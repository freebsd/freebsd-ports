# New ports collection makefile for:    lablgl
# Date created:         13. January 2002
# Whom:                 Ronald Kuehn <rk@ronald.org>
#
# $FreeBSD$
#

PORTNAME=	lablgl
PORTVERSION=	1.00
CATEGORIES=	graphics
MASTER_SITES=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/dist/ \
		ftp://ftp.inria.fr/lang/caml-light/bazar-ocaml/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	rk@ronald.org
COMMENT=	OpenGL interface for Objective Caml

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml
LIB_DEPENDS=	glut.3:${PORTSDIR}/graphics/libglut
RUN_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml

USE_GL=		yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/lablgl-${PORTVERSION}
ALL_TARGET=	all opt
#EXAMPLESDIR=	${PREFIX}/share/examples/ocaml/${PORTNAME}
#DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}

post-extract:
	@${CP} ${WRKSRC}/Makefile.config.freebsd ${WRKSRC}/Makefile.config

post-install:
	${MKDIR} ${EXAMPLESDIR}/LablGlut/caml-images \
	    ${EXAMPLESDIR}/LablGlut/etc \
	    ${EXAMPLESDIR}/LablGlut/etc/in-progress \
	    ${EXAMPLESDIR}/LablGlut/lablGL \
	    ${EXAMPLESDIR}/LablGlut/nehe \
	    ${EXAMPLESDIR}/Togl
	${INSTALL_DATA} ${WRKSRC}/LablGlut/examples/README \
	    ${EXAMPLESDIR}/LablGlut
	${INSTALL_DATA} ${WRKSRC}/LablGlut/examples/caml-images/* \
	    ${EXAMPLESDIR}/LablGlut/caml-images
	${INSTALL_DATA} ${WRKSRC}/LablGlut/examples/etc/d* \
	    ${EXAMPLESDIR}/LablGlut/etc
	${INSTALL_DATA} ${WRKSRC}/LablGlut/examples/etc/in-progress/* \
	    ${EXAMPLESDIR}/LablGlut/etc/in-progress
	${INSTALL_DATA} ${WRKSRC}/LablGlut/examples/lablGL/* \
	    ${EXAMPLESDIR}/LablGlut/lablGL
	${INSTALL_DATA} ${WRKSRC}/LablGlut/examples/nehe/* \
	    ${EXAMPLESDIR}/LablGlut/nehe
	${INSTALL_DATA} ${WRKSRC}/Togl/examples/* \
	    ${EXAMPLESDIR}/Togl
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
