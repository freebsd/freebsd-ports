# New ports collection makefile for:	Sun Linux JDK 1.4.x
# Date created:				25 May 2001
# Whom:					Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${INSTALL_JDK_VERSION}
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	#
PKGNAMEPREFIX=	linux-sun-
DISTNAME=	j2sdk-${DL_JDK_VERSION:S/./_/g}-linux-i586
EXTRACT_SUFX=	.bin

MAINTAINER=	znerd@FreeBSD.org

BUILD_DEPENDS=  ${LINUXBASE}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base
RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

NO_CDROM=	"License does not allow distribution with fee"
RESTRICTED=	"Redistribution of repackaged binaries not permitted"

EXTRACT_CMD=		# empty
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	# empty

WRKSRC=		${WRKDIR}/j2sdk${DL_JDK_VERSION}
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///} PORTVERSION=${PORTVERSION}

NO_BUILD=	yes
USE_LINUX=	yes
DL_JDK_VERSION=	1.4.1_01
INSTALL_JDK_VERSION=	1.4.1
ONLY_FOR_ARCHS=	i386
DOWNLOAD_URL?=	http://java.sun.com/webapps/download/Display?BundleId=7143
PORTTITLE=	Java 2 Development Kit ${INSTALL_JDK_VERSION} for Linux
APP_HOME=	${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}${INSTALL_JDK_VERSION}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=You must manually fetch the J2SE v1.4 SDK Linux GNUZIP Tar shell script (${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

pre-everything:
	@${CAT} ${PKGMESSAGE}

post-fetch:
	@${CHMOD} +x ${DISTDIR}/${DISTFILES}

post-patch:
	find ${WRKSRC} -name '*.orig' -print | xargs ${RM} -f

do-install:
	${MKDIR} ${APP_HOME}
	${TAR} -C ${WRKSRC} -cf- . | ${TAR} -C ${APP_HOME} -xpf-
	${LOCALBASE}/bin/registervm "${APP_HOME}/bin/java # Linux-Sun-JDK${PORTVERSION}"

.include <bsd.port.post.mk>
