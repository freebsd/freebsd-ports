PORTNAME=	topkg
PORTVERSION=	1.0.3
CATEGORIES=	devel
MASTER_SITES=	https://erratique.ch/software/topkg/releases/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Transitory OCaml software packager

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	ocamlbuild:devel/ocaml-ocamlbuild \
		opam-installer:devel/ocaml-opam

USES=		tar:tbz
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${BUILD_WRKSRC} && ocaml pkg/pkg.ml build

do-install:
	cd ${INSTALL_WRKSRC} && opam-installer -i \
		--prefix=${STAGEDIR}${PREFIX} \
		--docdir=${OCAML_DOCSDIR:S,^${PREFIX}/,,} \
		--libdir=${OCAML_SITELIBDIR} ${PORTNAME}.install

.include <bsd.port.mk>
