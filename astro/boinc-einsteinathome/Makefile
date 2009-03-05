# New ports collection makefile for:	boinc-einsteinathome
# Date created:				20 February 2006
# Whom:					Rene Ladan <r.c.ladan@student.tue.nl>
# $FreeBSD$
#

PORTNAME=	boinc-einsteinathome
PORTVERSION=	4.18
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	astro
MASTER_SITES=	http://einstein.phys.uwm.edu/app_test/FreeBSD/
DISTNAME=	einstein_S5R3_${PORTVERSION}_i386-unknown-freebsd

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Search for gravitational waves, a distributed computing project

LIB_DEPENDS=	c.5:${PORTSDIR}/misc/compat5x
RUN_DEPENDS=	boinc_client:${PORTSDIR}/net/boinc-client

ONLY_FOR_ARCHS=	i386 amd64

IGNORE=		is out of work units.  No FreeBSD app exists for current batch of work

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
STRIP=		#

# these must match settings in ${PORTSDIR}/net/boinc-client/Makefile
BOINC_USER?=	boinc
BOINC_GROUP?=	nobody
BOINC_HOME?=	/var/db/boinc

EINSTEIN_SITE=	einstein.phys.uwm.edu
EINSTEIN_BINARY=${DISTNAME}

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
AMD64=		""
.else
AMD64=		"@comment "
.endif

SUB_FILES=	pkg-message
SUB_LIST=	AMD64=${AMD64}

PLIST_SUB=	EINSTEIN_BINARY="${EINSTEIN_BINARY}" EINSTEIN_SITE=${EINSTEIN_SITE} \
		BOINC_HOME=${BOINC_HOME}

do-install:
	${INSTALL} -d -o ${BOINC_USER} -g ${BOINC_GROUP} ${BOINC_HOME}/projects
	${INSTALL} -d -o ${BOINC_USER} -g ${BOINC_GROUP} ${BOINC_HOME}/projects/${EINSTEIN_SITE}
	${INSTALL_DATA} -o ${BOINC_USER} -g ${BOINC_GROUP} ${WRKDIR}/projects/${EINSTEIN_SITE}/app_info.xml ${BOINC_HOME}/projects/${EINSTEIN_SITE}
	${INSTALL_PROGRAM} -o ${BOINC_USER} -g ${BOINC_GROUP} ${WRKSRC}/projects/${EINSTEIN_SITE}/${EINSTEIN_BINARY} ${BOINC_HOME}/projects/${EINSTEIN_SITE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
