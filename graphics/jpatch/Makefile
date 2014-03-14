# Created by: ijliao
# $FreeBSD$

PORTNAME=	jpatch
DISTVERSION=	0.4p1
PORTREVISION=	2
CATEGORIES=	graphics java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/JPatch%200.4%20PREVIEW%201
DISTNAME=	${PORTNAME}0_4preview1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A spline based 3D modeling tool

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}${DISTVERSION}

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar \
		bin/jpatch

SUB_FILES=	jpatch.sh

NO_STAGE=	yes
do-install:
	${INSTALL_DATA} ${WRKSRC}/jpatch.jar ${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/jpatch.sh ${PREFIX}/bin/jpatch

.include <bsd.port.mk>
