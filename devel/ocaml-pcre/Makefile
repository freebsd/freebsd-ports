# Created by: Henrik Motakef <henrik.motakef@web.de>
# $FreeBSD$

PORTNAME=	pcre
PORTVERSION=	7.2.3
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Perl compatible regular expressions for Objective Caml

LICENSE=	LGPL21

LIB_DEPENDS=	libpcre.so:devel/pcre

USE_GITHUB=	yes
GH_ACCOUNT=	mmottl
GH_PROJECT=	${PORTNAME}-ocaml
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
EXAMPLESDIR=	${OCAML_EXAMPLESDIR}/${PORTNAME}
PORTEXAMPLES=	cloc count_hash pcregrep subst
DOCSDIR=	${PREFIX}/share/doc/pcre-ocaml
PORTDOCS=	api

OPTIONS_DEFINE=	DOCS EXAMPLES
DOCS_CONFIGURE_OFF=	--disable-docs

post-patch:
	${REINPLACE_CMD} -e 's|$$prefix"/"share|${STAGEDIR}${PREFIX}/share|' \
	    -e '/datarootdir/s|$$pkg_name|&-ocaml|' \
	    ${WRKSRC}/setup.ml
	${REINPLACE_CMD} -e 's| safe_string,||' ${WRKSRC}/_tags

post-install:
	cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} \
	    lib/ocaml/site-lib/pcre/dllpcre_stubs.so \
	    lib/ocaml/site-lib/pcre/pcre.cmxs

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
