# Created by: Martin Matuska <martin@tradex.sk> et al
# $FreeBSD$

PORTNAME=	utserver
PORTVERSION=	451
PORTREVISION=	5
CATEGORIES=	games linux
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/:p436 \
		ftp://ftp.wireplay.co.uk/pub/unrealtournament/server/:p436 \
		ftp://ftp.fh-niederrhein.de/pub/win9x/gamesup/ut/:p436 \
		http://www.utpg.org/patches/:p451
DISTFILES=	${MAINFILE}:p436 ${PATCH451FILE}:p451
DIST_SUBDIR=	linux-ut
EXTRACT_ONLY=	${MAINFILE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unreal Tournament Dedicated Server for Linux

OPTIONS_DEFINE=	BONUSPACKS
OPTIONS_DEFAULT=	BONUSPACKS
BONUSPACKS_DESC=	install the official bonus packs collection

USE_LINUX=	yes
USE_LINUX_APPS=	sdl12
NO_CDROM=	Size; the data set is much too big
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/ut-server
USE_RC_SUBR=	ucc

UTDIR=		ut-server
PLIST_SUB=	UTDIR="${UTDIR}/"
SUB_LIST=	UTDIR="${PREFIX}/${UTDIR}"
SUB_FILES=	pkg-message
MAINFILE=	ut-server-436.tar.gz
PATCH451FILE=	UTPGPatch451.tar.bz2
EXTRA_PATCHES=	${WRKDIR}/patch-ngstatsut

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBONUSPACKS}
MASTER_SITES+=	http://liflg.holarse.net/files/final/:pbonus
BONUSFILE=	unreal.tournament.official.bonus.pack.collection.run
DISTFILES+=	${BONUSFILE}:pbonus
PLIST_SUB+=	WITH_BONUSPACKS=""
.else
PLIST_SUB+=	WITH_BONUSPACKS="@comment "
.endif

pre-fetch:
.if exists(${DISTDIR}/${MAINFILE})
	@${MKDIR} ${_DISTDIR}
	@${MV} ${DISTDIR}/${MAINFILE} ${_DISTDIR}/
.endif
.if exists(${DISTDIR}/${PATCH451FILE})
	@${MKDIR} ${_DISTDIR}
	@${MV} ${DISTDIR}/${PATCH451FILE} ${_DISTDIR}/
.endif

pre-patch:
	@${SED} -e "s!%%LOCALBASE%%!${LOCALBASE}!" \
		-e "s!%%UTDIR%%!${PREFIX}/${UTDIR}!" \
		${FILESDIR}/template-patch-ngstatsut > \
		${WRKDIR}/patch-ngstatsut
.if ${PORT_OPTIONS:MBONUSPACKS}
	@${SED} -e '1,/exit \$$res/d' ${_DISTDIR}/${BONUSFILE} | \
		${GUNZIP_CMD} -q | ${TAR} xf - -C ${WRKDIR} -X ${FILESDIR}/excludefiles
.for file in bp1.tar.bz2 bp2.tar.bz2 bp3.tar.bz2 bp4.tar.bz2
	@${TAR} jx -C ${WRKSRC} -f ${WRKDIR}/${file}
.endfor
	@${MV} ${WRKDIR}/README.bonus.pack.collection ${WRKSRC}/Help
.endif
	@${TAR} jx -C ${WRKSRC} -X ${FILESDIR}/excludefiles \
		-f ${_DISTDIR}/${PATCH451FILE}
	@${RM} -f ${WRKSRC}/System/libSDL-1.1.so.0
# remove trailing ^M
	@${FIND} -E ${WRKSRC} -type f \
		-iregex ".*\.(bat|cfg|gam|htm|html|inf|ini|int|lst| \
		pl|pm|sc|sh|scr|txt|url|uhtm|inc|ver)" \
		-exec ${SH} -c "${SED} "s/`printf '\r'`//" '{}' \
		>${WRKDIR}/tmp.txt; ${MV} ${WRKDIR}/tmp.txt '{}'" \;
post-patch:
	@${FIND} -E ${WRKSRC} -type f -name '*.orig' -exec ${RM} '{}' \;

do-install:
	@${CP} -Rp ${WRKSRC}/ ${STAGEDIR}${PREFIX}/${UTDIR}

.include <bsd.port.mk>
