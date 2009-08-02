# New ports collection makefile for:	jid3lib
# Date created:				11 Apr 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$

PORTNAME=	jid3lib
PORTVERSION=	0.5.4
PORTREVISION=	2
CATEGORIES=	audio java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	javamusictag

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java ID3 Tag Library

USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_ANT=	yes

PLIST_FILES=	%%JAVAJARDIR%%/jid3lib.jar

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/jid3lib.jar..."
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/dist/jid3lib-${PORTVERSION}.jar \
	${JAVAJARDIR}/jid3lib.jar
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.mk>
