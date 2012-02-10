# New ports collection makefile for:	ocaml-lwt
# Date created:				7 July 2008
# Whom:					jaapb@kerguelen.org
#
# $FreeBSD$
#

PORTNAME=	lwt
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.ocsigen.org/download/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	Cooperative threading library for OCaml

MAKE_JOBS_UNSAFE=	yes

USE_OCAML=		yes
OCAMLC_DEPEND=		ocaml>=3.10:${OCAMLC_PORT}
USE_OCAML_FINDLIB=	yes
USE_OCAMLFIND_PLIST=	yes
USE_OCAML_LDCONFIG=	yes

USE_GMAKE=		yes
DOCSDIR=		${PREFIX}/share/doc/ocaml/${PORTNAME}
PORTDOCS=		*

BUILD_DEPENDS+=		${SA_DIR}/ssl/ssl.a:${PORTSDIR}/security/ocaml-ssl
RUN_DEPENDS+=		${SA_DIR}/ssl/ssl.a:${PORTSDIR}/security/ocaml-ssl

SA_DIR=         	${PREFIX}/${OCAML_SITELIBDIR}

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/_build/lwt.docdir/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
