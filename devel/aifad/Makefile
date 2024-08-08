PORTNAME=	aifad
PORTVERSION=	2.3.0
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Machine learning system
WWW=		https://mmottl.github.io/aifad

LICENSE=	LGPL21+

BUILD_DEPENDS=	menhir:devel/menhir \
		ocaml-cfg>0:devel/ocaml-cfg \
		ocaml-pcre>0:devel/ocaml-pcre \
		ocaml-res>0:devel/ocaml-res
LIB_DEPENDS=	libpcre.so:devel/pcre

USE_GITHUB=	yes
GH_ACCOUNT=	mmottl

USES=		ocaml:dune
USE_OCAML=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE.md README.md TODO.md
PORTEXAMPLES=	*
PLIST_FILES=	bin/aifad %%OCAML_SITELIBDIR%%/aifad/META \
		%%OCAML_SITELIBDIR%%/aifad/dune-package \
		%%OCAML_SITELIBDIR%%/aifad/opam
OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/aifad

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${INSTALL_DATA} * ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
