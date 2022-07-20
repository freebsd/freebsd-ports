PORTNAME=	camlp4
PORTVERSION=	4.07+1
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	michipili@gmail.com
COMMENT=	System for writing extensible parsers for OCaml

LICENSE=	LGPL20

BUILD_DEPENDS=	ocamlbuild:devel/ocaml-ocamlbuild

USE_GITHUB=	yes
GH_ACCOUNT=	ocaml

USES=		gmake
USE_OCAML=	yes
HAS_CONFIGURE=	yes
MAKE_ENV+=	DESTDIR="${STAGEDIR}"
MAKE_JOBS_UNSAFE=yes
ALL_TARGET=	all camlp4/META
INSTALL_TARGET=	install install-META

post-install:
.for f in camlp4o camlp4of camlp4oof camlp4orf camlp4r camlp4rf
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${f}.opt
.endfor

.include <bsd.port.mk>
