# New ports collection makefile for:	linux-ibm-jdk
# Date created:				22 April 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}
PORTREVISION=	2 # Service Release 10 : cx130-20010925
CATEGORIES=	java
MASTER_SITES=	#
PKGNAMEPREFIX=	linux-ibm-
DISTNAME=	IBMJava2-SDK-13
EXTRACT_SUFX=	.tgz

MAINTAINER=	perky@python.or.kr

BUILD_DEPENDS=	${LOCALBASE}/bin/javavm:${PORTSDIR}/java/javavmwrapper \
		${X11BASE}/lib/X11/fonts/TrueType/wadalab-gothic.ttf:${PORTSDIR}/japanese/truetypefonts
RUN_DEPENDS=	${LOCALBASE}/bin/javavm:${PORTSDIR}/java/javavmwrapper \
		${X11BASE}/lib/X11/fonts/TrueType/wadalab-gothic.ttf:${PORTSDIR}/japanese/truetypefonts

WRKSRC=		${WRKDIR}/${DISTNAME:S/-SDK//}
PLIST_SUB+=	TARGET_PREFIX=${TARGET_PREFIX:S/^${PREFIX}\///}

NO_BUILD=	yes
USE_LINUX=	yes
JDK_VERSION=	1.3.0
ONLY_FOR_ARCHS=	i386
TARGET_PREFIX?=	${PREFIX}/${PKGBASE}${PORTVERSION}
LINUX_SH?=	${LINUXBASE}/bin/sh

NO_CDROM=	"License doesn\'t allow distribution with fee"
RESTRICTED=	"Redistribution of repackaged binaries not permitted"

XARGS=		xargs
FIND=		find

.if defined(BATCH) || defined(PACKAGE_BUILDING)
IGNORE=	"You can not legally distribute binaries"
.endif

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=You must manually fetch the IBM Java SDK ${JDK_VERSION} for Linux archive (${DISTNAME}${EXTRACT_SUFX}) from http://www6.software.ibm.com/dl/dklx130/dklx130-p, place it in ${DISTDIR} and then run make again.
.endif

post-patch:
	@for shfn in `${GREP} -r '^#!/bin/sh' ${WRKSRC}|${AWK} -F: '{print $$1}'`; do \
		if [ ! -h $$shfn ]; then \
			(${SED} -e 's:^#!/bin/sh:#!${LINUX_SH}:' $$shfn \
				> $$shfn.tmp && ${CAT} $$shfn.tmp > $$shfn \
				&& ${RM} -f $$shfn.tmp) \
		fi \
	done

do-install:
	${MKDIR} ${TARGET_PREFIX}
	${TAR} -C ${WRKSRC} -cf- . | ${TAR} -C ${TARGET_PREFIX} -xpf-
	${LOCALBASE}/bin/registervm "${TARGET_PREFIX}/bin/java # IBM-JDK${PORTVERSION}_${PORTREVISION}"

post-install:
	${LN} -sf ${X11BASE}/lib/X11/fonts/TrueType/wa*ttf ${TARGET_PREFIX}/jre/lib/fonts/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
