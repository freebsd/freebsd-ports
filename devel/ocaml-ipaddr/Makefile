PORTNAME=	ipaddr
DISTVERSIONPREFIX=	v
PORTVERSION=	3.1.0
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml library for manipulation of IP address representations

BUILD_DEPENDS=	${LOCALBASE}/${OCAML_SITELIBDIR}/sexplib0/sexplib0.a:devel/ocaml-sexplib0 \
		dune:devel/ocaml-dune
RUN_DEPENDS=	${LOCALBASE}/${OCAML_SITELIBDIR}/sexplib0/sexplib0.a:devel/ocaml-sexplib0

USE_GITHUB=	yes
GH_ACCOUNT=	mirage
GH_PROJECT=	ocaml-ipaddr

USES=			gmake

USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_CAMLP4=	yes
USE_OCAML_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e '/^SETUP =/s,ocaml,& -unsafe-string,' \
		${WRKSRC}/Makefile

do-install:
	cd ${INSTALL_WRKSRC} && dune install --destdir=${STAGEDIR} \
		--prefix=${PREFIX} --libdir=${PREFIX}/${OCAML_SITELIBDIR}

.include <bsd.port.mk>
