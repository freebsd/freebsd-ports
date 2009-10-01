# New ports collection makefile for:	boinc-simap
# Date created:				29 May 2006
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	boinc-simap
PORTVERSION=	${SIMAP_VERSION}.${HMMER_VERSION}
PORTREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	http://boinc.bio.wzw.tum.de/boincsimap/download/
DISTNAME=	${SIMAP_BINARY} ${HMMER_BINARY}
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
SIMAP_BINARY=	simap_${SIMAP_VERSION}_${MACH}-pc-freebsd
SIMAP_VERSION=	5.10
HMMER_BINARY=	hmmer_${HMMER_VERSION}_${MACH}-pc-freebsd
HMMER_VERSION=	5.09

PLIST_SUB=	SIMAP_BINARY=${SIMAP_BINARY} HMMER_BINARY=${HMMER_BINARY} SIMAP_SITE=${SIMAP_SITE} \
		BOINC_HOME=${BOINC_HOME}

ONLY_FOR_ARCHS=	i386 amd64

OPTIONS=	SSE "SSE optimized app (warning! your CPU must support SSE)" off

.include <bsd.port.pre.mk>

.ifdef WITH_SSE
MACH=		i686
.else
MACH=		i386
.endif

.if ${ARCH} == amd64 && ${OSVERSION} < 800000
AMD64=		""
.else
AMD64=		"@comment "
.endif

SUB_FILES=	app_info.xml pkg-message
SUB_LIST=	SIMAP_BINARY=${SIMAP_BINARY} HMMER_BINARY=${HMMER_BINARY} SIMAP_APPVERSION=${SIMAP_VERSION:S/.//} HMMER_APPVERSION=${HMMER_VERSION:S/.//} AMD64=${AMD64}

.if ${OSVERSION} >= 700043
LIB_DEPENDS+=	c.6:${PORTSDIR}/misc/compat6x
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${SIMAP_BINARY} ${WRKDIR}
	@(cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${HMMER_BINARY} ${EXTRACT_AFTER_ARGS})

do-install:
	${INSTALL} -d -o ${BOINC_USER} -g ${BOINC_GROUP} ${BOINC_HOME}/projects
	${INSTALL} -d -o ${BOINC_USER} -g ${BOINC_GROUP} ${BOINC_HOME}/projects/${SIMAP_SITE}
	${INSTALL_DATA} -o ${BOINC_USER} -g ${BOINC_GROUP} ${WRKDIR}/app_info.xml ${BOINC_HOME}/projects/${SIMAP_SITE}
.for APP in ${DISTNAME}
	${INSTALL_PROGRAM} -o ${BOINC_USER} -g ${BOINC_GROUP} ${WRKDIR}/${APP} ${BOINC_HOME}/projects/${SIMAP_SITE}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
