# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quetoo
PORTVERSION=	0.6.1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://tastyspleen.net/~jdolan/ \
		http://freebsd.nsu.ru/distfiles/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Fast, stable, compatible, and secure Quake II client

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_SDL=	sdl
USE_GL=		glut
USE_DOS2UNIX=	src/vanctf/g_local.h

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OPENGL_CFLAGS="-I${LOCALBASE}/include" \
		OPENGL_LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

LIBDIR=		${PREFIX}/lib/${PORTNAME}
PLIST_SUB+=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"

OPTIONS_DEFINE=	GAME CTF VANCTF QMASS MYSQL DOCS
# Main and CTF game.so files are not built/installed by default since
# they're available via `quake2-data' and `quake2-ctf' ports.
OPTIONS_DEFAULT=	VANCTF QMASS

GAME_DESC=	Build main game (default mod)
CTF_DESC=	Build Capture The Flag mod
VANCTF_DESC=	Build Vanilla CTF mod
QMASS_DESC=	Build QMass deathmatch mod
MYSQL_DESC=	Enable frag logging with MySQL

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGAME}
PLIST_SUB+=	GAME=""
Q2GAMES+=	baseq2
.else
PLIST_SUB+=	GAME="@comment "
.endif

.if ${PORT_OPTIONS:MCTF}
PLIST_SUB+=	CTF=""
Q2GAMES+=	ctf
.else
PLIST_SUB+=	CTF="@comment "
.endif

.if ${PORT_OPTIONS:MQMASS}
PLIST_SUB+=	QMASS=""
Q2GAMES+=	qmass
.else
PLIST_SUB+=	QMASS="@comment "
.endif

.if ${PORT_OPTIONS:MVANCTF}
PLIST_SUB+=	VANCTF=""
Q2GAMES+=	vanctf
.else
PLIST_SUB+=	VANCTF="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql
CONFIGURE_ENV+=	MYSQL_LIBS="-L${LOCALBASE}/lib/mysql -lmysqlclient" \
		MYSQL_CFLAGS="-I${LOCALBASE}/include"
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

CONFIGURE_ARGS+=	--with-games='${Q2GAMES}'

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-patch: .SILENT
	${REINPLACE_CMD} -E 's,^(eval PKGDATADIR=).*$$,\1"${Q2DIR}", ; \
		19752s,sdl-config,${SDL_CONFIG}, ; \
		s,^(GAME_MODULES=")baseq2",\1",' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's,-ldl,,' ${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/quetoo ${PREFIX}/bin
.for g in ${Q2GAMES}
	@${MKDIR} ${LIBDIR}/${g}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${g}/.libs/game.so ${LIBDIR}/${g}
.endfor
.if ${PORT_OPTIONS:MQMASS}
	@${MKDIR} ${DATADIR}/qmass/sound
	${INSTALL_DATA} ${WRKSRC}/data/qmass/sound/*.wav ${DATADIR}/qmass/sound
.if ${PORT_OPTIONS:MVANCTF}
	@${MKDIR} ${DATADIR}/vanctf/maps
	${INSTALL_DATA} ${WRKSRC}/data/vanctf/maps/*.ent ${DATADIR}/vanctf/maps
	${INSTALL_DATA} ${WRKSRC}/data/vanctf/maps.lst ${DATADIR}/vanctf
.endif
.endif
.if ${PORT_OPTIONS:MDOCS}
.  if ${PORT_OPTIONS:MQMASS}
	@${MKDIR} ${DOCSDIR}/qmass
	${INSTALL_DATA} ${WRKSRC}/src/qmass/README ${DOCSDIR}/qmass
.  endif
.  if ${PORT_OPTIONS:MVANCTF}
	@${MKDIR} ${DOCSDIR}/vanctf
	${INSTALL_DATA} ${WRKSRC}/src/vanctf/*E* ${DOCSDIR}/vanctf
.  endif
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include "${.CURDIR}/../quake2-data/Makefile.include"
.include <bsd.port.mk>
