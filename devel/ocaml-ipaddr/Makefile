# $FreeBSD$

PORTNAME=	ipaddr
PORTVERSION=	2.6.1
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	johans@FreeBSD.org
COMMENT=	OCaml library for manipulation of IP address representations

BUILD_DEPENDS=	${LOCALBASE}/${OCAML_SITELIBDIR}/sexplib/sexplib.a:devel/ocaml-sexplib
RUN_DEPENDS=	${LOCALBASE}/${OCAML_SITELIBDIR}/sexplib/sexplib.a:devel/ocaml-sexplib

USE_GITHUB=	yes
GH_ACCOUNT=	mirage
GH_PROJECT=	ocaml-ipaddr

USES=			gmake
HAS_CONFIGURE=		yes
MAKE_JOBS_UNSAFE=	yes

USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_CAMLP4=	yes
USE_OCAMLFIND_PLIST=	yes
USE_OCAML_LDCONFIG=	yes

do-configure:
	cd ${WRKSRC}; ocaml setup.ml -configure ${CONFIGURE_ARGS}

.include <bsd.port.mk>
