PORTNAME=	tokyotyrant
PORTVERSION=	1.1.41
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	https://dbmx.net/tokyotyrant/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network interface of Tokyo Cabinet
WWW=		https://dbmx.net/tokyotyrant/

BUILD_DEPENDS=	tokyocabinet>=1.4.20:databases/tokyocabinet
LIB_DEPENDS=	libtokyocabinet.so:databases/tokyocabinet

USES=		gmake localbase

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_LDCONFIG=	yes
USE_RC_SUBR=	ttserver

OPTIONS_DEFINE=	LUA
OPTIONS_DEFAULT=LUA # should be removed before committing

LUA_CFLAGS=		-I${LUA_INCDIR}
LUA_CONFIGURE_ENABLE=	lua
LUA_USES=		lua

post-patch:
	@${REINPLACE_CMD} -e 's|llua|llua-${LUA_VER}|g' ${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
