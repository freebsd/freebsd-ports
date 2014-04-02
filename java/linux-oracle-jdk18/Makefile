# $FreeBSD$

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}.${JDK_UPDATE_VERSION}
CATEGORIES=	java devel
MASTER_SITES=	#
PKGNAMEPREFIX=	linux-oracle-
DISTNAME=	jdk-8-linux-i586

MAINTAINER=	java@FreeBSD.org
COMMENT=	Oracle Java ${JDK_VERSION} Development Kit for Linux

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

OPTIONS_DEFINE=	DEMO
DEMO_DESC=	Install demos and samples

NO_CDROM=	License does not allow distribution with fee
RESTRICTED=	Redistribution of repackaged binaries not permitted
PKGNAMESUFFIX=	18

WRKSRC=		${WRKDIR}/jdk${DL_JDK_VERSION}
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///} PORTVERSION=${PORTVERSION}

NO_BUILD=	yes
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
USES=		shebangfix
ONLY_FOR_ARCHS=	i386 amd64

JDK_VERSION=		8
JDK_INTERNAL_VERSION=	1.8.0
JDK_UPDATE_VERSION=	0
DL_JDK_VERSION=		${JDK_INTERNAL_VERSION}
DOWNLOAD_URL=		http://www.oracle.com/technetwork/java/javase/downloads/index.html

APP_HOME=	${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}${JDK_INTERNAL_VERSION}
BIN_DIRS=	bin jre/bin
SHEBANG_FILES=	bin/jcontrol jre/bin/jcontrol
bash_CMD=	${SH}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE?=You must manually fetch the J2SE SDK download for the Linux platform (${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEMO}
DEMO_UPDATE_VERSION=	${JDK_UPDATE_VERSION}
.if ${DEMO_UPDATE_VERSION} != ${JDK_UPDATE_VERSION}
DEMO_DISTNAME=	jdk-7u${DEMO_UPDATE_VERSION}-linux-i586-demos
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
	@${MV} ${DEMO_WRKSRC}/demo ${WRKSRC}/
	@${MV} ${DEMO_WRKSRC}/sample ${WRKSRC}/
.endif

post-patch:
	@cd ${WRKSRC}/include && ${LN} -s linux freebsd

do-install:
	@${MKDIR} ${STAGEDIR}${APP_HOME}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${APP_HOME}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${APP_HOME} \
	    "-not ( -type d -name bin -prune )"
	@cd ${WRKSRC} && ${COPYTREE_BIN} "${BIN_DIRS}" ${STAGEDIR}${APP_HOME}
	@${INSTALL_SCRIPT} ${WRKSRC}/jre/lib/jexec \
	    ${STAGEDIR}${APP_HOME}/jre/lib
	@${INSTALL_SCRIPT} ${WRKSRC}/lib/jexec ${STAGEDIR}${APP_HOME}/lib

.include <bsd.port.post.mk>
