# Created by: Alexander Botero-Lowry <alex@foxybanana.com>
# $FreeBSD$

PORTNAME=	jid3lib
PORTVERSION=	0.5.4
PORTREVISION=	2
CATEGORIES=	audio java
MASTER_SITES=	SF/javamusictag/${PORTNAME}/beta-dev6

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java ID3 Tag Library

USE_JAVA=	yes
USE_ANT=	yes

PLIST_FILES=	%%JAVAJARDIR%%/jid3lib.jar

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/jid3lib-${PORTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/jid3lib.jar

.include <bsd.port.mk>
