# New ports collection makefile for:    jedit
# Date created:		22 June 2000
# Whom:			Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jedit
PORTVERSION=	2.4.2
CATEGORIES=	editors java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://members.xoom.com/romainguy/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${PORTNAME}-${PORTVERSION}.jar swingall.jar
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.jar

MAINTAINER=	sobomax@FreeBSD.org

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper \
		${LOCALBASE}/etc/javavms:${PORTSDIR}/java/jre

USE_ZIP=	yes
USE_XLIB=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-configure:
	@${SED} "s|%%PREFIX%%|${PREFIX}|g ; s|%%LOCALBASE%%|${LOCALBASE}|g" \
		< ${FILESDIR}/jedit.sh > ${WRKDIR}/jedit.sh

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/jedit.sh ${PREFIX}/bin/jedit
	@${MKDIR} ${PREFIX}/share/java/jedit
	@${INSTALL_DATA} ${DISTDIR}/swingall.jar ${PREFIX}/share/java/jedit
	@(cd ${WRKSRC}/jEdit && ${TAR} -c -f - .) \
		| (cd ${PREFIX}/share/java/jedit && ${TAR} --unlink -x -f -)

.include <bsd.port.mk>
