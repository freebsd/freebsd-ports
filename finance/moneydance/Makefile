# New ports collection makefile for:	moneydance
# Date created:		27 Feb 2000
# Whom:			Sean Reilly <sreilly@seanreilly.com>
#
# $FreeBSD$
#

PORTNAME=	moneydance
PORTVERSION=	2.0.4
CATEGORIES=	deskutils
MASTER_SITES=	ftp://ftp.moneydance.net/pub/packages/

MAINTAINER=	sreilly@seanreilly.com

RUN_DEPENDS=	${LOCALBASE}/jdk1.1.8/bin/java:${PORTSDIR}/java/jdk

WRKSRC=		${WRKDIR}/moneydance
NO_BUILD=	YES
MDSUBDIR=	moneydance
PLIST_SUB=	MDSUBDIR=${MDSUBDIR}

JDIR=		${PREFIX}/jdk1.1.8
MDDIR=		${PREFIX}/${MDSUBDIR}

do-install:
	${MKDIR} ${PREFIX}/${MDSUBDIR}
	(cd ${WRKSRC} && tar -c -f - .) \
		| (cd ${PREFIX}/${MDSUBDIR} && tar fx -)
	${ECHO} "#!/bin/sh" > ${PREFIX}/bin/moneydance
	${ECHO} "exec ${JDIR}/bin/java -classpath ${JDIR}/lib/classes.zip:${MDDIR}/moneydance.jar:${MDDIR}/license.jar:${MDDIR}/swingall.jar Moneydance" >> ${PREFIX}/bin/moneydance
	${CHMOD} 755 ${PREFIX}/bin/moneydance

.include <bsd.port.mk>
