# New ports collection makefile for:	linux-ibm-jdk
# Date created:				22 April 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}
PORTREVISION=	10 # SR7
CATEGORIES=	java
MASTER_SITES=	#
PKGNAMEPREFIX=	linux-ibm-
DISTNAME=	IBMJava2-SDK-131
EXTRACT_SUFX=	.tgz

MAINTAINER=	java@FreeBSD.org
COMMENT=	IBM Java Development Kit 1.3 for Linux

FORBIDDEN=	Vulnerabilities in the browser plugin

RUN_DEPENDS=	${LOCALBASE}/bin/javavm:${PORTSDIR}/java/javavmwrapper

WRKSRC=		${WRKDIR}/${DISTNAME:S/-SDK//}
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///}

NO_BUILD=	yes
USE_LINUX=	yes
USE_XLIB=	yes
JDK_VERSION=	1.3.1
LATEST_LINK=	linux-ibm-jdk13
ONLY_FOR_ARCHS=	i386 amd64
APP_HOME?=	${PREFIX}/${PKGBASE}${PORTVERSION}
LINUX_SH?=	${LINUXBASE}/bin/sh

NO_CDROM=	"License does not allow distribution with fee"
RESTRICTED=	"Redistribution of repackaged binaries not permitted"

DOWNLOAD_URL=	https://www6.software.ibm.com/dl/lxdk/lxdk-i?S_TACT=&S_CMP=&S_PKG=ia32ww&x=50&y=13

.if defined(WITH_JAPANESE_FONTS)
PLIST_SUB+=	JAPANESE=""
BUILD_DEPENDS+=	${X11BASE}/lib/X11/fonts/TrueType/wadalab-gothic.ttf:${PORTSDIR}/japanese/truetypefonts
RUN_DEPENDS+=	${X11BASE}/lib/X11/fonts/TrueType/wadalab-gothic.ttf:${PORTSDIR}/japanese/truetypefonts
.else
PLIST_SUB+=	JAPANESE="@comment "
.endif

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE=You must manually fetch the IBM Java SDK ${JDK_VERSION} for Linux archive (${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

post-patch:
	@for shfn in `${GREP} -r '^#!/bin/sh' ${WRKSRC}|${AWK} -F: '{print $$1}'`; do \
		if [ ! -h $$shfn ]; then \
			(${SED} -e 's:^#!/bin/sh:#!${LINUX_SH}:' $$shfn \
				> $$shfn.tmp && ${CAT} $$shfn.tmp > $$shfn \
				&& ${RM} -f $$shfn.tmp) \
		fi \
	done

# XXX: This is missing a "${BRANDELF} -t Linux <executables>".

do-install:
	${MKDIR} ${APP_HOME}
	cd ${WRKSRC} && ${FIND} . \
		| ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} ${APP_HOME}
	${LOCALBASE}/bin/registervm "${APP_HOME}/bin/java # Linux-IBM-JDK${PORTVERSION}_${PORTREVISION}"

post-install:
.if defined(WITH_JAPANESE_FONTS)
	${LN} -sf ${X11BASE}/lib/X11/fonts/TrueType/wa*ttf ${APP_HOME}/jre/lib/fonts/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
