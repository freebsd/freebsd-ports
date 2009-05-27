# New ports collection makefile for:	tokyotyrant
# Date created:		2009-03-09
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	tokyotyrant
PORTVERSION=	1.1.27
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	tokyocabinet

MAINTAINER=	gslin@gslin.org
COMMENT=	Network interface of Tokyo Cabinet

BUILD_DEPENDS=	tokyocabinet>=1.4.20:${PORTSDIR}/databases/tokyocabinet
LIB_DEPENDS=	tokyocabinet:${PORTSDIR}/databases/tokyocabinet

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_RC_SUBR=	ttserver

MAN1=		tcrmgr.1 tcrmttest.1 tcrtest.1 ttserver.1 ttulmgr.1 ttultest.1
MAN3=		tcrdb.3 tculog.3 ttutil.3
MAN8=		ttservctl.8

OPTIONS=	LUA	"Enable LUA support" off

.include <bsd.port.pre.mk>

.if defined(WITH_LUA)
CONFIGURE_ARGS+=	--enable-lua
CONFIGURE_ENV+=	LDFLAGS="-L${LUA_LIBDIR}"
CFLAGS+=	-I${LUA_INCDIR}
USE_LUA=	yes
.endif

# Since gnomehack only works for "(libdir)" case, we need to patch it
# manually.
post-patch:
	${REINPLACE_CMD} -e 's|@libdir@/pkgconfig|@prefix@/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
