# New ports collection makefile for:	Quetoo
# Date created:				10 Apr 2006
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quetoo
PORTVERSION=	0.6.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://jdolan.dyndns.org/jaydolan/files/ \
		http://tastyspleen.net/~jdolan/ \
		http://freebsd.nsu.ru/distfiles/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Fast, stable, compatible, and secure Quake II client

USE_BZIP2=	yes
USE_SDL=	sdl
USE_GL=		glut
USE_DOS2UNIX=	src/vanctf/g_local.h

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		OPENGL_CFLAGS="-I${LOCALBASE}/include" \
		OPENGL_LIBS="-L${LOCALBASE}/lib"

LIBDIR=		${PREFIX}/lib/${PORTNAME}
PLIST_SUB+=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"

# Main and CTF game.so files are not built/installed by default since
# they're available via `quake2-data' and `quake2-ctf' ports.
#
OPTIONS=	GAME	"Build the main game .so file"		off \
		CTF	"Build Capture The Flag modification"	off \
		VANCTF	"Build Vanilla CTF modification"	on \
		QMASS	"Build QMass deathmatch mod"		on \
		MYSQL	"Enable MySQL frag logging"		off \

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GAME)
PLIST_SUB+=	GAME=""
Q2GAMES+=	baseq2
.else
PLIST_SUB+=	GAME="@comment "
.endif

.if defined(WITH_CTF)
PLIST_SUB+=	CTF=""
Q2GAMES+=	ctf
.else
PLIST_SUB+=	CTF="@comment "
.endif

.if !defined(WITHOUT_QMASS)
PLIST_SUB+=	QMASS=""
Q2GAMES+=	qmass
.else
PLIST_SUB+=	QMASS="@comment "
.endif

.if defined(WITH_VANCTF)
PLIST_SUB+=	VANCTF=""
Q2GAMES+=	vanctf
.else
PLIST_SUB+=	VANCTF="@comment "
.endif

.if defined(WITH_MYSQL)
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
.if ${OSVERSION} < 800501
	${REINPLACE_CMD} -e 's,const struct,struct,' ${WRKSRC}/src/files.c
.endif
	${REINPLACE_CMD} -e 's,-ldl,,' ${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/quetoo ${PREFIX}/bin
.for g in ${Q2GAMES}
	@${MKDIR} ${LIBDIR}/${g}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${g}/.libs/game.so ${LIBDIR}/${g}
.endfor
.if !defined(WITHOUT_QMASS)
	@${MKDIR} ${DATADIR}/qmass/sound
	${INSTALL_DATA} ${WRKSRC}/data/qmass/sound/*.wav ${DATADIR}/qmass/sound
.if !defined(WITHOUT_VANCTF)
	@${MKDIR} ${DATADIR}/vanctf/maps
	${INSTALL_DATA} ${WRKSRC}/data/vanctf/maps/*.ent ${DATADIR}/vanctf/maps
	${INSTALL_DATA} ${WRKSRC}/data/vanctf/maps.lst ${DATADIR}/vanctf
.endif
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.   if !defined(WITHOUT_QMASS)
	@${MKDIR} ${DOCSDIR}/qmass
	${INSTALL_DATA} ${WRKSRC}/src/qmass/README ${DOCSDIR}/qmass
.   endif
.   if !defined(WITHOUT_VANCTF)
	@${MKDIR} ${DOCSDIR}/vanctf
	${INSTALL_DATA} ${WRKSRC}/src/vanctf/*E* ${DOCSDIR}/vanctf
.   endif
.endif

.include "${.CURDIR}/../quake2-data/Makefile.include"

.include <bsd.port.post.mk>
