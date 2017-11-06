# Created by: Ben Lavery <ben.lavery@hashbang0.com>
# $FreeBSD$

PORTNAME=	bunnysay
PORTVERSION=	1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	ben.lavery@hashbang0.com
COMMENT=	Bunny Sign for terminals with UTF-8 support

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	fails to compile: cc1plus: error: unrecognized command line option -std=c++11

USES=		gmake

ALL_TARGET=	bunnysay

USE_GITHUB=	yes
GH_ACCOUNT=	co60ca

PLIST_FILES=	bin/bunnysay

post-extract:
	@${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bunnysay ${STAGEDIR}${PREFIX}/bin/${PORTNAME} 

.include <bsd.port.mk>
