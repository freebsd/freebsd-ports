# New ports collection makefile for:	obfuscatejs
# Date created:		2006-04-21
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	obfuscatejs
PORTVERSION=	0.3.5
CATEGORIES=	devel java
MASTER_SITES=	http://nivi.interfree.it/distfiles/${DIST_SUBDIR}/ \
		http://tools.2vi.nl/
DISTNAME=	consyntools
EXTRACT_SUFX=	.jar
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A JavaScript code obfuscator

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+

SUB_FILES=	${PORTNAME}
SUB_LIST=	OBFUSCATEJSJAR=${DATADIR}/${OBFUSCATEJSJAR}

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

OBFUSCATEJSJAR=	${DISTNAME}${EXTRACT_SUFX}

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${OBFUSCATEJSJAR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
