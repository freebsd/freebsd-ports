# New ports collection makefile for:    lablgl
# Date created:         13. January 2002
# Whom:                 Ronald Kuehn <rk@ronald.org>
#
# $FreeBSD$
#

PORTNAME=	lablgl
PORTVERSION=	0.99
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/dist/ \
		ftp://ftp.inria.fr/lang/caml-light/bazar-ocaml/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	rk@ronald.org
COMMENT=	OpenGL interface for Objective Caml

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml
RUN_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml

USE_MESA=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/lablGL-${PORTVERSION}
ALL_TARGET=	all opt
EXAMPLESDIR=	${PREFIX}/share/examples/ocaml/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Does not compile"
.endif

post-extract:
	@${CP} ${WRKSRC}/Makefile.config.ex ${WRKSRC}/Makefile.config

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.if !defined(NO_PORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
