# New ports collection makefile for:	quake-extras
# Date created:				10 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	extras
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://www.fuhquake.net/files/extras/:fq \
		http://gamefiles.blueyonder.co.uk/blueyondergames/quake/quakeworld/clients/fuhquake/addons/:fq \
		http://facelift.quakedev.com/download/:rev
PKGNAMEPREFIX=	${Q1PKGNAMEPREFIX}
DISTFILES=	#
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Addons for Quake

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

OPTIONS=	LITS "Coloured lighting (FuhQuake/JoeQuake)" on \
		REMODEL "High quality models" on \
		RETEXTURE_HQ "High quality textures (200MB)" off \
		RETEXTURE_OP "Optimal quality textures (50MB)" on \
		SKYBOXES "Skyboxes (sky replacement images)" on

DATADIR=	${Q1DIR}

LITSFILE=	fuhquake-lits.rar
SKINSFILE=	SKINSbmodels-48files-4-23-05.zip
SKYFILE=	fuhquake-skyboxes.zip

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_REMODEL) || !defined(WITHOUT_SKYBOXES)
EXTRACT_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
.endif

.if !defined(WITHOUT_LITS) || !defined(WITHOUT_RETEXTURE_OP) || \
    defined(WITH_RETEXTURE_HQ)
EXTRACT_DEPENDS+=	unrar:${PORTSDIR}/archivers/unrar
.endif

.if !defined(WITHOUT_LITS)
DISTFILES+=	${LITSFILE}:fq
PLIST_SUB+=	LITS=""
.else
PLIST_SUB+=	LITS="@comment "
.endif

.if !defined(WITHOUT_REMODEL)
DISTFILES+=	${SKINSFILE}:rev
PLIST_SUB+=	REMOD=""
.else
PLIST_SUB+=	REMOD="@comment "
.endif

.if defined(WITH_RETEXTURE_HQ)
TEXFILE=	textures-486files-8-20-05.rar
.elif !defined(WITHOUT_RETEXTURE_OP)
TEXFILE=	textures-486files-8-20-05-low.rar
.endif

.if !defined(WITHOUT_RETEXTURE_OP) || defined(WITH_RETEXTURE_HQ)
DISTFILES+=	${TEXFILE}:rev
PLIST_SUB+=	RETEX=""
.else
PLIST_SUB+=	RETEX="@comment "
.endif

.if !defined(WITHOUT_REMODEL) || !defined(WITHOUT_RETEXTURE_OP) || \
    defined(WITH_RETEXTURE_HQ)
PLIST_SUB+=	TEX_DIR=""
.else
PLIST_SUB+=	TEX_DIR="@comment "
.endif

.if !defined(WITHOUT_SKYBOXES)
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
.if !defined(WITHOUT_REMODEL) || !defined(WITHOUT_RETEXTURE_OP) || \
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
.if !defined(WITHOUT_RETEXTURE_OP) || defined(WITH_RETEXTURE_HQ)
	@cd ${WRKDIR}/textures && \
		unrar x ${DISTDIR}/${DIST_SUBDIR}/${TEXFILE} >/dev/null
.endif
.if !defined(WITHOUT_SKYBOXES)
	@cd ${WRKDIR} && ${UNZIP_CMD} -qo ${DISTDIR}/${DIST_SUBDIR}/${SKYFILE}
	@nwreckdum -d ${WRKDIR}/skyboxes -p ${WRKDIR}/pakX.pak >/dev/null
.endif

do-install:
.if !defined(WITHOUT_LITS)
	${MKDIR} ${DATADIR}/id1/lits
	${INSTALL_DATA} ${WRKSRC}/lits/* ${DATADIR}/id1/lits
.endif
.if !defined(WITHOUT_REMODEL) || !defined(WITHOUT_RETEXTURE_OP) || \
    defined(WITH_RETEXTURE_HQ)
	${CP} -R ${WRKSRC}/textures ${DATADIR}/id1
.endif
.if !defined(WITHOUT_REMODEL)
	cd ${DATADIR}/id1/textures && \
		${LN} -s . bmodels && ${LN} -s . progs
.endif
.if !defined(WITHOUT_SKYBOXES)
	${CP} -R ${WRKSRC}/skyboxes/* ${DATADIR}/id1
.endif

.include <bsd.port.post.mk>
