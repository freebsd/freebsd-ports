# Created by: Andriy Gapon
# $FreeBSD$

PORTNAME=	coccinelle
DISTVERSION=	1.0.0-rc22
CATEGORIES=	devel
MASTER_SITES=	http://coccinelle.lip6.fr/distrib/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program matching and transformation engine

LICENSE=	GPLv2

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USES=		gmake perl5 pkgconfig:build python tar:tgz
GNU_CONFIGURE=	yes
USE_PERL5=	build
USE_OCAML=	3.0+
USE_OCAML_CAMLP4=yes
MAKE_ARGS+=	PYTHON_VERSION=${PYTHON_VER}
CONFIGURE_ENV+=	PYVER=${PYTHON_VER} PYTHON=${PYTHON_CMD}

.include <bsd.port.mk>
