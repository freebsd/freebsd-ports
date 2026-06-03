PORTNAME=	maki
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.9
CATEGORIES=	devel

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Efficient AI coding agent
WWW=		https://maki.sh

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo gmake perl5 pkgconfig python:build ssl
USE_GITHUB=	yes
GH_ACCOUNT=	tontinton
USE_PERL5=	build

RUN_DEPENDS=	bash:shells/bash

BINARY_ALIAS=	python3=${PYTHON_CMD}

PLIST_FILES=	bin/maki

.include "${.CURDIR}/Makefile.crates"

MAKE_ENV+=	PYO3_PYTHON=${PYTHON_CMD}

.include <bsd.port.mk>
