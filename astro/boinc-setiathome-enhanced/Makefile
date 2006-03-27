# New ports collection makefile for:	boinc-setiathome-enhanced
# Date created:				26 March 2006
# Whom:					Rene Ladan <r.c.ladan@student.tue.nl>
# $FreeBSD$
#

PORTNAME=	boinc-setiathome-enhanced
PORTVERSION=	5.05
CATEGORIES=	astro
MASTER_SITES=	http://www.lb.shuttle.de/apastron/boinc/
DISTNAME=	boinc5.2.14seti${PORTVERSION}freebsd-mmx

MAINTAINER=	r.c.ladan@student.tue.nl
COMMENT=	Setiathome Enhanced for BOINC

USE_BZIP2=	yes

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386 amd64
.if ${ARCH} == amd64
#amd64 builds 5.X compat libs as part of lib32 layer
#amd64 does not run, unless you libmap libpthread.so.1 to libc_r.so.5
.else
.if ${OSVERSION} >= 600000
LIB_DEPENDS+=	c.5:${PORTSDIR}/misc/compat5x
#also depends on libm.so.3, libstdc++.so.4, libpthread.so.1
.endif
.endif

RUN_DEPENDS+=	boinc_client:${PORTSDIR}/net/boinc-client

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

# these must match settings in ${PORTSDIR}/net/boinc-client/Makefile
BOINC_USER?=	boinc
BOINC_GROUP?=	nobody
BOINC_HOME?=	/var/db/boinc

SETI_SITE=	setiweb.ssl.berkeley.edu_beta
SETI_BINARY=	setiathome-5.5.i386-unknown-freebsd

PLIST_SUB=	SETI_BINARY="${SETI_BINARY}" SETI_SITE=${SETI_SITE} \
		BOINC_HOME=${BOINC_HOME}

do-install:
	${INSTALL} -d -o ${BOINC_USER} -g ${BOINC_GROUP} ${BOINC_HOME}/projects
	${INSTALL} -d -o ${BOINC_USER} -g ${BOINC_GROUP} ${BOINC_HOME}/projects/${SETI_SITE}
	${INSTALL_DATA} -o ${BOINC_USER} -g ${BOINC_GROUP} ${WRKDIR}/projects/${SETI_SITE}/app_info.xml ${BOINC_HOME}/projects/${SETI_SITE}
	${INSTALL_PROGRAM} -o ${BOINC_USER} -g ${BOINC_GROUP} ${WRKDIR}/projects/${SETI_SITE}/${SETI_BINARY} ${BOINC_HOME}/projects/${SETI_SITE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
