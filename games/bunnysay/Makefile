# Created by: Ben Lavery <ben.lavery@hashbang0.com>
# $FreeBSD$

PORTNAME=	bunnysay
PORTVERSION=	1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	ben.lavery@hashbang0.com
COMMENT=	Bunny Sign for terminals

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang dos2unix
DOS2UNIX_FILES=	src/BunnySay.cpp src/BunnySay.h

USE_GITHUB=	yes
GH_ACCOUNT=	co60ca

PLIST_FILES=	bin/bunnysay

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
LIB_DEPENDS+=	libc++.so.1:devel/libc++
CFLAGS+=	-isystem${LOCALBASE}/include/c++/v1
CXXFLAGS+=	-isystem${LOCALBASE}/include/c++/v1
LDFLAGS+=	-L${LOCALBASE}/lib/c++
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.post.mk>
