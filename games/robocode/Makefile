# New ports collection makefile for:    robocode
# Date created:				10 September 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	robocode
PORTVERSION=	1.0
CATEGORIES=	games java
MASTER_SITES=	ftp://dragon.adtech.internet.ibm.com/pub/robocode/
DISTNAME=	robocode-setup-${PORTVERSION}
EXTRACT_SUFX=	.jar

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	${JAVAVM}:${PORTSDIR}/java/linux-sun-jdk13
RUN_DEPENDS=	${JAVAVM}:${PORTSDIR}/java/linux-sun-jdk13

JDK13DIR?=	${LOCALBASE}/linux-sun-jdk1.3.1
JAVAVM=		${JDK13DIR}/bin/java
JAVAJAR=	${JDK13DIR}/bin/jar

USE_ZIP=	yes
USE_XLIB=	yes
RESTRICTED=	"Redistribution isn't permitted - see license for details"
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

INSTFILES=	battles javadoc license.html robocode.ico \
		robocode.jar robots templates versions.txt

.if defined(BATCH) || defined(PACKAGE_BUILDING)
IGNORE=		"You can not legally redistribute package"
.endif

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
