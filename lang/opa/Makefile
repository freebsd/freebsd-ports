# Ports collection makefile for:	opa
# Date created:				27 December 2011
# Whom:					"Mezz" <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	opa
PORTVERSION=	1.0.5.${GITVER}
CATEGORIES=	lang
MASTER_SITES=	http://download.opalang.org/tar-gz/
DISTNAME=	${PORTNAME}_v${GITVER}

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	Open source, simple, and unified platform for writing web apps

BUILD_DEPENDS=	${OCAMLFIND_DEPEND} \
		${LOCALBASE}/${OCAML_SITELIBDIR}/ssl/ssl.a:${PORTSDIR}/security/ocaml-ssl \
		${LOCALBASE}/${OCAML_SITELIBDIR}/cryptokit/cryptokit.a:${PORTSDIR}/security/ocaml-cryptokit \
		${LOCALBASE}/${OCAML_SITELIBDIR}/zip/zip.a:${PORTSDIR}/archivers/ocaml-zip \
		${LOCALBASE}/${OCAML_LIBDIR}/ocamlgraph/graph.a:${PORTSDIR}/math/ocaml-ocamlgraph \
		${LOCALBASE}/${OCAML_SITELIBDIR}/ulex/ulexing.a:${PORTSDIR}/devel/ocaml-ulex \
		${LOCALBASE}/bin/node:${PORTSDIR}/www/node
RUN_DEPENDS=	${LOCALBASE}/${OCAML_SITELIBDIR}/ssl/ssl.a:${PORTSDIR}/security/ocaml-ssl \
		${LOCALBASE}/${OCAML_SITELIBDIR}/cryptokit/cryptokit.a:${PORTSDIR}/security/ocaml-cryptokit \
		${LOCALBASE}/${OCAML_SITELIBDIR}/zip/zip.a:${PORTSDIR}/archivers/ocaml-zip \
		${LOCALBASE}/${OCAML_LIBDIR}/ocamlgraph/graph.a:${PORTSDIR}/math/ocaml-ocamlgraph \
		${LOCALBASE}/${OCAML_SITELIBDIR}/ulex/ulexing.a:${PORTSDIR}/devel/ocaml-ulex \
		${LOCALBASE}/bin/node:${PORTSDIR}/www/node \
		${LOCALBASE}/bin/npm:${PORTSDIR}/www/npm

GITVER=		2988
USE_JAVA=	yes
JAVA_BUILD=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_OCAML=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-prefix ${PREFIX}
MAKE_ENV=	MLSTATELIBS="${WRKSRC}/_build"

MAN1=		bslbrowser.1 filepos.1 gen_opa_manpage.1 \
		gen_opatop_manpage.1 genman.1 globalizer.1 jsstat.1 \
		mlidl.1 ocamlbase.1 odep.1 odeplink.1 ofile.1 opa-cloud.1 \
		opa-db-server.1 opa-db-tool.1 opa-plugin-browser-bin.1 \
		opa-plugin-builder-bin.1 opa-translate.1 opa.1 opa2opa.1 \
		opadep.1 opatop.1 opatrack.1 passdesign.1 ppdebug.1 \
		qmljs.1 trx.1 trx_interpreter.1 wsdl2ml.1

.if defined(WITH_CAMLIDL)
BUILD_DEPENDS+=	${LOCALBASE}/bin/camlidl:${PORTSDIR}/lang/ocaml-camlidl
LIB_DEPENDS+=	natpmp:${PORTSDIR}/net/libnatpmp \
		miniupnpc:${PORTSDIR}/net/miniupnpc
RUN_DEPENDS+=	${LOCALBASE}/bin/camlidl:${PORTSDIR}/lang/ocaml-camlidl
CONFIGURE_ARGS+=-camlidl
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|share/man/|/man/|g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|_git_version = .*"|_git_version = ${GITVER}"|g' \
		${WRKSRC}/compiler/buildinfos/generate_buildinfos.sh
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/tools/build/myocamlbuild_prefix.ml

.include <bsd.port.mk>
