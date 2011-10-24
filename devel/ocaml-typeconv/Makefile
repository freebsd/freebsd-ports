# New ports collection makefile for:	ocaml-type-conv
# Date created:		2008-04-08
# Whom:			Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	type-conv
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://janestcapital.com/ocaml/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Type conversion routines for OCaml

USE_GMAKE=	yes
USE_OCAML=	yes
USE_OCAML_FINDLIB=yes

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

.include <bsd.port.pre.mk>

post-extract:
# For nonstandard prefixes
.if !exists(${OCAMLFIND_DESTDIR})
	${MKDIR} ${OCAMLFIND_DESTDIR}
.endif

post-install:
	@${FIND} ${OCAMLFIND_DESTDIR}/${PORTNAME} -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}

.include <bsd.port.post.mk>
