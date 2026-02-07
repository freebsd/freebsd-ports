PORTNAME=	extlib
DISTVERSION=	1.7.9
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://github.com/ygrek/ocaml-extlib/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Complete - yet small - standard library for OCaml
WWW=		https://github.com/ygrek/ocaml-extlib

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/../LICENSE

BROKEN_mips=	depends on Ocaml(not available for mips)

BUILD_DEPENDS=	cppo:devel/ocaml-cppo

USES=		gmake ocaml:camlp4,findplist

MAKE_ARGS=	VERSION="${DISTVERSION}"
ALL_TARGET=	all opt doc

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}

WRKSRC_SUBDIR=	src

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} * ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
