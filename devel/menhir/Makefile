PORTNAME=	menhir
PORTVERSION=	20231231
CATEGORIES=	devel
MASTER_SITES=	http://cristal.inria.fr/~fpottier/menhir/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LR(1) parser generator for OCaml
WWW=		http://cristal.inria.fr/~fpottier/menhir

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		ocaml:dune
USE_GITLAB=	yes
USE_OCAML=	yes
GL_SITE=	https://gitlab.inria.fr/
GL_ACCOUNT=	fpottier
OCAML_PACKAGES=		menhir menhirLib menhirSdk
DUNE_INSTALL_TARGETS=	${OCAML_PACKAGES}

DOCSDIR=	${OCAML_DOCSDIR}
PORTDOCS=	${OCAML_PACKAGES:@p@$p@}

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/menhir
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/menhirLib/menhirLib.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/menhirSdk/menhirSdk.cmxs

.include <bsd.port.mk>
