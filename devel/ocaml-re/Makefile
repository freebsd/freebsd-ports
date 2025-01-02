PORTNAME=	re
PORTVERSION=	1.11.0
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pure OCaml regular expressions
WWW=		https://github.com/ocaml/ocaml-re

LICENSE=	LGPL21

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	ocaml
GH_PROJECT=	${PKGNAMEPREFIX}${PORTNAME}

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE.md README.md

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

post-patch:
	${REINPLACE_CMD} \
		-e "s/(name ${PORTNAME})/&\n (version ${PORTVERSION})/" \
		${WRKSRC}/dune-project

post-install:
	${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/emacs/re_emacs.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/glob/re_glob.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/pcre/re_pcre.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/str/re_str.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/perl/re_perl.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/posix/re_posix.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/re.cmxs

.include <bsd.port.mk>
