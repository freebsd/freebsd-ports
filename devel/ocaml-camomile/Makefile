PORTNAME=	camomile
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Comprehensive Unicode library for Objective Caml
WWW=		https://camomile.sourceforge.net/

LICENSE=	LGPL21

BUILD_DEPENDS=	${SA_DIR}/camlp-streams/META:devel/ocaml-camlp-streams \
		dune:devel/ocaml-dune
RUN_DEPENDS=	${SA_DIR}/camlp-streams/META:devel/ocaml-camlp-streams

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	yoriyuki
GH_PROJECT=	Camomile
USE_OCAML=	yes

MAKE_ENV=	LIBDIR="${PREFIX}/${OCAML_SITELIBDIR}"
DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}

PORTDOCS=	CHANGES.md LICENSE.md README.md

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-patch:
	@${REINPLACE_CMD} -e '/^INSTALL_ARGS/ \
		s:$$: $$(if $$(LIBDIR),--libdir $$(LIBDIR),):' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,(\*\*,(*,' \
		${WRKSRC}/Camomile/public/uCharInfo.mli \
		${WRKSRC}/Camomile/public/stringPrep.ml*

.include <bsd.port.mk>
