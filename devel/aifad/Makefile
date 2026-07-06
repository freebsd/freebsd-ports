PORTNAME=	aifad
DISTVERSION=	2.3.2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/mmottl/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Machine learning system
WWW=		https://mmottl.github.io/aifad

LICENSE=	LGPL21+

BUILD_DEPENDS=	menhir:devel/menhir \
		ocaml-cfg>0:devel/ocaml-cfg \
		ocaml-pcre2>0:devel/ocaml-pcre2 \
		ocaml-res>0:devel/ocaml-res
LIB_DEPENDS=	libpcre2-8.so:devel/pcre2

USES=		ocaml:dune tar:tbz

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGELOG.md LICENSE.md README.md TODO.md
PORTEXAMPLES=	*
PLIST_FILES=	bin/aifad %%OCAML_SITELIBDIR%%/aifad/META \
		%%OCAML_SITELIBDIR%%/aifad/dune-package \
		%%OCAML_SITELIBDIR%%/aifad/opam

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/aifad

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${INSTALL_DATA} * ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
