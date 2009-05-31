# New ports collection makefile for:	odamex
# Date created:				2007-12-06
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	odamex
PORTVERSION=	0.4.3
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	odamex-src-${PORTVERSION}

MAINTAINER=	joshua_rickmar@eumx.net
COMMENT=	The Standard in Online Multiplayer Doom

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer

OPTIONS=	LAUNCHER "Enable GUI launcher program" off

.include <bsd.port.pre.mk>

.if defined(WITH_LAUNCHER)
USE_WX=		2.6+
MAKE_ENV+=	WXRC_CMD="${WXRC_CMD}" WITH_LAUNCHER=yes
PLIST_SUB+=	LAUNCHER=""
.else
PLIST_SUB+=	LAUNCHER="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%DMDIR%%|${DMDIR}|; \
		s|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/client/src/d_main.cpp \
		${WRKSRC}/server/src/d_main.cpp

.if defined(WITH_LAUNCHER)
	@${REINPLACE_CMD} -e 's|\./odamex|odamex|' \
		${WRKSRC}/odalaunch/src/misc.cpp
.endif

do-install:
.for f in odamaster odamex odasrv
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
.if defined(WITH_LAUNCHER)
	${INSTALL_PROGRAM} ${WRKSRC}/odalaunch/odalaunch ${PREFIX}/bin
.endif
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/odamex.wad ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.post.mk>
