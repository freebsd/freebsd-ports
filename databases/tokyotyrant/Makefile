# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	tokyotyrant
PORTVERSION=	1.1.41
CATEGORIES=	databases
MASTER_SITES=	http://fallabs.com/${PORTNAME}/

MAINTAINER=	gslin@gslin.org
COMMENT=	Network interface of Tokyo Cabinet

BUILD_DEPENDS=	tokyocabinet>=1.4.20:${PORTSDIR}/databases/tokyocabinet
LIB_DEPENDS=	libtokyocabinet.so:${PORTSDIR}/databases/tokyocabinet

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake
USE_RC_SUBR=	ttserver

OPTIONS_DEFINE=	LUA

LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLUA}
CONFIGURE_ARGS+=	--enable-lua
LDFLAGS+=	-L${LUA_LIBDIR}
CFLAGS+=	-I${LUA_INCDIR}
USE_LUA=	yes
.else
CONFIGURE_ARGS+=	--disable-lua
.endif

# Since gnomehack only works for "(libdir)" case, we need to patch it
# manually.
post-patch:
	${REINPLACE_CMD} -e 's|@libdir@/pkgconfig|@prefix@/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
