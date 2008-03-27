# New ports collection makefile for:	Warsow
# Date created:				31 May 2006
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	warsow
PORTVERSION=	0.12
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://warsow.aditsystems.com/ \
		http://ftp.club-internet.fr/pub/games/nofrag/warsow/ \
		http://wsw.surreal-xenotronic.com/
DISTNAME=	${PORTNAME}_${PORTVERSION}_sdk
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A fast paced first person shooter game

RUN_DEPENDS=	${DATADIR}/data0.pk3:${PORTSDIR}/games/warsow-data

ONLY_FOR_ARCHS=	i386 amd64
USE_GMAKE=	yes
USE_GCC=	3.4+
USE_XORG=	xxf86dga
USE_ZIP=	yes
USE_DOS2UNIX=	linux/in_x11.c linux/sys_linux.c

WRKSRC=		${WRKDIR}/source/source012
ALL_TARGET=	game
RELEASEDIR=	${WRKSRC}/release
WSWDATADIR=	${PREFIX}/lib/${PORTNAME}

OPTIONS=	CLIENT	"Build client executable"		on \
		SERVER	"Build dedicated server executable"	on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_SERVER)
IGNORE=		requires at least one of CLIENT and SERVER options
.endif

.if ${ARCH} == "i386"
ARCHSUFFIX=	"_i386"
PLIST_SUB+=	ARCHSUFFIX=${ARCHSUFFIX}
.elif ${ARCH} == "amd64"
ARCHSUFFIX=	"_x86_64"
PLIST_SUB+=	ARCHSUFFIX=${ARCHSUFFIX}
.endif

.if !defined(WITHOUT_CLIENT)
LIB_DEPENDS=	curl.4:${PORTSDIR}/ftp/curl \
		jpeg.9:${PORTSDIR}/graphics/jpeg
USE_GL=		yes
USE_SDL=	yes
ALL_TARGET+=	cgame ui client
WSBIN+=		warsow
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if !defined(WITHOUT_SERVER)
ALL_TARGET+=	ded
WSBIN+=		wsw_server
PLIST_SUB+=	SERVER=""
.else
PLIST_SUB+=	SERVER="@comment "
.endif

post-patch: .SILENT
	${REINPLACE_CMD} -e 's#@$$(DO_CC#$$(DO_CC#; \
		s#-O2 ##' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's#path", "\.#path", "${WSWDATADIR}#; \
		s#dir", "0#dir", "1#' ${WRKSRC}/qcommon/files.c
	${REINPLACE_CMD} -e 's#Linux#FreeBSD#' ${WRKSRC}/game/q_shared.h

do-install:
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}/basewsw
.for FILE in ${WSBIN}
	${INSTALL_PROGRAM} ${RELEASEDIR}/${FILE} ${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${RELEASEDIR}/basewsw/*.so ${PREFIX}/lib/${PORTNAME}/basewsw
	${LN} -s ${DATADIR}/* ${PREFIX}/lib/${PORTNAME}/basewsw

.include <bsd.port.post.mk>
