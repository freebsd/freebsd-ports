PORTNAME=	camlp5
PORTVERSION=	8.02.01
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Preprocessor-pretty-printer of OCaml
WWW=		https://camlp5.github.io

LICENSE=	INRIA
LICENSE_NAME=	INRIA permissive license with copyright notice requirements
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${SA_DIR}/bos/META:devel/ocaml-bos \
		${SA_DIR}/camlp-streams/META:devel/ocaml-camlp-streams \
		${SA_DIR}/fmt/META:devel/ocaml-fmt \
		${SA_DIR}/pcre2/META:devel/ocaml-pcre2 \
		${SA_DIR}/re/META:devel/ocaml-re \
		${SA_DIR}/rresult/META:devel/ocaml-rresult
RUN_DEPENDS=	${SA_DIR}/camlp-streams/META:devel/ocaml-camlp-streams \
		${SA_DIR}/pcre2/META:devel/ocaml-pcre2 \
		${SA_DIR}/re/META:devel/ocaml-re \
		${SA_DIR}/rresult/META:devel/ocaml-rresult

USES=		gmake perl5 tar:tgz
USE_GITHUB=	yes
USE_OCAML=	yes
USE_PERL5=	build
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix ${PREFIX} --mandir ${PREFIX}/share/man
ALL_TARGET=	world.opt
MAKE_JOBS_UNSAFE=yes

OPTIONS_SINGLE=		MODE
OPTIONS_SINGLE_MODE=	TRANSITIONAL STRICT
OPTIONS_DEFAULT=	STRICT
TRANSITIONAL_DESC=	Compatible syntax tree with old versions
STRICT_DESC=		New syntax tree quotations kit

OPTIONS_DEFINE=	DOCS

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES DEVEL ICHANGES MODE README.md UPGRADING

STRICT_CONFIGURE_ON=	--strict
TRANSITIONAL_CONFIGURE_ON=	--transitional

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/META \
	    ${STAGEDIR}${PREFIX}/lib/ocaml/camlp5
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/camlp5*.opt \
	    ${STAGEDIR}${PREFIX}/${OCAML_LIBDIR}/camlp5/*.o

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
