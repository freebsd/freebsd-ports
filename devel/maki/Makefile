PORTNAME=	maki
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.4
CATEGORIES=	devel

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Efficient AI coding agent
WWW=		https://maki.sh

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES=		cargo gmake perl5 pkgconfig python:build ssl
USE_GITHUB=	yes
GH_ACCOUNT=	tontinton
USE_PERL5=	build

BINARY_ALIAS=	python3=${PYTHON_CMD}

PLIST_FILES=	bin/maki

MAKE_ENV+=	PYO3_PYTHON=${PYTHON_CMD}

.include <bsd.port.mk>
