PORTNAME=	psmt2-frontend
DISTVERSION=	0.4.0
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	SMT-LIB 2 parsing library for Objective Caml
WWW=		https://github.com/ACoquereau/psmt2-frontend

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${LOCALBASE}/bin/menhir:devel/menhir

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	ACoquereau

OCAML_PACKAGES=		${PORTNAME} ${PORTNAME}_bin
DUNE_INSTALL_TARGETS=	${OCAML_PACKAGES}

DOCSDIR=	${OCAML_DOCSDIR}
PORTDOCS=	${OCAML_PACKAGES:@p@$p/CHANGES.md $p/LICENSE $p/LICENSE.md $p/README.md $p/odoc-pages/index.mld@}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/psmt2-frontend/psmt2Frontend.cmxs

.include <bsd.port.mk>
