# New ports collection makefile for:	linux-blackdown-jdk14
# Date created:				12 August 2002
# Whom:					Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}
PORTREVISION=	1
CATEGORIES=	java
MASTER_SITES=	ftp://metalab.unc.edu/pub/linux/devel/lang/java/blackdown.org/${DOWNLOAD_DIR}/ \
		ftp://ftp.tux.org/pub/java/${DOWNLOAD_DIR}/
PKGNAMEPREFIX=	linux-blackdown-
DISTNAME=	j2sdk-${JDK_VERSION}${JDK_VER_SUFFIX}-linux-i586
EXTRACT_SUFX=	.bin

MAINTAINER=	java@FreeBSD.org
COMMENT=	Blackdown Java Development Kit 1.4 for Linux

RUN_DEPENDS=	${LOCALBASE}/bin/javavm:${PORTSDIR}/java/javavmwrapper

EXTRACT_CMD=		${TAIL}
EXTRACT_BEFORE_ARGS=	+564
EXTRACT_AFTER_ARGS=	| ${BZIP2_CMD} -dc | ${TAR} xf -
USE_BZIP2=	yes
LATEST_LINK=	linux-blackdown-jdk14

WRKSRC=		${WRKDIR}/j2sdk${PORTVERSION}
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///} PORTVERSION=${PORTVERSION}

NO_BUILD=	yes
USE_LINUX=	yes
JDK_VERSION=	1.4.2
JDK_VER_SUFFIX=	-01
DOWNLOAD_DIR=	${PORTNAME:U}-${JDK_VERSION}/${ARCH}/01
ONLY_FOR_ARCHS=	i386 amd64

NO_CDROM=	"License doesn\'t allow distribution with fee"
NO_PACKAGE=	"License doesn\'t allow binary distributions"

APP_HOME=	${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}${JDK_VERSION}

.include <bsd.port.pre.mk>

post-fetch:
	@${CHMOD} +x ${DISTDIR}/${DISTFILES}

post-patch:
	@${ECHO} -n ">> Removing unneeded files..."
	@${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM} -f
	@${RM} -rf ${WRKSRC}/demo/jfc/SwingSet2/resources
	@${RM} -rf ${WRKSRC}/demo/plugin/jfc/SwingSet2/resources
	@${ECHO} " [ DONE ]"

do-install:
	@${ECHO} -n ">> Creating destination directory ${APP_HOME}..."
	@${MKDIR} ${APP_HOME}
	@${ECHO} " [ DONE ]"

	@${ECHO} -n ">> Copying files..."
	@${CP} -R ${WRKSRC}/* ${APP_HOME}
	@${CHOWN} -h -R ${LIBOWN}:${LIBGRP} ${APP_HOME}
	@${ECHO} " [ DONE ]"

	@${ECHO} -n ">> Registering with javavm..."
	@${LOCALBASE}/bin/registervm "${APP_HOME}/bin/java # Linux-Blackdown-JDK${PORTVERSION}"
	@${ECHO} " [ DONE ]"

.include <bsd.port.post.mk>
