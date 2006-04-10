# New ports collection makefile for:	Quetoo
# Date created:				10 Apr 2006
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quetoo
PORTVERSION=	0.3.3
CATEGORIES=	games
MASTER_SITES=	http://jdolan.dyndns.org/jaydolan/files/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Fast, stable, compatible, and secure Quake II engine

USE_BZIP2=	yes
USE_SDL=	sdl
USE_GL=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include \
		${PTHREAD_CFLAGS}" LDFLAGS="-L${LOCALBASE}/lib \
		-L${X11BASE}/lib ${PTHREAD_LIBS}" \
		OPENGL_CFLAGS="-I${X11BASE}/include" \
		OPENGL_LIBS="-L${X11BASE}/lib" \
		MYSQL_LIBS="-L${LOCALBASE}/lib/mysql -lmysqlclient" \
		MYSQL_CFLAGS="-I${LOCALBASE}/include"

LIBDIR=		${PREFIX}/lib/${PORTNAME}
PLIST_SUB+=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"

OPTIONS=	QMASS		"Build QMass deathmatch mod"		on \
		MYSQL		"Enable MySQL frag logging"		off \
		OPTIMIZED_CFLAGS "Enable extra optimization options"	off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_QMASS)
Q2GAMES=	baseq2 ctf qmass
CONFIGURE_ARGS+=	--enable-qmass
PLIST_SUB+=	QMASS=""
.else
Q2GAMES=	baseq2 ctf
PLIST_SUB+=	QMASS="@comment "
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql
.endif

.if !defined(WITH_OPTIMIZED_CFLAGS)
CONFIGURE_ARGS+=	--disable-opt --disable-sse
.endif

post-extract: .SILENT
	${REINPLACE_CMD} -E 's,^(eval PKGDATADIR=).*$$,\1"${Q2DIR}",; \
		s,-ldl,,; s, -lGL,,' ${WRKSRC}/configure
.if !defined(WITH_MYSQL)
	${REINPLACE_CMD} '22266,22268d' ${WRKSRC}/configure
.else
	${REINPLACE_CMD} 's,src$$,& @MYSQL_CFLAGS@,' \
		${WRKSRC}/src/qmass/Makefile.in
.endif
	${REINPLACE_CMD} 's,alsa,sdl,' ${WRKSRC}/src/snd_dma.c

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
