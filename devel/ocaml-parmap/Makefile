PORTNAME=	parmap
DISTVERSION=	1.2.4
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	dumbbell@FreeBSD.org
COMMENT=	Minimalistic library allowing to exploit multicore architecture
WWW=		https://github.com/rdicosmo/parmap

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	dune:devel/ocaml-dune

USE_GITHUB=	yes
GH_ACCOUNT=	rdicosmo

USES=			gmake
USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes

TARGETS=	${PORTNAME}

do-build:
	cd ${BUILD_WRKSRC} && dune build --verbose -p ${TARGETS:ts,} -j ${MAKE_JOBS_NUMBER}

do-install:
	cd ${INSTALL_WRKSRC} && dune install --destdir=${STAGEDIR} \
		--libdir=${PREFIX}/${OCAML_SITELIBDIR} ${TARGETS}

.include <bsd.port.mk>
