PORTNAME=	maki
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.4
CATEGORIES=	devel

MAINTAINER=	ghislain.potier@gpotier.org
COMMENT=	Efficient AI coding agent
WWW=		https://maki.sh

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES=		cargo gmake perl5 pkgconfig python:build ssl
USE_GITHUB=	yes
GH_ACCOUNT=	tontinton
USE_PERL5=	build

MAKE_ENV+=	PYO3_PYTHON=${PYTHON_CMD}
# Compile-time switch (option_env!, upstream PR tontinton/maki#1776): `maki
# update`/`maki rollback` exit with an error pointing at the package manager
# and the startup version check is skipped; updates go through pkg(8).
MAKE_ENV+=	MAKI_DISABLE_UPDATE=1

BINARY_ALIAS=	python3=${PYTHON_CMD}

PLIST_FILES=	bin/maki

.include <bsd.port.mk>
