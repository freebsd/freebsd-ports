# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quetoo
PORTVERSION=	0.6.1
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://tastyspleen.net/~jdolan/ \
		http://freebsd.nsu.ru/distfiles/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Fast, stable, compatible, and secure Quake II client

LICENSE=	GPLv2

USES=		dos2unix gl sdl tar:bzip2
USE_GL=		glut
USE_SDL=	sdl
DOS2UNIX_FILES=	src/vanctf/g_local.h

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
		s,^(GAME_MODULES=")baseq2",\1", ; \
		s,-Werror,,' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's,-ldl,,' ${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/quetoo ${STAGEDIR}${PREFIX}/bin
.for g in ${Q2GAMES}
	@${MKDIR} ${STAGEDIR}${LIBDIR}/${g}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${g}/.libs/game.so \
		${STAGEDIR}${LIBDIR}/${g}
.endfor
.if ${PORT_OPTIONS:MQMASS}
	@${MKDIR} ${STAGEDIR}${DATADIR}/qmass/sound
	${INSTALL_DATA} ${WRKSRC}/data/qmass/sound/*.wav \
		${STAGEDIR}${DATADIR}/qmass/sound
.endif
.if ${PORT_OPTIONS:MVANCTF}
	@${MKDIR} ${STAGEDIR}${DATADIR}/vanctf/maps
	${INSTALL_DATA} ${WRKSRC}/data/vanctf/maps/*.ent \
		${STAGEDIR}${DATADIR}/vanctf/maps
	${INSTALL_DATA} ${WRKSRC}/data/vanctf/maps.lst \
		${STAGEDIR}${DATADIR}/vanctf
.endif
.if ${PORT_OPTIONS:MQMASS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/qmass
	${INSTALL_DATA} ${WRKSRC}/src/qmass/README ${STAGEDIR}${DOCSDIR}/qmass
.endif
.if ${PORT_OPTIONS:MVANCTF}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/vanctf
	${INSTALL_DATA} ${WRKSRC}/src/vanctf/*E* ${STAGEDIR}${DOCSDIR}/vanctf
.endif
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include "${.CURDIR}/../quake2-data/Makefile.include"
.include <bsd.port.mk>
