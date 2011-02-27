# New ports collection makefile for:	quake-extras
# Date created:				10 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

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
COMMENT=	Addons for Quake

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

OPTIONS=	LITS "Coloured lighting (FuhQuake/JoeQuake based)" on \
		REMODEL "High quality models" on \
		RETEXTURE_HQ "High quality textures (200MB)" off \
		RETEXTURE_LW "Low (still good) quality textures (15MB)" on \
		SKYBOXES "Skyboxes (sky replacement images)" on

DATADIR=	${Q1DIR}

LITSFILE=	fuhquake-lits.rar
SKINSFILE=	SKINSbmodels-48files-4-23-05.zip
SKYFILE=	fuhquake-skyboxes.zip

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.pre.mk>

# FIXME: SKYBOXES option only enabled for i386, as the unpacking program
# "nwreckdum" fails when receiving SIGXFSZ on !i386 platforms.

.if !defined(WITHOUT_REMODEL) || \
    (!defined(WITHOUT_SKYBOXES) && ${ARCH} == "i386")
EXTRACT_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
.endif

.if !defined(WITHOUT_LITS)
EXTRACT_DEPENDS+=	unrar:${PORTSDIR}/archivers/unrar
.endif

.if !defined(WITHOUT_LITS)
DISTFILES+=	${LITSFILE}:fq
PLIST_SUB+=	LITS=""
.else
PLIST_SUB+=	LITS="@comment "
.endif

.if !defined(WITHOUT_REMODEL)
DISTFILES+=	${SKINSFILE}:remod
PLIST_SUB+=	REMOD=""
.else
PLIST_SUB+=	REMOD="@comment "
.endif

.if defined(WITH_RETEXTURE_HQ)
TEXFILE=	qrp-maptextures-2007-10-06r2-7files.zip
TEX_EXT=	tga
.elif !defined(WITHOUT_RETEXTURE_LW)
TEXFILE=	qrp-maptextures-2007-10-20r2-7files-low.zip
TEX_EXT=	jpg
.endif

.if !defined(WITHOUT_RETEXTURE_LW) || defined(WITH_RETEXTURE_HQ)
DISTFILES+=	${TEXFILE}:retex
PLIST_SUB+=	RETEX="" EXT="${TEX_EXT}"
.else
PLIST_SUB+=	RETEX="@comment "
.endif

.if !defined(WITHOUT_REMODEL) || !defined(WITHOUT_RETEXTURE_LW) || \
    defined(WITH_RETEXTURE_HQ)
PLIST_SUB+=	TEX_DIR=""
.else
PLIST_SUB+=	TEX_DIR="@comment "
.endif

.if !defined(WITHOUT_SKYBOXES) && ${ARCH} == "i386"
DISTFILES+=	${SKYFILE}:fq
EXTRACT_DEPENDS+=	nwreckdum:${PORTSDIR}/archivers/nwreckdum
PLIST_SUB+=	SKYBOX=""
.else
PLIST_SUB+=	SKYBOX="@comment "
.endif

do-extract:
.if !defined(WITHOUT_LITS)
	@${MKDIR} ${WRKDIR}/lits
	@cd ${WRKDIR}/lits && \
		unrar x ${DISTDIR}/${DIST_SUBDIR}/${LITSFILE} >/dev/null
.endif
.if !defined(WITHOUT_REMODEL) || !defined(WITHOUT_RETEXTURE_LW) || \
    defined(WITH_RETEXTURE_HQ)
	@${MKDIR} ${WRKDIR}/textures
.endif
.if !defined(WITHOUT_REMODEL)
	@cd ${WRKDIR}/textures && \
		${UNZIP_CMD} -qo ${DISTDIR}/${DIST_SUBDIR}/${SKINSFILE}
	@${RM} ${WRKDIR}/textures/readme.txt
# Make links for compatibility.
	@cd ${WRKDIR}/textures && \
	for f in `${LS} | ${GREP} -E '[[:alnum:]]+_[[:digit:]]+'`; do \
		${LN} -s $$f `${ECHO_CMD} $$f | ${SED} -E -e 's/([[:alnum:]]+)_.+/\1/'`.mdl_`${ECHO_CMD} $$f | ${SED} -E -e 's/[[:alnum:]]+_(.+)/\1/'`; \
	done
.endif
.if !defined(WITHOUT_RETEXTURE_LW) || defined(WITH_RETEXTURE_HQ)
	@cd ${WRKDIR} && \
	    ${UNZIP_CMD} -qo ${DISTDIR}/${DIST_SUBDIR}/${TEXFILE} "*.pk3" && \
	    ${UNZIP_CMD} -qo *.pk3 && ${RM} *.pk3
	@cd ${WRKDIR}/textures && for tex in *.link; do ln -s `${CAT} $$tex` \
	    `${ECHO_CMD} $$tex | ${SED} -e 's|\.link|.${TEX_EXT}|'`; done
.endif
.if !defined(WITHOUT_SKYBOXES) && ${ARCH} == "i386"
	@cd ${WRKDIR} && ${UNZIP_CMD} -qo ${DISTDIR}/${DIST_SUBDIR}/${SKYFILE}
	@nwreckdum -d ${WRKDIR}/skyboxes -p ${WRKDIR}/pakX.pak >/dev/null
.endif

do-install:
.if !defined(WITHOUT_LITS)
	${MKDIR} ${DATADIR}/id1/lits
	${INSTALL_DATA} ${WRKSRC}/lits/* ${DATADIR}/id1/lits
.endif
.if !defined(WITHOUT_REMODEL) || !defined(WITHOUT_RETEXTURE_LW) || \
    defined(WITH_RETEXTURE_HQ)
	${CP} -R ${WRKSRC}/textures ${DATADIR}/id1
.endif
.if !defined(WITHOUT_REMODEL)
	cd ${DATADIR}/id1/textures && \
		${LN} -s . bmodels && ${LN} -s . progs
.endif
.if !defined(WITHOUT_SKYBOXES) && ${ARCH} == "i386"
	${CP} -R ${WRKSRC}/skyboxes/* ${DATADIR}/id1
.endif

.include <bsd.port.post.mk>
