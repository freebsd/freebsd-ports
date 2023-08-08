PORTNAME=	dune
PORTVERSION=	3.7.1
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Composable build system for OCaml (formerly jbuilder)
WWW=		https://dune.build/

LICENSE=	MIT

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	ocaml
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
SUB_FILES=	setup.ml
SUB_LIST=	OCAML_SITELIBDIR="${PREFIX}/${OCAML_SITELIBDIR}" \
		OCAML_LIBDIR="${PREFIX}/${OCAML_LIBDIR}" \
		OCAML_DOCSDIR="${OCAML_DOCSDIR}" \
		MANPREFIX="${MANPREFIX}"

CONFLICTS_INSTALL=	wdune

ALL_TARGET=	release
MAKE_ENV=	LIBDIR="${PREFIX}/${OCAML_SITELIBDIR}"
DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-patch:
# FreeBSD-specific hack, do not nag upstream (for now)
	@${REINPLACE_CMD} -e '/doc_root = Path.relative/ \
		s:"doc:"${OCAML_DOCSDIR:S,^${PREFIX}/,,}:' \
		${WRKSRC}/src/dune_rules/install.ml

pre-configure:
	@${MV} ${WRKDIR}/setup.ml ${WRKSRC}/src/dune_rules/setup.ml

.include <bsd.port.mk>
