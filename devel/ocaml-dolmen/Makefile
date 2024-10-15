PORTNAME=	dolmen
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Library for writing deduction and logic languages in Objective Caml
WWW=		https://github.com/Gbury/dolmen

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/menhir:devel/menhir \
		${SA_DIR}/farith/META:math/ocaml-farith \
		${SA_DIR}/fmt/META:devel/ocaml-fmt \
		${SA_DIR}/gen/META:devel/ocaml-gen \
		${SA_DIR}/linol/META:devel/ocaml-linol \
		${SA_DIR}/logs/META:devel/ocaml-logs \
		${SA_DIR}/lsp/META:devel/ocaml-lsp \
		${SA_DIR}/pp_loc/META:devel/ocaml-pp_loc \
		${SA_DIR}/ppx_deriving/META:devel/ocaml-ppx_deriving \
		${SA_DIR}/ppx_hash/META:devel/ocaml-ppx_hash \
		${SA_DIR}/ppx_yojson_conv/META:devel/ocaml-ppx_yojson_conv \
		${SA_DIR}/spelll/META:textproc/ocaml-spelll \
		${SA_DIR}/uutf/META:devel/ocaml-uutf
LIB_DEPENDS=	libev.so:devel/libev \
		libgmp.so:math/gmp
RUN_DEPENDS=	${SA_DIR}/farith/META:math/ocaml-farith \
		${SA_DIR}/fmt/META:devel/ocaml-fmt \
		${SA_DIR}/gen/META:devel/ocaml-gen \
		${SA_DIR}/linol/META:devel/ocaml-linol \
		${SA_DIR}/logs/META:devel/ocaml-logs \
		${SA_DIR}/lsp/META:devel/ocaml-lsp \
		${SA_DIR}/menhirLib/META:devel/menhir \
		${SA_DIR}/pp_loc/META:devel/ocaml-pp_loc \
		${SA_DIR}/ppx_deriving/META:devel/ocaml-ppx_deriving \
		${SA_DIR}/ppx_hash/META:devel/ocaml-ppx_hash \
		${SA_DIR}/ppx_yojson_conv_lib/META:devel/ocaml-ppx_yojson_conv_lib \
		${SA_DIR}/spelll/META:textproc/ocaml-spelll \
		${SA_DIR}/uutf/META:devel/ocaml-uutf

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	Gbury

USE_OCAML=		yes
OCAML_PACKAGES=		${PORTNAME} ${PORTNAME}_bin ${PORTNAME}_loop \
			${PORTNAME}_lsp ${PORTNAME}_model ${PORTNAME}_type
DUNE_INSTALL_TARGETS=	${OCAML_PACKAGES}

DOCSDIR=	${OCAML_DOCSDIR}
PORTDOCS=	dolmen/odoc-pages/index.mld \
		${OCAML_PACKAGES:@p@$p/CHANGES.md $p/LICENSE $p/README.md@}

OPTIONS_DEFINE=	DOCS MANPAGES
OPTIONS_SUB=	yes

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-patch:
	@${REINPLACE_CMD} \
		-e "/^version:/s/dev/${PORTVERSION}/" \
		${WRKSRC}/dolmen.opam \
		${WRKSRC}/dolmen_bin.opam \
		${WRKSRC}/dolmen_loop.opam \
		${WRKSRC}/dolmen_lsp.opam \
		${WRKSRC}/dolmen_model.opam \
		${WRKSRC}/dolmen_type.opam

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/dolmen \
		${STAGEDIR}${PREFIX}/bin/dolmenls
	@(cd ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}; \
		${STRIP_CMD} \
			dolmen/ae/dolmen_ae.cmxs \
			dolmen/class/dolmen_class.cmxs \
			dolmen/dimacs/dolmen_dimacs.cmxs dolmen/dolmen.cmxs \
			dolmen/icnf/dolmen_icnf.cmxs \
			dolmen/intf/dolmen_intf.cmxs \
			dolmen/line/dolmen_line.cmxs \
			dolmen/smtlib2/dolmen_smtlib2.cmxs \
			dolmen/smtlib2/poly/dolmen_smtlib2_poly.cmxs \
			dolmen/smtlib2/v6/dolmen_smtlib2_v6.cmxs \
			dolmen/smtlib2/v6_response/dolmen_smtlib2_v6_response.cmxs \
			dolmen/smtlib2/v6_script/dolmen_smtlib2_v6_script.cmxs \
			dolmen/std/dolmen_std.cmxs \
			dolmen/tptp/dolmen_tptp.cmxs \
			dolmen/tptp/v6_3_0/dolmen_tptp_v6_3_0.cmxs \
			dolmen/zf/dolmen_zf.cmxs dolmen_loop/dolmen_loop.cmxs \
			dolmen_model/dolmen_model.cmxs \
			dolmen_type/dolmen_type.cmxs)

.include <bsd.port.mk>
