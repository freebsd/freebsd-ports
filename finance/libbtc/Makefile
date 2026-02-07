PORTNAME=	libbtc
PORTVERSION=	g20210428
PORTREVISION=	1
CATEGORIES=	finance

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tiny Bitcoin Library written in C
WWW=		https://github.com/libbtc/libbtc

LICENSE=	MIT

LIB_DEPENDS=	libevent_core.so:devel/libevent

USES=		autoreconf gmake libtool:keepla localbase # keepla for bitcoin-armory
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_TAGNAME=	0793399

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

PORTSCOUT=	ignore:1 # tags are bogus

.include <bsd.port.mk>
