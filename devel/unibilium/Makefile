PORTNAME=	unibilium
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Terminfo parsing library
WWW=		https://github.com/neovim/unibilium

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LGPLv3

USES=		gmake libtool:build pathfix perl5 pkgconfig
USE_PERL5=	build
PATHFIX_MAKEFILEIN=	Makefile

USE_GITHUB=	yes
GH_ACCOUNT=	neovim

MAKE_ARGS=	MANDIR=${PREFIX}/share/man
TEST_TARGET=	test
USE_LDCONFIG=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libunibilium.so

.include <bsd.port.mk>
