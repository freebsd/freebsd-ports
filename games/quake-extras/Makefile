# Created by: Alejandro Pulver <alepulver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	extras
PORTVERSION=	1.1
CATEGORIES=	games
MASTER_SITES=	http://gamefiles.virginmedia.com/blueyondergames/quake/quakeworld/clients/fuhquake/addons/:fq \
		http://facelift.quakedev.com/download/:remod,retex \
		http://shub-hub.com/files/textures_retexture_project/:retex \
		http://qrp.quakeonline.net/:retex
PKGNAMEPREFIX=	${Q1PKGNAMEPREFIX}
DISTFILES=	#
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Various add-ons for games of Quake/QuakeWorld and alike

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${Q1DIR}

LITSFILE=	fuhquake-lits.rar
SKINSFILE=	SKINSbmodels-48files-4-23-05.zip
SKYFILE=	fuhquake-skyboxes.zip

OPTIONS_DEFINE=	LITS REMODEL RETEXTURE_HQ RETEXTURE_LW SKYBOXES
OPTIONS_DEFAULT=	LITS REMODEL RETEXTURE_LW SKYBOXES

LITS_DESC=		Colored lighting (FuhQuake/JoeQuake based)
REMODEL_DESC=		High quality models
RETEXTURE_HQ_DESC=	High quality textures (200MB)
RETEXTURE_LW_DESC=	Low (still good) quality textures (15MB)
SKYBOXES_DESC=		Skyboxes (sky replacement images)

.include "${.CURDIR}/../quake-data/Makefile.include"
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MREMODEL} || ${PORT_OPTIONS:MSKYBOXES}
EXTRACT_DEPENDS+=	${UNZIP_CMD}:${PORTSDIR}/archivers/unzip
.endif

.if ${PORT_OPTIONS:MLITS}
EXTRACT_DEPENDS+=	unrar:${PORTSDIR}/archivers/unrar
.endif

.if ${PORT_OPTIONS:MLITS}
DISTFILES+=	${LITSFILE}:fq
PLIST_SUB+=	LITS=""
.else
PLIST_SUB+=	LITS="@comment "
.endif

.if ${PORT_OPTIONS:MREMODEL}
DISTFILES+=	${SKINSFILE}:remod
PLIST_SUB+=	REMOD=""
.else
PLIST_SUB+=	REMOD="@comment "
.endif

.if ${PORT_OPTIONS:MRETEXTURE_HQ}
TEXFILE=	qrp-maptextures-2007-10-06r2-7files.zip
TEX_EXT=	tga
.elif ${PORT_OPTIONS:MRETEXTURE_LW}
TEXFILE=	qrp-maptextures-2007-10-20r2-7files-low.zip
TEX_EXT=	jpg
.endif

.if ${PORT_OPTIONS:MRETEXTURE_LW} || ${PORT_OPTIONS:MRETEXTURE_HQ}
DISTFILES+=	${TEXFILE}:retex
PLIST_SUB+=	RETEX="" EXT="${TEX_EXT}"
.else
PLIST_SUB+=	RETEX="@comment "
.endif

.if ${PORT_OPTIONS:MREMODEL} || ${PORT_OPTIONS:MRETEXTURE_LW} || \
    ${PORT_OPTIONS:MRETEXTURE_HQ}
PLIST_SUB+=	TEX_DIR=""
.else
PLIST_SUB+=	TEX_DIR="@comment "
.endif

.if ${PORT_OPTIONS:MSKYBOXES}
DISTFILES+=	${SKYFILE}:fq
EXTRACT_DEPENDS+=	nwreckdum:${PORTSDIR}/archivers/nwreckdum
PLIST_SUB+=	SKYBOX=""
.else
PLIST_SUB+=	SKYBOX="@comment "
.endif

do-extract:
.if ${PORT_OPTIONS:MLITS}
	@${MKDIR} ${WRKDIR}/lits
	@cd ${WRKDIR}/lits && unrar x -y -idq \
		${DISTDIR}/${DIST_SUBDIR}/${LITSFILE}
.endif
.if ${PORT_OPTIONS:MREMODEL} || ${PORT_OPTIONS:MRETEXTURE_LW} || \
    ${PORT_OPTIONS:MRETEXTURE_HQ}
	@${MKDIR} ${WRKDIR}/textures
.endif
.if ${PORT_OPTIONS:MREMODEL}
	@cd ${WRKDIR}/textures && \
		${UNZIP_CMD} -qo ${DISTDIR}/${DIST_SUBDIR}/${SKINSFILE}
	@${RM} ${WRKDIR}/textures/readme.txt
# Make links for compatibility
	@cd ${WRKDIR}/textures && \
	for f in `${LS} | ${GREP} -E '[[:alnum:]]+_[[:digit:]]+'`; do \
		${LN} -s $$f `${ECHO_CMD} $$f | ${SED} -E -e 's/([[:alnum:]]+)_.+/\1/'`.mdl_`${ECHO_CMD} $$f | ${SED} -E -e 's/[[:alnum:]]+_(.+)/\1/'`; \
	done
.endif
.if ${PORT_OPTIONS:MRETEXTURE_LW} || ${PORT_OPTIONS:MRETEXTURE_HQ}
	@cd ${WRKDIR} && ${UNZIP_CMD} -qo \
		${DISTDIR}/${DIST_SUBDIR}/${TEXFILE} "*.pk3" && \
		${UNZIP_CMD} -qo *.pk3 && ${RM} *.pk3
	@cd ${WRKDIR}/textures && for tex in *.link; do ln -s `${CAT} $$tex` \
		`${ECHO_CMD} $$tex | ${SED} -e 's|\.link|.${TEX_EXT}|'`; done
.endif
.if ${PORT_OPTIONS:MSKYBOXES}
	@cd ${WRKDIR} && ${UNZIP_CMD} -qo ${DISTDIR}/${DIST_SUBDIR}/${SKYFILE}
	@nwreckdum -d ${WRKDIR}/skyboxes -p ${WRKDIR}/pakX.pak >/dev/null
.endif

do-install:
.if ${PORT_OPTIONS:MLITS}
	@${MKDIR} ${DATADIR}/id1/lits
	${INSTALL_DATA} ${WRKSRC}/lits/* ${DATADIR}/id1/lits
.endif
.if ${PORT_OPTIONS:MREMODEL} || ${PORT_OPTIONS:MRETEXTURE_LW} || \
    ${PORT_OPTIONS:MRETEXTURE_HQ}
	${CP} -a ${WRKSRC}/textures ${DATADIR}/id1
.endif
.if ${PORT_OPTIONS:MREMODEL}
	cd ${DATADIR}/id1/textures && ${LN} -s . bmodels && ${LN} -s . progs
.endif
.if ${PORT_OPTIONS:MSKYBOXES}
	${CP} -a ${WRKSRC}/skyboxes/* ${DATADIR}/id1
.endif

.include <bsd.port.mk>
