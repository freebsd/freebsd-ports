# Created by: Andriy Gapon
# $FreeBSD$

PORTNAME=	coccinelle
PORTVERSION=	1.0.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://coccinelle.lip6.fr/distrib/

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Program matching and transformation engine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	menhir:devel/menhir \
		ocaml-parmap>=0:devel/ocaml-parmap \
		ocaml-pcre>=0:devel/ocaml-pcre
LIB_DEPENDS=	libpcre.so:devel/pcre

USE_OCAML=	3.0+
USE_OCAML_CAMLP4=yes

USES=		autoreconf gmake perl5 pkgconfig:build python shebangfix
BINARY_ALIAS=	make=${LOCALBASE}/bin/gmake
SHEBANG_FILES=	tools/pycocci
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PYTHON="${PYTHON_CMD}" PYVER="${PYTHON_VER}"
MAKE_ARGS=	PYTHON_VERSION="${PYTHON_VER}"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/spatch
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/spgen
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/coccinelle/*.so

.include <bsd.port.mk>
