# ex:ts=8
# Ports collection makefile for:	jcommon
# Date created:			Nov 11, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jcommon
PORTVERSION=	0.8.8
CATEGORIES=	java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jfreechart

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collection of useful classes used by JFreeChart and JFreeReport

PLIST_FILES=	share/java/classes/jcommon.jar
USE_JAVA=	1.2+
NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
