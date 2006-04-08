# New ports collection makefile for:	boinc-einsteinathome
# Date created:				20 February 2006
# Whom:					Rene Ladan <r.c.ladan@student.tue.nl>
# $FreeBSD$
#

PORTNAME=	boinc-einsteinathome
PORTVERSION=	0.40
CATEGORIES=	astro
MASTER_SITES=	http://einstein.phys.uwm.edu/app_test/FreeBSD/
DISTNAME=	albert_${PORTVERSION}_i386-unknown-freebsd
EXTRACT_SUFX=	.tgz

MAINTAINER=	r.c.ladan@gmail.com
COMMENT=	Einstein@Home for BOINC

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386 amd64
# Binary is built on 4.9 :
.if ${OSVERSION} >= 500000
.if ${ARCH} == "amd64"
RUN_DEPENDS+=	compat4x-i386>0:${PORTSDIR}/misc/compat4x
.else
LIB_DEPENDS+=	c_r.4:${PORTSDIR}/misc/compat4x
.endif
# also depends on libm.so.2
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
