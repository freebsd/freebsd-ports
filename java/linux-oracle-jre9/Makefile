# $FreeBSD$

PORTNAME=	jre
PORTVERSION=	${JRE_VERSION}.${JRE_UPDATE_VERSION}
CATEGORIES=	java
MASTER_SITES=	#
PKGNAMEPREFIX=	linux-${JRE_VENDOR}-
PKGNAMESUFFIX=	${JRE_VERSION}
DISTNAME=	jre-${JRE_VERSION}_linux-x64_bin

MAINTAINER=	java@FreeBSD.org
COMMENT=	Oracle Java ${JRE_VERSION} Runtime Environment for Linux

ONLY_FOR_ARCHS=	amd64 i386
RUN_DEPENDS=	javavm:java/javavmwrapper

RESTRICTED=	Redistribution of repackaged binaries not permitted

WRKSRC=		${WRKDIR}/jre-${DL_JRE_VERSION}
PLIST_SUB=	T=${APP_HOME:S/^${PREFIX}\///} PORTVERSION=${PORTVERSION}

NO_BUILD=	yes
USES=		linux
USE_LINUX=	xorglibs

JRE_VENDOR=		oracle
JRE_VERSION=		9
JRE_UPDATE_VERSION=	0
.if ${JRE_UPDATE_VERSION} == 0
DL_JRE_VERSION=		${JRE_VERSION}
.elif ${JRE_UPDATE_VERSION} <= 9
DL_JRE_VERSION=		${JRE_VERSION}_0${JRE_UPDATE_VERSION}
.else
DL_JRE_VERSION=		${JRE_VERSION}_${JRE_UPDATE_VERSION}
.endif
DOWNLOAD_URL=		http://www.oracle.com/technetwork/java/javase/downloads/index.html

APP_HOME=	${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}${JRE_VERSION}
BIN_DIRS=	bin
LIB_DIRS=	${BIN_DIRS:S|bin$|lib|}
bash_CMD=	${SH}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE?=You must manually fetch the J2SE RE download for the Linux platform (${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${APP_HOME}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${APP_HOME}

.include <bsd.port.post.mk>
