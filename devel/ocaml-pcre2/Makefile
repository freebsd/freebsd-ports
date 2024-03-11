PORTNAME=	pcre2
PORTVERSION=	7.5.2
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Perl compatible regular expressions for Objective Caml
WWW=		https://github.com/camlp5/pcre2-ocaml

LICENSE=	LGPL21

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2

USES=		ocaml:dune pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	camlp5
GH_PROJECT=	${PORTNAME}-ocaml
USE_OCAML=	yes
USE_OCAML_LDCONFIG=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
EXAMPLESDIR=	${OCAML_EXAMPLESDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE.md README.md
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DOCS EXAMPLES
DOCS_ALL_TARGET=	examples/ @install

post-patch:
	${REINPLACE_CMD} \
		-e "s/(name ${PORTNAME})/&\n (version ${PORTVERSION})/" \
		${WRKSRC}/dune-project

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	for exe in ${WRKSRC}/_build/default/examples/*.exe ; \
	    do ${INSTALL_PROGRAM} $$exe ${STAGEDIR}${EXAMPLESDIR} ; \
	done
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/dllpcre2_stubs.so \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/pcre2.cmxs

.include <bsd.port.mk>
