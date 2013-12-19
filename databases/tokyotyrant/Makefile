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
USE_GMAKE=	yes
USE_RC_SUBR=	ttserver

MAN1=		tcrmgr.1 tcrmttest.1 tcrtest.1 ttserver.1 ttulmgr.1 ttultest.1
MAN3=		tcrdb.3 tculog.3 ttutil.3
MAN8=		ttservctl.8

OPTIONS_DEFINE=	LUA

LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

NO_STAGE=	yes
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
