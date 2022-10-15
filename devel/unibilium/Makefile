PORTNAME=	unibilium
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.1
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very basic terminfo library
WWW=		https://github.com/mauke/unibilium

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LGPLv3

USES=		gmake libtool:build pathfix perl5 pkgconfig
PATHFIX_MAKEFILEIN=	Makefile
USE_PERL5=	build
USE_LDCONFIG=	yes
MAKE_ARGS=	MANDIR=${MANPREFIX}/man

USE_GITHUB=	yes
GH_ACCOUNT=	neovim
GH_TAGNAME=	444e4f3

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libunibilium.so

.include <bsd.port.mk>
