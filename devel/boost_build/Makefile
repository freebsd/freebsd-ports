# Created by: Bruce M. Simpson
# $FreeBSD$

PORTNAME=	boost_build
DISTVERSION=	4.3.0
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible cross-platform build tool suite

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${LOCALBASE}/bin/bjam:devel/boost-jam

USES=		tar:bzip2

USE_GITHUB=	yes
GH_ACCOUNT=	boostorg
GH_PROJECT=	build

SUB_FILES=	pkg-message

do-build:
	@cd ${WRKSRC} && ./bootstrap.sh

do-install:
	cd ${WRKSRC} && ./b2 toolset=clang install --prefix=${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
