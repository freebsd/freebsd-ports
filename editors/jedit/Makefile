# New ports collection makefile for:    jedit
# Date created:				22 June 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jedit
PORTVERSION=	3.0.2
CATEGORIES=	editors java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://members.nbci.com/romainguy/ \
		http://members.xoom.com/romainguy/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${PORTNAME}${PORTVERSION:S/.//g}install.jar swingall.jar
EXTRACT_ONLY=	

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper \
		${LOCALBASE}/etc/javavms:${PORTSDIR}/java/jre
RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper \
		${LOCALBASE}/etc/javavms:${PORTSDIR}/java/jre

USE_XLIB=	yes
NO_BUILD=	yes

do-configure:
	@${SED} "s|%%PREFIX%%|${PREFIX}|g ; s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${FILESDIR}/jedit.sh > ${WRKDIR}/jedit.sh

do-install:
	@${SED} "s|%%PREFIX%%|${PREFIX}| ; s|%%WRKDIR%%|${WRKDIR}|" ${FILESDIR}/instscript | \
		${SETENV} CLASSPATH=${DISTDIR}/${PORTNAME}${PORTVERSION:S/.//g}install.jar:${DISTDIR}/swingall.jar \
		${LOCALBASE}/bin/javavm installer.Install text
	@${INSTALL_DATA} ${DISTDIR}/swingall.jar ${PREFIX}/share/java/jedit
	@${INSTALL_SCRIPT} ${WRKDIR}/jedit.sh ${PREFIX}/bin/jedit

.include <bsd.port.mk>
