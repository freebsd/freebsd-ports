# New ports collection makefile for:    robocode
# Date created:				10 September 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	robocode
PORTVERSION=	1.0.7
CATEGORIES=	games java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=robocode
DISTNAME=	${PORTNAME}-setup-${PORTVERSION}
EXTRACT_SUFX=	.jar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A game for learning Java[tm] programming language

USE_JAVA=	yes
JAVA_VERSION=	1.3+
JAVA_EXTRACT=	yes
JAVA_RUN=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

USE_ZIP=	yes
USE_XLIB=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

INSTFILES=	battles javadoc license robocode.ico \
		robocode.jar robots templates versions.txt

SUB_FILES=	robocode.sh

post-extract:
	@cd ${WRKSRC} && ${JAR} xf ${WRKSRC}/extract.jar

do-install:
	@cd ${WRKSRC} && \
		${FIND} ${INSTFILES} -type d -exec ${MKDIR} ${DATADIR}/{} \;
	@cd ${WRKSRC} && \
		${FIND} ${INSTFILES} -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
	@${INSTALL_SCRIPT} ${WRKDIR}/robocode.sh ${PREFIX}/bin/robocode

.include <bsd.port.mk>
