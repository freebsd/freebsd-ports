PORTNAME=	nwnclient
PORTVERSION=	1.69
PORTREVISION=	6
CATEGORIES=	games linux
MASTER_SITES=	${NWN_SITE_1}${PORTVERSION:S/.//}/:CLIENT \
		${NWN_SITE_2}${PORTVERSION:S/.//}/:CLIENT \
		${NWN_SITE_1}:ORIG,GOLD,HOTU \
		${NWN_SITE_2}:ORIG,GOLD,HOTU
PKGNAMEPREFIX=	linux-
DISTFILES=	${CLIENT_FILES}
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}
EXTRACT_ONLY=	${DISTFILE_NWMOVIES}

MAINTAINER=	scf@FreeBSD.org
COMMENT=	Neverwinter Nights Linux (x86) Client
WWW=		https://nwn.fandom.com/wiki/Neverwinter_Nights

# Converted from RESTRICTED
LICENSE=	nwnclient
LICENSE_NAME=	nwnclient
LICENSE_TEXT=	Distribution not allowed
LICENSE_PERMS=	auto-accept

# NOTE:  nwndata is not actually used to fetch anything.  Since nwndata
# determines the version of the client, force it to be installed prior to
# poudriere performing its placement of DISTFILES into /portdistfiles.
NWNDATA_DEPENDS=${LOCALBASE}/share/nwndata/docs/readme.txt:games/nwndata
FETCH_DEPENDS=	${NWNDATA_DEPENDS}
BUILD_DEPENDS=	${NWNDATA_DEPENDS}
RUN_DEPENDS=	${NWNDATA_DEPENDS}

NO_BUILD=	yes
USES=		linux
USE_LINUX=	dri sdl12-extralibs xorglibs

OPTIONS_DEFINE=	NWMOVIES

NWMOVIES_DESC=		In-game support for Bink format movies
NWMOVIES_RUN_DEPENDS=	mpv:multimedia/mpv
USE_GITHUB=	nodefault
GH_ACCOUNT=	nwnlinux:NWMOVIES
GH_PROJECT=	nwmovies:NWMOVIES
GH_TAGNAME=	v1.0:NWMOVIES

.include <bsd.port.options.mk>

NWN_SITE_1=	http://na.llnet.bioware.cdn.ea.com/u/f/eagames/bioware/neverwinternights/updates/linux/
NWN_SITE_2=	http://lvlt.bioware.cdn.ea.com/bioware/u/f/eagames/bioware/neverwinternights/updates/linux/

SUB_FILES=	nwn
SUB_LIST=	LINUXBASE=${LINUXBASE} NWNCLIENTDIR=${DATADIR} \
		NWNDATADIR=${LOCALBASE}/share/nwndata

# Client detection.  Currently, detects only original and Diamond editions.
.if exists(${LOCALBASE}/share/nwndata/xp2.key)
CLIENT_FILES=	nwclientgold.tar.gz:GOLD \
		nwclienthotu.tar.gz:HOTU \
		English_linuxclient169_xp2.tar.gz:CLIENT
.if ${PORT_OPTIONS:MNWMOVIES}
NWMOVIESFILES=	nwmovies/libdis/libdisasm.so \
		nwmovies/nwmovies.so
SUB_FILES+=	nwmovies.sh
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

post-extract:
	${MKDIR} ${WRKSRC}
.for _distfile in ${CLIENT_FILES:C/:.*$//g}
	(cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${_DISTDIR}/${_distfile} ${EXTRACT_AFTER_ARGS})
.endfor
	${RM} ${WRKSRC}/lib/libSDL* ${WRKSRC}/fixinstall ${WRKSRC}/nwn
	if [ -d ${WRKSRC}/SDL-1.2.5 ]; then \
		${RM} ${WRKSRC}/SDL-1.2.5/*; \
		${RMDIR} ${WRKSRC}/SDL-1.2.5; \
	fi
	@${FIND} ${WRKSRC} -type f -name ".*" -delete

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	(cd ${STAGEDIR}${DATADIR} && ${CHMOD} 0755 dmclient nwmain nwserver)
.if !empty(PORT_OPTIONS:MNWMOVIES)
	${MKDIR} ${STAGEDIR}${DATADIR}/nwmovies/libdis
.for _distfile in ${NWMOVIESFILES}
	${INSTALL_DATA} ${WRKSRC_NWMOVIES}/${_distfile} \
		${STAGEDIR}${DATADIR}/${_distfile}
.endfor
	(cd ${STAGEDIR}${DATADIR}/nwmovies && \
		${LN} -s /compat/linux/usr/lib/libX11.so.6 libX11.so)
	${INSTALL_SCRIPT} ${WRKDIR}/nwmovies.sh ${STAGEDIR}${DATADIR}
.endif
	${INSTALL_SCRIPT} ${WRKDIR}/nwn ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
