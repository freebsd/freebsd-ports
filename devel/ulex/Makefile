# ex:ts=8
# Ports collection makefile for:	ulex
# Date created:			Mar 17, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ulex
PORTVERSION=	0.4
CATEGORIES=	devel
MASTER_SITES=	http://www.cduce.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A lexer generator for Unicode and OCaml

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib
RUN_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib

USE_GMAKE=	yes
ALL_TARGET=	all all.opt

.if !defined(NOPORTDOCS)
ALL_TARGET+=	doc
PORTDOCS=	*
.endif

post-install:
	@${ECHO_CMD} "@unexec ocamlfind remove ${PORTNAME} 2>/dev/null || /usr/bin/true" >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${WRKSRC}/*.css ${DOCSDIR}
.endif

.include <bsd.port.mk>
