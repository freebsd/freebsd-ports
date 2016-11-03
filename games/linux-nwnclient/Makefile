# Created by: Erik Olson <erikolson@olsonexpress.com>
# $FreeBSD$

PORTNAME=	nwnclient
PORTVERSION=	1.69
PORTREVISION=	3
CATEGORIES=	games linux
MASTER_SITES=	http://na.llnet.bioware.cdn.ea.com/u/f/eagames/bioware/neverwinternights/updates/linux/${PORTVERSION:S/.//}/:CLIENT \
		http://nwdownloads.bioware.com/neverwinternights/linux/129/:ORIG \
		http://nwdownloads.bioware.com/neverwinternights/linux/gold/:GOLD \
		http://nwdownloads.bioware.com/neverwinternights/linux/161/:HOTU \
		http://home.roadrunner.com/~nwmovies/nwmovies/:NWMOVIES \
		http://www.radgametools.com/down/Bink/:BINK
PKGNAMEPREFIX=	linux-
DISTFILES=	${CLIENT_FILES} \
		${CLIENT_NWMOVIES}
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

MAINTAINER=	scf@FreeBSD.org
COMMENT=	Neverwinter Nights Linux (x86) Client

RUN_DEPENDS=	${LOCALBASE}/share/nwndata/docs/readme.txt:games/nwndata

NO_BUILD=	yes
RESTRICTED=	Distribution not allowed
USES=		linux
USE_LINUX=	dri sdl12 xorglibs
NWNDATADIR=	${LOCALBASE}/share/nwndata

OPTIONS_DEFINE=	NWMOVIES
NWMOVIES_DESC=	Support for movies using BinkPlayer

.include <bsd.port.options.mk>

# Client detection.  Currently, detects only original and Diamond editions.
.if exists(${LOCALBASE}/share/nwndata/xp2.key)
CLIENT_FILES=	nwclientgold.tar.gz:GOLD \
		nwclienthotu.tar.gz:HOTU \
		English_linuxclient169_xp2.tar.gz:CLIENT
.if ${PORT_OPTIONS:MNWMOVIES}
NWMOVIESFILE=	nwmovies-v4-public.20090223.080954.tar.gz
BINKPLAYERFILE=	BinkLinuxPlayer.zip
CLIENT_NWMOVIES=${NWMOVIESFILE}:NWMOVIES \
		${BINKPLAYERFILE}:BINK
USE_LINUX+=	mikmod sdlmixer
PLIST_SUB+=	NWMOVIES=""
.else
PLIST_SUB+=	NWMOVIES="@comment "
.endif
PLIST_SUB+=	DIAMOND="" ORIGINAL="@comment "
.else
CLIENT_FILES=	nwclient129.tar.gz:ORIG \
		English_linuxclient${PORTVERSION:S/.//}_orig.tar.gz:CLIENT
PLIST_SUB+=	NWMOVIES="@comment " DIAMOND="@comment " ORIGINAL=""
.endif

do-extract:
	${MKDIR} ${WRKSRC}
.for _distfile in ${CLIENT_FILES:C/:.*$//g} ${BINKPLAYERFILE}
	(cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${_DISTDIR}/${_distfile} ${EXTRACT_AFTER_ARGS})
.endfor
.if defined(BINKPLAYERFILE)
	(cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${_DISTDIR}/${NWMOVIESFILE} ${EXTRACT_AFTER_ARGS} \
		nwmovies/binklib.so nwmovies/libdis/libdisasm.so \
		nwmovies/nwmovies.so)
	(cd ${WRKSRC} && ${MV} BinkPlayer nwmovies)
.endif
	${RM} ${WRKSRC}/lib/libSDL* ${WRKSRC}/fixinstall ${WRKSRC}/nwn
	if [ -d ${WRKSRC}/SDL-1.2.5 ]; then \
		${RM} ${WRKSRC}/SDL-1.2.5/*; \
		${RMDIR} ${WRKSRC}/SDL-1.2.5; \
	fi
	@${FIND} ${WRKSRC} -type f -name ".*" -delete

do-configure:
	${SED} -e 's|%%NWNDATADIR%%|${NWNDATADIR}|' \
		-e 's|%%NWNCLIENTDIR%%|${DATADIR}|' \
		<${FILESDIR}/nwn.sh >${WRKDIR}/nwn

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	(cd ${STAGEDIR}${DATADIR} && ${CHMOD} 0755 dmclient nwmain nwserver)
.if defined(BINKPLAYERFILE)
	(cd ${STAGEDIR}${DATADIR} && ${CHMOD} 0755 nwmovies/BinkPlayer)
	(cd ${STAGEDIR}${DATADIR}/nwmovies && ${LN} -s /compat/linux/usr/lib/libX11.so.6 libX11.so)
	${INSTALL_SCRIPT} ${FILESDIR}/nwmovies.pl ${STAGEDIR}${DATADIR}
.endif
	${INSTALL_SCRIPT} ${WRKDIR}/nwn ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
