PORTNAME=	parmap
DISTVERSION=	1.0-rc9
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	dumbbell@FreeBSD.org
COMMENT=	Minimalistic library allowing to exploit multicore architecture

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ocamlbuild:devel/ocaml-ocamlbuild

USE_GITHUB=	yes
GH_ACCOUNT=	rdicosmo

USES=			gmake
GNU_CONFIGURE=		yes
USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ocaml/parmap/*.cmxs
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ocaml/stublibs/*.so

.include <bsd.port.mk>
