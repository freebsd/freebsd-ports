# ex:ts=8
# Ports collection makefile for:	ulex
# Date created:			Mar 17, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ulex
PORTVERSION=	0.7
CATEGORIES=	devel
MASTER_SITES=	http://www.cduce.org/download/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	marwan.burelle@lri.fr
COMMENT=	A lexer generator for Unicode and OCaml

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib
RUN_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib

ALL_TARGET=	all all.opt

MAKE_ENV=	OCAMLFIND_DESTDIR="${PREFIX}/lib/ocaml/site-lib"

.if !defined(NOPORTDOCS)
ALL_TARGET+=	doc
PORTDOCS=	*
.endif

PKGDEINSTALL=	${PKGINSTALL}

post-install:
	@${FIND} ${PREFIX}/lib/ocaml/site-lib/${PORTNAME} -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm lib/ocaml/site-lib/${PORTNAME}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ocamlfind remove ${PORTNAME} 2>/dev/null || true" >> ${TMPPLIST}
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${WRKSRC}/*.css ${DOCSDIR}
.endif

.include <bsd.port.mk>
