# New ports collection makefile for:	eclipse-drjava
# Date created:		2006-04-14
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	drjava
PORTVERSION=	0.9.8
PORTREVISION=	5
CATEGORIES=	java devel
MASTER_SITES=	SF/${PORTNAME}/3.%20DrJava%20Eclipse%20Plug-in/${PORTNAME}-eclipse-${PORTVERSION}
PKGNAMEPREFIX=	eclipse-
DISTNAME=	drjava-eclipse-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	DrJava plugin for Eclipse

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_JAVA=	yes
USE_ZIP=	yes

JAVA_VERSION=	1.4+
JAVA_OS=	native

DATADIR=	${PREFIX}/lib/eclipse/plugins

EPLUGIN_ID=	edu.rice.cs.drjava
EPLUGIN_VER=	${PORTVERSION}

FIND_HERE=	${EPLUGIN_ID}_${EPLUGIN_VER}
FIND_DIRS=	-type d
FIND_DATA=	-type f -not \( -name "README" -or -name "LICENSE" \)

PLIST_SUB+=	EPLUGINID=${EPLUGIN_ID} EPLUGINVER="${PORTVERSION}" \
		PORTVERSION=${PORTVERSION}

do-install:
	cd ${WRKDIR} && ${FIND} ${FIND_HERE} ${FIND_DIRS} -exec ${MKDIR} ${DATADIR}/{} \;
	cd ${WRKDIR} && ${FIND} ${FIND_HERE} ${FIND_DATA} -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;

.include <bsd.port.mk>
