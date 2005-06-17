# New ports collection makefile for:	linux-ibm-jdk14
# Date created:				19 November 2002
# Whom:					Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}
PORTREVISION=	2
CATEGORIES=	java
PKGNAMEPREFIX=	linux-ibm-
DISTNAME=	IBMJava2-SDK-${JDK_VERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	IBM Java Development Kit 1.4 for Linux

FORBIDDEN=	Vulnerabilities in the browser plugin

RUN_DEPENDS=	${LOCALBASE}/bin/javavm:${PORTSDIR}/java/javavmwrapper

WRKSRC=		${WRKDIR}/${DISTNAME:S/-SDK//}
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///}
PLIST_SUB+=	PORTVERSION=${PORTVERSION}
PLIST_SUB+=	PORTREVISION=${PORTREVISION}

NO_BUILD=	yes
USE_REINPLACE=	yes
USE_LINUX=	yes
USE_XLIB=	yes
JDK_VERSION=	1.4.2
ONLY_FOR_ARCHS=	i386 amd64
APP_HOME?=	${PREFIX}/${PKGBASE}${PORTVERSION}

NO_CDROM=	"License does not allow distribution with fee"
RESTRICTED=	"Redistribution of repackaged binaries not permitted"

DOWNLOAD_URL=	https://www6.software.ibm.com/dl/lxdk/lxdk-p/

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
ECHO_MSG=/usr/bin/printf
IGNORE=:\n\
Because of licensing restrictions, you must manually fetch the IBM Java SDK\n\
${JDK_VERSION} for Linux archive (${DISTNAME}${EXTRACT_SUFX}).  Please access\n\
${DOWNLOAD_URL}, and select the\n\
\"Dev Kit for Linux\", ${JDK_VERSION}, for the \"32-bit xSeries (Intel Compat)\"\n\
platform.  After registration, download the archive and place it in\n\
${DISTDIR}.  Then run make again.\n
.endif

post-patch:
	${REINPLACE_CMD} -e "s:%%APP_HOME%%:${APP_HOME}:g" ${WRKSRC}/bin/java-rmi.cgi
	@${RM} -f ${WRKSRC}/bin/java-rmi.cgi.*

# XXX: This is missing a "${BRANDELF} -t Linux <executables>".

do-install:
	${MKDIR} ${APP_HOME}
	cd ${WRKSRC} && ${FIND} . \
		| ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} ${APP_HOME}
	${LOCALBASE}/bin/registervm "${APP_HOME}/bin/java # Linux-IBM-JDK${PORTVERSION}"

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
