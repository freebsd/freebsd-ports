# New ports collection makefile for:	Quetoo
# Date created:				10 Apr 2006
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quetoo
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://jdolan.dyndns.org/jaydolan/files/ \
		http://freebsd.nsu.ru/distfiles/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Fast, stable, compatible, and secure Quake II client

USE_BZIP2=	yes
USE_SDL=	sdl
USE_GL=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		OPENGL_CFLAGS="${CPPFLAGS}" OPENGL_LIBS="${LDFLAGS}"
CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}

LIBDIR=		${PREFIX}/lib/${PORTNAME}
PLIST_SUB=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"

OPTIONS=	GAME		"Build a main game .so file (required)"	on \
		CTF		"Build the Capture The Flag modification" off \
		QMASS		"Build QMass deathmatch mod"		on \
		MYSQL		"Enable MySQL frag logging"		off \
		OPTIMIZED_CFLAGS "Enable extra optimization options"	off

.include <bsd.port.pre.mk>

.if defined(GCCVERSION)
.   if ${GCCVERSION} < 030000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-fbsd4
.   endif
.else
.   if ${OSVERSION} < 500035
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-fbsd4
.   endif
.endif

.if !defined(WITHOUT_GAME)
PLIST_SUB+=	GAME=""
Q2GAMES+=	baseq2
.else
PLIST_SUB+=	GAME="@comment "
Q2GAMES_NOT+=	baseq2
.endif

.if defined(WITH_CTF)
PLIST_SUB+=	CTF=""
Q2GAMES+=	ctf
.else
PLIST_SUB+=	CTF="@comment "
Q2GAMES_NOT+=	ctf
.endif

.if !defined(WITHOUT_QMASS)
CONFIGURE_ARGS+=	--enable-qmass
PLIST_SUB+=	QMASS=""
Q2GAMES+=	qmass
.else
PLIST_SUB+=	QMASS="@comment "
Q2GAMES_NOT+=	qmass
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-mysql
CONFIGURE_ENV+=	MYSQL_LIBS="-L${LOCALBASE}/lib/mysql -lmysqlclient" \
		MYSQL_CFLAGS="-I${LOCALBASE}/include"
.else
CONFIGURE_ARGS+=--without-mysql
.endif

.if !defined(WITH_OPTIMIZED_CFLAGS)
CONFIGURE_ARGS+=--disable-opt --disable-sse
.endif

post-extract: .SILENT
	${REINPLACE_CMD} -E 's,^(eval PKGDATADIR=).*$$,\1"${Q2DIR}",; \
		s,sdl-config,${SDL_CONFIG},' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's,-ldl,,' ${WRKSRC}/src/Makefile.in
	${REINPLACE_CMD} -e 's,alsa,sdl,' ${WRKSRC}/src/snd_ref.c
.for f in ${Q2GAMES_NOT}
	${REINPLACE_CMD} -i "" -Ee 's,^(SRC_SUBDIRS=".*)${f}(.*),\1\2,' \
		${WRKSRC}/configure
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/quetoo ${PREFIX}/bin/quetoo
	@${MKDIR} ${LIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/.libs/*.so ${LIBDIR}
.for g in ${Q2GAMES}
	@${MKDIR} ${LIBDIR}/${g}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${g}/.libs/game.so ${LIBDIR}/${g}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.   if !defined(WITHOUT_QMASS)
	${INSTALL_DATA} ${WRKSRC}/src/qmass/README ${DOCSDIR}/qmass-README
.   endif
.endif

.include "${.CURDIR}/../quake2-data/Makefile.include"

.include <bsd.port.post.mk>
