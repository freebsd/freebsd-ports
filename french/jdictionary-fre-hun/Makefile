# New ports collection makefile for:    jdictionary-fre-hun
# Date created:         20.06.2002
# Whom:                 janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	jdictionary-fre-hun
PORTVERSION=    1.0
PORTREVISION=	1
CATEGORIES=	french hungarian textproc
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=jdictionary
DISTFILES=	Smart_French_Hungarian-1_0.jar

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	JDictionary plugin: French-Hungarian dictionary

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper \
		${LOCALBASE}/etc/javavms:${PORTSDIR}/java/jdk13 \
		jdictionary:${PORTSDIR}/textproc/jdictionary

EXTRACT_CMD=    ${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=     ${WRKDIR}
NO_BUILD=y

do-install:
	@if [ ! -d ${PREFIX}/share/java/classes/jdictionary/Plugins ]; then \
		${MKDIR} ${PREFIX}/share/java/classes/jdictionary/Plugins; fi
	${CP} ${WRKDIR}/${DISTFILES} \
		${PREFIX}/share/java/classes/jdictionary/Plugins/

.include <bsd.port.mk>
