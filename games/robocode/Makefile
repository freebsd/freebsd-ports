# New ports collection makefile for:    robocode
# Date created:				10 September 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	robocode
PORTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	games java
MASTER_SITES=	ftp://dragon.adtech.internet.ibm.com/pub/robocode/ \
		http://robocode.alphaworks.ibm.com/
DISTNAME=	robocode-setup
EXTRACT_SUFX=	.jar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A game for learning Java[tm] programming language

BROKEN=		Does not build

USE_JAVA=	1.3+

JAVAVM=		${JAVA_HOME}/bin/java
JAVAJAR=	${JAVA_HOME}/bin/jar

USE_ZIP=	yes
USE_XLIB=	yes
RESTRICTED=	"Redistribution isn't permitted - see license for details"
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_SIZE=	yes

INSTFILES=	battles javadoc license.html robocode.ico \
		robocode.jar robots templates versions.txt

post-extract:
	@cd ${WRKSRC} && ${JAVAJAR} xf ${WRKSRC}/extract.jar

do-configure:
	@${SED} "s|%%PREFIX%%|${PREFIX}|g ; s|%%JAVAVM%%|${JAVAVM}|g" \
		${FILESDIR}/robocode.sh > ${WRKDIR}/robocode.sh

do-install:
	@${MKDIR} ${PREFIX}/share/java/robocode
	@cd ${WRKSRC} && ${TAR} -c -f - ${INSTFILES} | \
		${TAR} --unlink -x -f - -C ${PREFIX}/share/java/robocode
	@${INSTALL_SCRIPT} ${WRKDIR}/robocode.sh ${PREFIX}/bin/robocode

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
