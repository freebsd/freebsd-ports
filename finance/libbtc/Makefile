PORTNAME=	libbtc
PORTVERSION=	g20210428
CATEGORIES=	finance

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tiny Bitcoin Library written in C

LICENSE=	MIT

LIB_DEPENDS=	libevent_core.so:devel/libevent

USES=		autoreconf gmake libtool localbase
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_TAGNAME=	0793399

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
