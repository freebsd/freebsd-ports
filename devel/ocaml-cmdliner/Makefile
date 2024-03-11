PORTNAME=	cmdliner
PORTVERSION=	1.0.4
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://erratique.ch/software/cmdliner/releases/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	OCaml module for handling command-line interfaces
WWW=		https://erratique.ch/software/cmdliner

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		gmake tar:tbz
USE_OCAML=		yes
USE_OCAML_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	tes
MAKE_ARGS=	DOCDIR=${STAGEDIR}${OCAML_DOCSDIR}/${PORTNAME} \
		LIBDIR=${STAGEDIR}${PREFIX}/${OCAML_LDLIBS}
INSTALL_TARGET=	install

OPTIONS_DEFINE=	DOCS
DOCS_INSTALL_TARGET=	install-doc

.include <bsd.port.mk>
