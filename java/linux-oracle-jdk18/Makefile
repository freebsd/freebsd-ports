# $FreeBSD$

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}.${JDK_UPDATE_VERSION}
CATEGORIES=	java devel
MASTER_SITES=	#
PKGNAMEPREFIX=	linux-${JDK_VENDOR}-
DISTNAME=	jdk-${JDK_VERSION}u${JDK_UPDATE_VERSION}-linux-i586

MAINTAINER=	java@FreeBSD.org
COMMENT=	Oracle Java ${JDK_VERSION} Development Kit for Linux

RUN_DEPENDS=	javavm:java/javavmwrapper

OPTIONS_DEFINE=	DEMO
DEMO_DESC=	Install demos and samples

RESTRICTED=	Redistribution of repackaged binaries not permitted
PKGNAMESUFFIX=	1${JDK_VERSION}

WRKSRC=		${WRKDIR}/jdk${DL_JDK_VERSION}
PLIST_SUB=	T=${APP_HOME:S/^${PREFIX}\///} PORTVERSION=${PORTVERSION}

NO_BUILD=	yes
USES=		linux shebangfix
USE_LINUX=	xorglibs
ONLY_FOR_ARCHS=	i386 amd64

JDK_VENDOR=		oracle
JDK_VERSION=		8
JDK_INTERNAL_VERSION=	1.${JDK_VERSION}.0
JDK_UPDATE_VERSION=	112
.if ${JDK_UPDATE_VERSION} == 0
DL_JDK_VERSION=		${JDK_INTERNAL_VERSION}
.elif ${JDK_UPDATE_VERSION} <= 9
DL_JDK_VERSION=		${JDK_INTERNAL_VERSION}_0${JDK_UPDATE_VERSION}
.else
DL_JDK_VERSION=		${JDK_INTERNAL_VERSION}_${JDK_UPDATE_VERSION}
.endif
DOWNLOAD_URL=		http://www.oracle.com/technetwork/java/javase/downloads/index.html

APP_HOME=	${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}${JDK_INTERNAL_VERSION}
BIN_DIRS=	bin jre/bin
LIB_DIRS=	${BIN_DIRS:S|bin$|lib|}
SHEBANG_FILES=	${BIN_DIRS:S|$|/jcontrol|}
bash_CMD=	${SH}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE?=You must manually fetch the J2SE SDK download for the Linux platform (${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEMO}
DEMO_UPDATE_VERSION=	${JDK_UPDATE_VERSION}
.if ${DEMO_UPDATE_VERSION} != ${JDK_UPDATE_VERSION}
DEMO_DISTNAME=	jdk-${JDK_VERSION}u${DEMO_UPDATE_VERSION}-linux-i586-demos
DEMO_WRKSRC=	${WRKDIR}/jdk${JDK_INTERNAL_VERSION}_${DEMO_UPDATE_VERSION}
.else
DEMO_DISTNAME=	${DISTNAME}-demos
DEMO_WRKSRC=	${WRKSRC}
.endif
.if !exists(${DISTDIR}/${DEMO_DISTNAME}${EXTRACT_SUFX})
IGNORE?=You must manually fetch the J2SE demos and samples for the Linux platform (${DEMO_DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DEMO_DISTNAME}${EXTRACT_SUFX}
PLIST_SUB+=	DEMO=""
.else
PLIST_SUB+=	DEMO="@comment "
.endif

.if ${PORT_OPTIONS:MDEMO} && ${DEMO_WRKSRC} != ${WRKSRC}
post-extract:
	@cd ${DEMO_WRKSRC} && ${MV} demo sample ${WRKSRC}
.endif

post-patch:
	@cd ${WRKSRC}/include && ${LN} -s linux freebsd

do-install:
	@${MKDIR} ${STAGEDIR}${APP_HOME}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${APP_HOME}
	@cd ${STAGEDIR}${APP_HOME} && \
	    ${CHMOD} ${BINMODE} ${BIN_DIRS:S|$|/*|} ${LIB_DIRS:S|$|/jexec|}

.include <bsd.port.post.mk>
