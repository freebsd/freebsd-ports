PORTNAME=	result
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Compatibility result module for OCaml
WWW=		https://github.com/janestreet/result

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	dune:devel/ocaml-dune

USES=		gmake ocaml
USE_GITHUB=	yes
GH_ACCOUNT=	janestreet

ALL_TARGET=	default
MAKE_ENV=	LIBDIR=${PREFIX}/${OCAML_SITELIBDIR}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/result/result.cmxs

.include <bsd.port.mk>
