# New ports collection makefile for:	boinc-einsteinathome
# Date created:				20 February 2006
# Whom:					Rene Ladan <r.c.ladan@student.tue.nl>
# $FreeBSD$
#

PORTNAME=	boinc-einsteinathome
PORTVERSION=	4.61
CATEGORIES=	astro
MASTER_SITES=	http://einstein.phys.uwm.edu/app_test/FreeBSD/
DISTNAME=	albert_${PORTVERSION}_i386-unknown-freebsd
EXTRACT_SUFX=	.tgz

MAINTAINER=	r.c.ladan@gmail.com
COMMENT=	Einstein@Home for BOINC

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386 amd64

# Binary is built for 5.X :
.if ${OSVERSION} < 500000
IGNORE=		only supports FreeBSD 5.X and newer
.endif

.if ${OSVERSION} >= 600000
LIB_DEPENDS+=	c.5:${PORTSDIR}/misc/compat5x
.endif

RUN_DEPENDS+=	boinc_client:${PORTSDIR}/net/boinc-client

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

# these must match settings in ${PORTSDIR}/net/boinc-client/Makefile
BOINC_USER?=	boinc
BOINC_GROUP?=	nobody
BOINC_HOME?=	/var/db/boinc

EINSTEIN_SITE=	einstein.phys.uwm.edu
EINSTEIN_BINARY=${DISTNAME}

.if ${ARCH} == amd64 && ${OSVERSION} >= 600000
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
