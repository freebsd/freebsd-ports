# ex:ts=8
# Ports collection makefile for:	itext
# Date created:			Apr 2, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	itext
PORTVERSION=	1.02b
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.jar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Java-PDF Library

USE_JAVA=	1.2+
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	${WRKSRC}

PLIST_FILES=	${JAVAJARDIR:S,^${PREFIX}/,,}/${PORTNAME}.jar

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTFILES} ${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
