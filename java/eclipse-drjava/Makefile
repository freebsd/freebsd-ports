# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	drjava
PORTVERSION=	0.9.8
PORTREVISION=	6
CATEGORIES=	java devel
MASTER_SITES=	SF/${PORTNAME}/3.%20DrJava%20Eclipse%20Plug-in/${PORTNAME}-eclipse-${PORTVERSION}
PKGNAMEPREFIX=	eclipse-
DISTNAME=	drjava-eclipse-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	DrJava plugin for Eclipse

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:java/eclipse

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_JAVA=	yes

JAVA_VERSION=	1.6+
JAVA_OS=	native

DATADIR=	${PREFIX}/lib/eclipse/plugins

EPLUGIN_ID=	edu.rice.cs.drjava
EPLUGIN_VER=	${PORTVERSION}

FIND_HERE=	${EPLUGIN_ID}_${EPLUGIN_VER}
FIND_COND=	-not ( -name README -or -name LICENSE )

PLIST_SUB+=	EPLUGINID=${EPLUGIN_ID} EPLUGINVER="${PORTVERSION}" \
		PORTVERSION=${PORTVERSION}

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${FIND_HERE} ${STAGEDIR}${DATADIR} "${FIND_COND}"

.include <bsd.port.mk>
