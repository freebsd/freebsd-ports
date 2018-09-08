# $FreeBSD$

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}.${JDK_UPDATE_VERSION}.${JDK_PATCH_VERSION}
CATEGORIES=	java devel
MASTER_SITES=	#
PKGNAMEPREFIX=	linux-${JDK_VENDOR}-
PKGNAMESUFFIX=	${JDK_VERSION}
DISTNAME=	jdk-${JDK_VERSION}.${JDK_UPDATE_VERSION}.${JDK_PATCH_VERSION}_linux-x64_bin

MAINTAINER=	java@FreeBSD.org
COMMENT=	Oracle Java ${JDK_VERSION} Development Kit for Linux

ONLY_FOR_ARCHS=	amd64
RUN_DEPENDS=	javavm:java/javavmwrapper

RESTRICTED=	Redistribution of repackaged binaries not permitted

WRKSRC=		${WRKDIR}/jdk-${DL_JDK_VERSION}
PLIST_SUB=	T=${APP_HOME:S/^${PREFIX}\///} PORTVERSION=${PORTVERSION}

NO_BUILD=	yes
USES=		linux:c7 shebangfix
USE_LINUX=	xorglibs

JDK_VENDOR=		oracle
JDK_VERSION=		10
JDK_UPDATE_VERSION=	0
JDK_PATCH_VERSION=	2
.if ${JDK_PATCH_VERSION} == 0
.if ${JDK_UPDATE_VERSION} == 0
DL_JDK_VERSION=		${JDK_VERSION}
.else
DL_JDK_VERSION=		${JDK_VERSION}.${JDK_UPDATE_VERSION}
.endif
.else
DL_JDK_VERSION=		${JDK_VERSION}.${JDK_UPDATE_VERSION}.${JDK_PATCH_VERSION}
.endif
DOWNLOAD_URL=		http://www.oracle.com/technetwork/java/javase/downloads/index.html

APP_HOME=	${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}${JDK_VERSION}
BIN_DIRS=	bin
LIB_DIRS=	${BIN_DIRS:S|bin$|lib|}
SHEBANG_FILES=	${BIN_DIRS:S|$|/javapackager|}
bash_CMD=	/compat/linux/bin/bash

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE?=You must manually fetch the J2SE SDK download for the Linux platform (${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

post-patch:
	@cd ${WRKSRC}/include && ${LN} -s linux freebsd

do-install:
	@${MKDIR} ${STAGEDIR}${APP_HOME}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${APP_HOME}

.include <bsd.port.post.mk>
