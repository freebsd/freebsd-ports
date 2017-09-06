# Created by: Anton Tornqvist <antont@inbox.lv>
# $FreeBSD$

PORTNAME=	unibilium
PORTVERSION=	1.2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	chuck@tuffli.net
COMMENT=	Unibilium is a very basic terminfo library

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LGPLv3

USES=		gmake libtool:build pathfix perl5 pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	mauke

PATHFIX_MAKEFILEIN=	Makefile
USE_PERL5=	build
USE_LDCONFIG=	yes
MAKE_ARGS=	MANDIR=${MANPREFIX}/man

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libunibilium.so

.include <bsd.port.mk>
