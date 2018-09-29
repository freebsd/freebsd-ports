# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	camlidl
PORTVERSION=	1.05
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://caml.inria.fr/distrib/bazar-ocaml/
PKGNAMEPREFIX=	ocaml-
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-${PORTVERSION}.doc.html.tar.gz
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	kennedy.greg@gmail.com
COMMENT=	Stub code generator for using C/C++ libraries from OCaml

LICENSE=	LGPL20 LGPL21
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_OCAML=	yes

MAKE_JOBS_UNSAFE=	yes

DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-extract:
	@${REINPLACE_CMD} -e "s,^\(OCAMLLIB=\).*,\1${STAGEDIR}${PREFIX}/lib/ocaml,g" \
		-e "s,^\(BINDIR=\).*,\1${STAGEDIR}${PREFIX}/bin,g" \
		-e "s,^CFLAGS=.*,#\&,g" \
		-e "s,^\(CPP=\).*,\1/usr/bin/cpp,g" \
		${WRKSRC}/config/Makefile.unix

	@${REINPLACE_CMD} -e \
		"/^install/,/^$$/s,\([ \t]*\)cp,\1${INSTALL_SCRIPT},g" \
		${WRKSRC}/compiler/Makefile

	@${REINPLACE_CMD} -e \
		"/^install/,/^$$/s,\([ \t]*\)cp,\1${INSTALL_DATA},g" \
		${WRKSRC}/lib/Makefile ${WRKSRC}/runtime/Makefile.unix

	@${LN} -sf ${WRKSRC}/config/Makefile.unix ${WRKSRC}/config/Makefile

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ocaml/caml

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${GZCAT} ${_DISTDIR}/${PORTNAME}-${PORTVERSION}.doc.html.tar.gz \
		| ${TAR} -C ${STAGEDIR}${DOCSDIR} -xf -

test:
	@${ECHO_CMD} "Testing IDL library"
	@${REINPLACE_CMD} -e "s,^\(CCPP=\).*,\1${CXX},g" \
		${WRKSRC}/tests/Makefile
	cd ${WRKSRC}/tests && ${SETENV} ${MAKE_ENV} ${MAKE} all

.include <bsd.port.mk>
