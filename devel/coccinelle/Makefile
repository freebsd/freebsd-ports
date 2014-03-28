# Created by: Andriy Gapon
# $FreeBSD$

PORTNAME=	coccinelle
DISTVERSION=	1.0.0-rc19
CATEGORIES=	devel
MASTER_SITES=	http://coccinelle.lip6.fr/distrib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	avg@icyb.net.ua
COMMENT=	Program matching and transformation engine

LICENSE=	GPLv2

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USES=		gmake perl5 pkgconfig:build
GNU_CONFIGURE=	yes
USE_PERL5=	build
USE_PYTHON=	yes
USE_OCAML=	3.0+
MAKE_ARGS+=	PYTHON_VERSION=${PYTHON_VER}
CONFIGURE_ENV+=	PYVER=${PYTHON_VER} PYTHON=${PYTHON_CMD}

.include <bsd.port.mk>
