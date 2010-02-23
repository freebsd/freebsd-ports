# ex:ts=8
# Ports collection makefile for:	ulex
# Date created:			Mar 17, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ulex
PORTVERSION=	1.1
CATEGORIES=	devel
MASTER_SITES=	http://www.cduce.org/download/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	johans@FreeBSD.org
COMMENT=	A lexer generator for Unicode and OCaml

USE_OCAML=	true
USE_OCAML_FINDLIB=	true
USE_OCAML_LDCONFIG=	true
OCAMLC_DEPEND=	ocaml>=3.10:${OCAMLC_PORT}

ALL_TARGET=	all all.opt

USE_GMAKE=	yes

.if !defined(NOPORTDOCS)
ALL_TARGET+=	doc
PORTDOCS=	*
.endif

PKGDEINSTALL=	${PKGINSTALL}

post-install:
	@${FIND} ${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME} -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${WRKSRC}/*.css ${DOCSDIR}
.endif

.include <bsd.port.mk>
