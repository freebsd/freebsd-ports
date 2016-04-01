# Created by: Andriy Gapon
# $FreeBSD$

PORTNAME=	coccinelle
PORTVERSION=	1.0.4
CATEGORIES=	devel
MASTER_SITES=	http://coccinelle.lip6.fr/distrib/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program matching and transformation engine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	menhir:devel/menhir \
		ocaml-parmap>=0:devel/ocaml-parmap \
		ocaml-pcre>=0:devel/ocaml-pcre
LIB_DEPENDS=	libpcre.so:devel/pcre

USE_OCAML=	3.0+
USE_OCAML_CAMLP4=yes

USES=		gmake perl5 pkgconfig:build python tar:tgz
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PYTHON="${PYTHON_CMD}" PYVER="${PYTHON_VER}"
MAKE_ARGS=	PYTHON_VERSION="${PYTHON_VER}"

post-install:
	# FIXME: Stripping spatch(1) breaks the executable.
	# ${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/coccinelle/spatch
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/coccinelle/*.so

.include <bsd.port.mk>
