# $FreeBSD$

PORTNAME=	jre
PORTVERSION=	${JRE_VERSION}.${JRE_UPDATE_VERSION}
CATEGORIES=	java
MASTER_SITES=	#
PKGNAMEPREFIX=	linux-${JRE_VENDOR}-
DISTNAME=	jre-${JRE_VERSION}u${JRE_UPDATE_VERSION}-linux-i586

MAINTAINER=	java@FreeBSD.org
COMMENT=	Oracle Java ${JRE_VERSION} Runtime Environment for Linux

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

NO_CDROM=	License does not allow distribution with fee
RESTRICTED=	Redistribution of repackaged binaries not permitted
PKGNAMESUFFIX=	1${JRE_VERSION}

WRKSRC=		${WRKDIR}/jre${DL_JRE_VERSION}
PLIST_SUB=	T=${APP_HOME:S/^${PREFIX}\///} PORTVERSION=${PORTVERSION}

NO_BUILD=	yes
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
USES=		shebangfix
ONLY_FOR_ARCHS=	i386 amd64

JRE_VENDOR=		sun
JRE_VERSION=		7
JRE_INTERNAL_VERSION=	1.${JRE_VERSION}.0
JRE_UPDATE_VERSION=	71
DL_JRE_VERSION=		${JRE_INTERNAL_VERSION}_${JRE_UPDATE_VERSION}
DOWNLOAD_URL=		http://www.oracle.com/technetwork/java/javase/downloads/index.html

APP_HOME=	${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}${JRE_INTERNAL_VERSION}
BIN_DIRS=	bin
LIB_DIRS=	${BIN_DIRS:S|bin$|lib|}
SHEBANG_FILES=	${BIN_DIRS:S|$|/jcontrol|}
bash_CMD=	${SH}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE?=You must manually fetch the J2SE RE download for the Linux platform (${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${APP_HOME}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${APP_HOME}
	@cd ${STAGEDIR}${APP_HOME} && \
	    ${CHMOD} ${BINMODE} ${BIN_DIRS:S|$|/*|} ${LIB_DIRS:S|$|/jexec|}

post-install:
	${MKDIR} ${STAGEDIR}${APP_HOME}/.systemPrefs
	${TOUCH} ${STAGEDIR}${APP_HOME}/.systemPrefs/.system.lock
	${TOUCH} ${STAGEDIR}${APP_HOME}/.systemPrefs/.systemRootModFile
	${CHMOD} 644 ${STAGEDIR}${APP_HOME}/.systemPrefs/.system.lock
	${CHMOD} 644 ${STAGEDIR}${APP_HOME}/.systemPrefs/.systemRootModFile

.include <bsd.port.post.mk>
