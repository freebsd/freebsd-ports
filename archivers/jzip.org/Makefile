# ex:ts=8
# Ports collection makefile for:	jzip.org
# Date created:			Dec 24, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jzip.org
PORTVERSION=	0.2.0
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jzipdotorg
DISTNAME=	${PORTNAME}${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A WinZip like program written in java

PLIST_FILES=	share/java/classes/jzip.org.jar
USE_ZIP=	yes
USE_JAVA=	1.2+
NEED_JAVAC=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}.${PORTVERSION}.src

do-build:
	@cd ${WRKSRC} && ${JAVAC} -d bin src/*.java && \
	 cd bin && ${JAR} cvfm jzip.org.jar manifest/MANIFEST.MF \
			i18n/*.properties jzipdotorg/*.class images/*.png

do-install:
	@${INSTALL_DATA} ${WRKSRC}/bin/${PORTNAME}.jar ${JAVAJARDIR}

.include <bsd.port.mk>
