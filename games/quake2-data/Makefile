# New ports collection makefile for:	quake2-data
# Date created:				28 Sep 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	data
PORTVERSION=	3.20
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_IDSOFTWARE}
MASTER_SITE_SUBDIR=	quake2
PKGNAMEPREFIX=	${Q2PKGNAMEPREFIX}
DISTFILES=	${Q2FULL}
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Quake II data files

EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

OPTIONS=	CTF "Install the Capture The Flag mod data" on \
		SHAREWARE "Install demo version game data" off

DATADIR=	${Q2DIR}

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}

Q2FULL=		q2-3.20-x86-full.exe
Q2DEMO=		q2-314-demo-x86.exe
Q2CTF=		ctf/q2ctf150.zip

.include "Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITH_CTF) && !defined(WITH_SHAREWARE)
DISTFILES+=	${Q2CTF}
PLIST_SUB+=	CTF=""
.else
PLIST_SUB+=	CTF="@comment "
.endif

.if defined(WITH_SHAREWARE)
PLIST_SUB+=	FULL="@comment " \
		SHAREWARE=""
.else
PLIST_SUB+=	FULL="" \
		SHAREWARE="@comment "
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
.endif

.if defined(WITH_SHAREWARE) || !defined(NOPORTDOCS)
DISTFILES+=	${Q2DEMO}
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@${UNZIP_CMD} -q -d ${WRKDIR} \
		${DISTDIR}/${DIST_SUBDIR}/${Q2FULL} \
		baseq2/* -x *.dll
.if defined(WITH_SHAREWARE)
	@${RM} ${WRKDIR}/baseq2/pak[^0].pak
.endif
.if defined(WITH_CTF) && defined(WITHOUT_SHAREWARE)
	@${UNZIP_CMD} -aq -d ${WRKDIR}/ctf \
		${DISTDIR}/${DIST_SUBDIR}/${Q2CTF} \
		-x *.dll *.ico
.endif
.if !defined(NOPORTDOCS)
	@${UNZIP_CMD} -ajq -d ${WRKDIR}/DOCS \
		${DISTDIR}/${DIST_SUBDIR}/${Q2DEMO} \
		Install/Data/DOCS/*
.endif
.if defined(WITH_SHAREWARE)
	@${UNZIP_CMD} -jq -d ${WRKDIR}/baseq2 \
		${DISTDIR}/${DIST_SUBDIR}/${Q2DEMO} \
		Install/Data/baseq2/pak0.pak
.endif

do-install:
	@${MKDIR} ${DATADIR}
	@${CP} -R ${WRKSRC}/baseq2 ${DATADIR}
.if defined(WITHOUT_SHAREWARE)
	@${MKDIR} ${DATADIR}/rogue ${DATADIR}/xatrix
.endif
.if defined(WITH_CTF) && defined(WITHOUT_SHAREWARE)
	@${MKDIR} ${DATADIR}/ctf
.   for f in *.cfg *.pak
	@${INSTALL_DATA} ${WRKSRC}/ctf/${f} ${DATADIR}/ctf
.   endfor
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -R ${WRKSRC}/DOCS ${DOCSDIR}/manual
.   if defined(WITH_CTF) && defined(WITHOUT_SHAREWARE)
	@${MKDIR} ${DOCSDIR}/ctf
	@${INSTALL_DATA} ${WRKSRC}/ctf/*.txt ${DOCSDIR}/ctf
.   endif
.endif

post-install:
.if defined(WITHOUT_SHAREWARE)
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}
.endif

.include <bsd.port.post.mk>
