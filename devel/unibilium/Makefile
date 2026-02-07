PORTNAME=	unibilium
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.2
CATEGORIES=	devel

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Terminfo parsing library
WWW=		https://github.com/neovim/unibilium

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LGPLv3

USES=		autoreconf gmake libtool:build perl5 pkgconfig
GNU_CONFIGURE=	yes
USE_PERL5=	build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	neovim

TEST_TARGET=	test

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libunibilium.so

.include <bsd.port.mk>
