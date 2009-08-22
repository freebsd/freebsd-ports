# ex:ts=8
# Ports collection makefile for:	jmusic
# Date created:			Sep 15, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jmusic
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	audio java
MASTER_SITES=	SF/${PORTNAME}/jMusic_Stable/${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	Composition in Java

USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${JAVAJARDIR}/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jar ${JAVAJARDIR}/${PORTNAME}
	@${CP} -R ${WRKSRC}/inst ${JAVAJARDIR}/${PORTNAME}

.include <bsd.port.mk>
