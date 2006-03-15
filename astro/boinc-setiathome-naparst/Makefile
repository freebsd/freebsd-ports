# New ports collection makefile for:	boinc-setiathome-naparst
# Date created:				14 March 2006
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	boinc-setiathome-naparst
PORTVERSION=	3.4
CATEGORIES=	astro
MASTER_SITES=	http://naparst.name/files/
DISTNAME=	setiathome_SSE-naparst-r${PORTVERSION}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Setiathome for BOINC, optimized by Harold Naparst

RUN_DEPENDS=	boinc_client:${PORTSDIR}/net/boinc-client

ONLY_FOR_ARCHS=	i386 amd64
USE_BZIP2=	yes
USE_LINUX=	yes

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

CONFLICTS=	boinc-setiathome-[0-9]*

# these must match settings in ${PORTSDIR}/net/boinc-client/Makefile
BOINC_USER?=	boinc
BOINC_GROUP?=	nobody
BOINC_HOME?=	/var/db/boinc

SETI_SITE=	setiathome.berkeley.edu
SETI_BINARY=	setiathome_SSE-naparst-r3.4

PLIST_SUB=	SETI_BINARY="${SETI_BINARY}" SETI_SITE=${SETI_SITE} \
		BOINC_HOME=${BOINC_HOME}

post-patch:
	@${BRANDELF} -t Linux ${WRKDIR}/${SETI_BINARY}

do-install:
	${INSTALL} -d -o ${BOINC_USER} -g ${BOINC_GROUP} ${BOINC_HOME}/projects
	${INSTALL} -d -o ${BOINC_USER} -g ${BOINC_GROUP} ${BOINC_HOME}/projects/${SETI_SITE}
	${INSTALL_DATA} -o ${BOINC_USER} -g ${BOINC_GROUP} ${WRKDIR}/app_info.xml ${BOINC_HOME}/projects/${SETI_SITE}
	${INSTALL_PROGRAM} -o ${BOINC_USER} -g ${BOINC_GROUP} ${WRKDIR}/${SETI_BINARY} ${BOINC_HOME}/projects/${SETI_SITE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
