# Created by: ijliao
# $FreeBSD$

PORTNAME=	jpatch
DISTVERSION=	0.4p1
PORTREVISION=	3
CATEGORIES=	graphics java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/JPatch%200.4%20PREVIEW%201
DISTNAME=	${PORTNAME}0_4preview1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Spline based 3D modeling tool

USES=		zip
USE_JAVA=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}${DISTVERSION}

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar \
		bin/jpatch

SUB_FILES=	jpatch.sh

do-install:
	${INSTALL_DATA} ${WRKSRC}/jpatch.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/jpatch.sh ${STAGEDIR}${PREFIX}/bin/jpatch

.include <bsd.port.mk>
