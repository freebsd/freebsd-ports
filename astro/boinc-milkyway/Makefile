# New ports collection makefile for:	boinc-milkyway
# Date created:				8 August 2008
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	boinc-milkyway
PORTVERSION=	1.21
CATEGORIES=	astro
MASTER_SITES=	http://milkyway.cs.rpi.edu/milkyway/download/
DISTNAME=	astronomy_${PORTVERSION}_${ARCH}-unknown-freebsd

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Modelling the evolution of the Milkyway Galaxy

EXTRACT_SUFX=	#

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386 amd64

.if ${OSVERSION} >= 700000
LIB_DEPENDS+=	c.6:${PORTSDIR}/misc/compat6x
.endif

RUN_DEPENDS+=	boinc_client:${PORTSDIR}/net/boinc-client

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
STRIP=		#

# these must match settings in ${PORTSDIR}/net/boinc-client/Makefile
BOINC_USER?=	boinc
BOINC_GROUP?=	nobody
BOINC_HOME?=	/var/db/boinc

MILKYWAY_SITE=	milkyway.cs.rpi.edu_milkyway
MILKYWAY_URL=	milkyway.cs.rpi.edu/milkyway
MILKYWAY_BINARY=${DISTNAME}

.if ${ARCH} == amd64 && ${OSVERSION} >= 600000
AMD64=		""
.else
AMD64=		"@comment "
.endif

SUB_FILES=	pkg-message app_info.xml
SUB_LIST=	AMD64=${AMD64} MILKYWAY_VERSION=${PORTVERSION:S/.//} MILKYWAY_BINARY="${MILKYWAY_BINARY}"

PLIST_SUB=	MILKYWAY_BINARY="${MILKYWAY_BINARY}" MILKYWAY_SITE=${MILKYWAY_SITE} \
		BOINC_HOME=${BOINC_HOME}

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKDIR}

do-install:
	${INSTALL} -d -o ${BOINC_USER} -g ${BOINC_GROUP} ${BOINC_HOME}/projects
	${INSTALL} -d -o ${BOINC_USER} -g ${BOINC_GROUP} ${BOINC_HOME}/projects/${MILKYWAY_SITE}
	${INSTALL_DATA} -o ${BOINC_USER} -g ${BOINC_GROUP} ${WRKDIR}/app_info.xml ${BOINC_HOME}/projects/${MILKYWAY_SITE}
	${INSTALL_PROGRAM} -o ${BOINC_USER} -g ${BOINC_GROUP} ${WRKDIR}/${MILKYWAY_BINARY} ${BOINC_HOME}/projects/${MILKYWAY_SITE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
