PORTNAME=	uutf
PORTVERSION=	1.0.2
CATEGORIES=	devel
MASTER_SITES=	https://erratique.ch/software/uutf/releases/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Non-blocking streaming Unicode codec for OCaml

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	ocamlbuild:devel/ocaml-ocamlbuild
BUILD_DEPENDS+=	opam-installer:devel/ocaml-opam \
		${LOCALBASE}/${OCAML_SITELIBDIR}/cmdliner/META:devel/ocaml-cmdliner \
		${LOCALBASE}/${OCAML_SITELIBDIR}/topkg/META:devel/ocaml-topkg \
		${LOCALBASE}/${OCAML_SITELIBDIR}/uchar/META:devel/ocaml-uchar

USES=		tar:tbz
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${BUILD_WRKSRC} && ocaml pkg/pkg.ml build

do-install:
	cd ${INSTALL_WRKSRC} && opam-installer -i \
		--prefix=${STAGEDIR}${PREFIX} \
		--docdir=${OCAML_DOCSDIR:S,^${PREFIX}/,,} \
		--libdir=${OCAML_SITELIBDIR} ${PORTNAME}.install

.include <bsd.port.mk>
