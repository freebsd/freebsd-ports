# New ports collection makefile for:	boinc-simap
# Date created:				29 May 2006
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	boinc-simap
PORTVERSION=	5.10
CATEGORIES=	biology
MASTER_SITES=	http://boinc.bio.wzw.tum.de/boincsimap/download/
DISTNAME=	simap_${PORTVERSION}_${MACH}-pc-freebsd
EXTRACT_SUFX=	#

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Similarity Matrix of Proteins project for BOINC

RUN_DEPENDS=	boinc_client:${PORTSDIR}/net/boinc-client

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
STRIP=		#

# these must match settings in ${PORTSDIR}/net/boinc-client/Makefile
BOINC_USER?=	boinc
BOINC_GROUP?=	nobody
BOINC_HOME?=	/var/db/boinc

SIMAP_SITE=	boinc.bio.wzw.tum.de_boincsimap
SIMAP_URL=	boinc.bio.wzw.tum.de/boincsimap
SIMAP_BINARY=	${DISTNAME}

PLIST_SUB=	SIMAP_BINARY=${SIMAP_BINARY} SIMAP_SITE=${SIMAP_SITE} \
		BOINC_HOME=${BOINC_HOME}

ONLY_FOR_ARCHS=	i386 amd64

OPTIONS=	SSE "SSE optimized app (warning! your CPU must support SSE)" off

.include <bsd.port.pre.mk>

.ifdef WITH_SSE
MACH=		i686
.else
MACH=		i386
.endif

.if ${ARCH} == amd64
AMD64=		""
.else
AMD64=		"@comment "
.endif

SUB_FILES=	app_info.xml pkg-message
SUB_LIST=	DISTNAME=${DISTNAME} APPVERSION=${PORTVERSION:S/.//} AMD64=${AMD64}

.if ${OSVERSION} < 600000
IGNORE=		only supports FreeBSD 6.X and newer
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKDIR}

do-install:
	${INSTALL} -d -o ${BOINC_USER} -g ${BOINC_GROUP} ${BOINC_HOME}/projects
	${INSTALL} -d -o ${BOINC_USER} -g ${BOINC_GROUP} ${BOINC_HOME}/projects/${SIMAP_SITE}
	${INSTALL_DATA} -o ${BOINC_USER} -g ${BOINC_GROUP} ${WRKDIR}/app_info.xml ${BOINC_HOME}/projects/${SIMAP_SITE}
	${INSTALL_PROGRAM} -o ${BOINC_USER} -g ${BOINC_GROUP} ${WRKDIR}/${SIMAP_BINARY} ${BOINC_HOME}/projects/${SIMAP_SITE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
