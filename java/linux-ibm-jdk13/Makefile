# New ports collection makefile for:	linux-ibm-jdk
# Date created:				22 April 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}
PORTREVISION=	2 # cxia32131-20020622
CATEGORIES=	java
MASTER_SITES=	#
PKGNAMEPREFIX=	linux-ibm-
DISTNAME=	IBMJava2-SDK-131
EXTRACT_SUFX=	.tgz

MAINTAINER=	znerd@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/bin/javavm:${PORTSDIR}/java/javavmwrapper
RUN_DEPENDS=	${LOCALBASE}/bin/javavm:${PORTSDIR}/java/javavmwrapper

WRKSRC=		${WRKDIR}/${DISTNAME:S/-SDK//}
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///}

NO_BUILD=	yes
USE_LINUX=	yes
JDK_VERSION=	1.3.1
ONLY_FOR_ARCHS=	i386
APP_HOME?=	${PREFIX}/${PKGBASE}${PORTVERSION}
LINUX_SH?=	${LINUXBASE}/bin/sh

NO_CDROM=	"License does not allow distribution with fee"
RESTRICTED=	"Redistribution of repackaged binaries not permitted"

DOWNLOAD_URL=	http://www6.software.ibm.com/dl/dklx130/dklx130-i?S_PKG=ia32ww

.if defined(WITH_JAPANESE_FONTS)
PLIST_SUB+=	JAPANESE=""
BUILD_DEPENDS+=	${X11BASE}/lib/X11/fonts/TrueType/wadalab-gothic.ttf:${PORTSDIR}/japanese/truetypefonts
RUN_DEPENDS+=	${X11BASE}/lib/X11/fonts/TrueType/wadalab-gothic.ttf:${PORTSDIR}/japanese/truetypefonts
.else
PLIST_SUB+=	JAPANESE="@comment "
.endif

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=You must manually fetch the IBM Java SDK ${JDK_VERSION} for Linux archive (${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again.
.endif

.include <bsd.port.pre.mk>

post-patch:
	@for shfn in `${GREP} -r '^#!/bin/sh' ${WRKSRC}|${AWK} -F: '{print $$1}'`; do \
		if [ ! -h $$shfn ]; then \
			(${SED} -e 's:^#!/bin/sh:#!${LINUX_SH}:' $$shfn \
				> $$shfn.tmp && ${CAT} $$shfn.tmp > $$shfn \
				&& ${RM} -f $$shfn.tmp) \
		fi \
	done

do-install:
	${MKDIR} ${APP_HOME}
	${TAR} -C ${WRKSRC} -cf- . | ${TAR} -C ${APP_HOME} -xpf-
	${LOCALBASE}/bin/registervm "${APP_HOME}/bin/java # IBM-JDK${PORTVERSION}_${PORTREVISION}"

post-install:
.if defined(WITH_JAPANESE_FONTS)
	${LN} -sf ${X11BASE}/lib/X11/fonts/TrueType/wa*ttf ${APP_HOME}/jre/lib/fonts/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
