PORTNAME=	cmdliner
PORTVERSION=	1.0.4
CATEGORIES=	devel
MASTER_SITES=	http://erratique.ch/software/cmdliner/releases/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml module for handling of command line interfaces

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		gmake tar:tbz
USE_OCAML=		yes
USE_OCAML_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	tes
MAKE_ARGS=	DOCDIR=${STAGEDIR}${OCAML_DOCSDIR}/${PORTNAME} \
		LIBDIR=${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}
INSTALL_TARGET=	install

OPTIONS_DEFINE=	DOCS
DOCS_INSTALL_TARGET=	install-doc

.include <bsd.port.mk>
