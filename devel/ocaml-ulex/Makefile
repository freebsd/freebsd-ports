# Created by: ijliao
# $FreeBSD$

PORTNAME=	ulex
PORTVERSION=	1.1
PORTREVISION=	1
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

MAKE_JOBS_UNSAFE=	yes

.if !defined(NOPORTDOCS)
ALL_TARGET+=	doc
PORTDOCS=	*
.endif

PKGDEINSTALL=	${PKGINSTALL}

NO_STAGE=	yes
post-install:
	@${FIND} ${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME} -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${WRKSRC}/*.css ${DOCSDIR}
.endif

.include <bsd.port.mk>
