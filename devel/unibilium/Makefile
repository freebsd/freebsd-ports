# Created by: Anton Tornqvist <antont@inbox.lv>
# $FreeBSD$

PORTNAME=	unibilium
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0
CATEGORIES=	devel

MAINTAINER=	chuck@tuffli.net
COMMENT=	Very basic terminfo library

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LGPLv3

USES=		gmake libtool:build pathfix perl5 pkgconfig
PATHFIX_MAKEFILEIN=	Makefile
USE_PERL5=	build
USE_LDCONFIG=	yes
MAKE_ARGS=	MANDIR=${MANPREFIX}/man

USE_GITHUB=	yes
GH_ACCOUNT=	neovim
GH_TAGNAME=	92d929f

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libunibilium.so

.include <bsd.port.mk>
