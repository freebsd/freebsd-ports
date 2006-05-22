# New ports collection makefile for:	boinc-setiathome-enhanced
# Date created:				26 March 2006
# Whom:					Rene Ladan <r.c.ladan@student.tue.nl>
# $FreeBSD$
#

PORTNAME=	boinc-setiathome-enhanced
PORTVERSION=	5.12
CATEGORIES=	astro
MASTER_SITES=	http://www.lb.shuttle.de/apastron/boinc/
DISTNAME=	seti${PORTVERSION}freebsd-i386

MAINTAINER=	r.c.ladan@gmail.com
COMMENT=	Setiathome Enhanced for BOINC

USE_BZIP2=	yes

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386 amd64

.if ${OSVERSION} >= 600000
LIB_DEPENDS+=	c.5:${PORTSDIR}/misc/compat5x
#also depends on libm.so.3, libstdc++.so.4, libpthread.so.1
.endif

RUN_DEPENDS+=	boinc_client:${PORTSDIR}/net/boinc-client

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

# these must match settings in ${PORTSDIR}/net/boinc-client/Makefile
BOINC_USER?=	boinc
BOINC_GROUP?=	nobody
BOINC_HOME?=	/var/db/boinc

SETI_SITE=	setiathome.berkeley.edu
SETI_BINARY=	setiathome-${PORTVERSION}.i386-unknown-freebsd

PLIST_SUB=	SETI_BINARY="${SETI_BINARY}" SETI_SITE=${SETI_SITE} \
		BOINC_HOME=${BOINC_HOME}

do-install:
	${INSTALL} -d -o ${BOINC_USER} -g ${BOINC_GROUP} ${BOINC_HOME}/projects
	${INSTALL} -d -o ${BOINC_USER} -g ${BOINC_GROUP} ${BOINC_HOME}/projects/${SETI_SITE}
	${INSTALL_PROGRAM} -o ${BOINC_USER} -g ${BOINC_GROUP} ${WRKDIR}/${SETI_BINARY} ${BOINC_HOME}/projects/${SETI_SITE}
.for file in app_info.xml AUTHORS CHANGES COPYING COPYRIGHT README
	${INSTALL_DATA} -o ${BOINC_USER} -g ${BOINC_GROUP} ${WRKDIR}/${file} ${BOINC_HOME}/projects/${SETI_SITE}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
