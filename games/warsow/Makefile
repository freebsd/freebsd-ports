# New ports collection makefile for:	Warsow
# Date created:				31 May 2006
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	warsow
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://warsow.aditsystems.com/ \
		http://ftp.club-internet.fr/pub/games/nofrag/warsow/ \
		http://wsw.surreal-xenotronic.com/
DISTNAME=	${PORTNAME}_${PORTVERSION}_sdk
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}_${PORTVERSION}_linux.tar.gz
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A fast paced first person shooter game

USE_GMAKE=	yes
USE_GCC=	3.3+
USE_ZIP=	yes
USE_DOS2UNIX=	linux/in_x11.c linux/sys_linux.c

ALL_TARGET=	game
WRKSRC=		${WRKDIR}/source/source012
RELEASEDIR=	${WRKSRC}/release
DATADIR=	${PREFIX}/lib/${PORTNAME}

OPTIONS=	CLIENT	"Build client executable"		on \
		SERVER	"Build dedicated server executable"	on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_SERVER)
IGNORE=		requires at least one of CLIENT and SERVER options
.endif

.if !defined(WITHOUT_CLIENT)
LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl \
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
		s#_$$(ARCH)##; s#-O2 ##' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's#path", "\.#path", "${DATADIR}#; \
		s#dir", "0#dir", "1#' ${WRKSRC}/qcommon/files.c
	${REINPLACE_CMD} -e 's#Linux#FreeBSD#' ${WRKSRC}/game/q_shared.h

do-install:
.for bin in ${WSBIN}
	${INSTALL_PROGRAM} ${RELEASEDIR}/${bin} ${PREFIX}/bin
.endfor
	@${MKDIR} ${DATADIR}/basewsw
	${INSTALL_PROGRAM} ${RELEASEDIR}/basewsw/*.so ${DATADIR}/basewsw
	@${TAR} xzvf ${_DISTDIR}/${PORTNAME}_${PORTVERSION}_linux.tar.gz \
		-C ${PREFIX}/lib warsow/basewsw/cfgs warsow/basewsw/huds \
		warsow/basewsw/dedicated_autoexec.cfg \
		warsow/basewsw/\*.pk3 && ${CHOWN} -R root:wheel ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${TAR} xzvf ${_DISTDIR}/${PORTNAME}_${PORTVERSION}_linux.tar.gz \
		-C ${WRKDIR} warsow/docs && ${CP} -R ${WRKDIR}/warsow/docs/ \
		${DOCSDIR} && ${CHMOD} -R 777 ${WRKDIR}/warsow
.endif

.include <bsd.port.post.mk>
