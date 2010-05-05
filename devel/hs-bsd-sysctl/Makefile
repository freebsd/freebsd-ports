# New ports collection makefile for: hs-bsd-sysctl
# Date created:			04 May 2010
# Whom:				Ju Pengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	bsd-sysctl
PORTVERSION=	1.0.6
CATEGORIES=	devel haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	jupengfei@gmail.com
COMMENT=	Access to the BSD sysctl(3) interface via the Haskell FFI

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS=	${BUILD_DEPENDS}

do-configure:
	cd ${WRKSRC} && runghc Setup.hs configure --prefix=${PREFIX}
do-build:
	cd ${WRKSRC} && runghc Setup.hs build
do-install:
	cd ${WRKSRC} && runghc Setup.hs install

.include <bsd.port.mk>
