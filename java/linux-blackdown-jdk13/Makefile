# New ports collection makefile for:	linux-blackdown-jdk13
# Date created:				09 May 2002
# Whom:					Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}
PORTREVISION=	1
CATEGORIES=	java
MASTER_SITES=	ftp://ftp.nluug.nl/pub/os/Linux/java/jdk/${DOWNLOAD_DIR}/ \
		ftp://metalab.unc.edu/pub/linux/devel/lang/java/blackdown.org/${DOWNLOAD_DIR}/ \
		ftp://ftp.tux.org/pub/java/${DOWNLOAD_DIR}/
PKGNAMEPREFIX=	linux-blackdown-
DISTNAME=	j2sdk-${JDK_VERSION}${JDK_VER_SUFFIX}-linux-${ARCH}
EXTRACT_SUFX=	.bin

MAINTAINER=	znerd@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/bin/javavm:${PORTSDIR}/java/javavmwrapper
RUN_DEPENDS=	${LOCALBASE}/bin/javavm:${PORTSDIR}/java/javavmwrapper

WRKSRC=		${WRKDIR}/j2sdk${PORTVERSION}
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///}

NO_BUILD=	yes
USE_LINUX=	yes
JDK_VERSION=	1.3.1
JDK_VER_SUFFIX=	-02b-FCS
DOWNLOAD_DIR=	${PORTNAME:U}-${JDK_VERSION}/${ARCH}/FCS-02b
ONLY_FOR_ARCHS=	arm i386 ppc sparc

NO_CDROM=	"License doesn\'t allow distribution with fee"
NO_PACKAGE=	"License doesn\'t allow binary distributions"

APP_HOME=	${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}${JDK_VERSION}

.include <bsd.port.pre.mk>

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && ${TAIL} +400 ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | ${BZIP2_CMD} -dc | ${TAR} xf -

post-patch:
	@${ECHO} -n ">> Removing unneeded files..."
	@${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM} -f
	@${ECHO} " [ DONE ]"

do-install:
	@${ECHO} -n ">> Creating destination directory ${APP_HOME}..."
	@${MKDIR} ${APP_HOME}
	@${ECHO} " [ DONE ]"

	@${ECHO} -n ">> Copying files..."
	@${CP} -R ${WRKSRC}/* ${APP_HOME}
	@${ECHO} " [ DONE ]"

	@${ECHO} -n ">> Registering with javavm..."
	@${LOCALBASE}/bin/registervm "${APP_HOME}/bin/java # Linux-Blackdown-JDK${PORTVERSION}_${PORTREVISION}"
	@${ECHO} " [ DONE ]"

post-install:
	@${ECHO} "Please read the license carefully before using this software."
	@${ECHO} "See: ${APP_HOME}/LICENSE"

.include <bsd.port.post.mk>
