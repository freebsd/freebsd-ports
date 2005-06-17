# New ports collection makefile for:	linux jdk 1.2.2
# Date created:		Nov 3 1999
# Whom:			Jose Marques
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	1.2.2
PORTREVISION=	6
CATEGORIES=	java devel
MASTER_SITES=	ftp://ftp.tux.org/pub/java/JDK-${PORTVERSION}/${ARCH}/FCS/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	znerd
PKGNAMEPREFIX=	linux-blackdown-
DISTNAME=	j2sdk-${PORTVERSION}-FCS-linux-${ARCH}-glibc-2.1.3

MAINTAINER=	java@FreeBSD.org
COMMENT=	Blackdown Java Development Kit 1.2 for Linux

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

NO_CDROM=	"License doesn\'t allow distribution with fee"
NO_PACKAGE=	"License doesn\'t allow binary distributions"
LATEST_LINK=	linux-blackdown-jdk12

ONLY_FOR_ARCHS=	i386 amd64

USE_BZIP2=	YES
USE_LINUX=	yes
USE_XLIB=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}
NO_BUILD=	YES
APP_HOME?=	${PREFIX}/${PKGBASE}${PORTVERSION}
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///}

post-patch:
	${FIND} ${WRKSRC} \( -name '*.orig' -o -name '.*.orig' \) -print \
	  | ${XARGS} ${RM} -f

# XXX: This is missing a "${BRANDELF} -t Linux <executables>".

do-install:
	${MKDIR} ${APP_HOME}
	cd ${WRKSRC} && ${FIND} . -print \
	  | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} ${APP_HOME}
	${INSTALL_DATA} ${FILESDIR}/cacerts ${APP_HOME}/jre/lib/security/cacerts
	${LOCALBASE}/bin/registervm "${APP_HOME}/bin/java # Linux-Blackdown-JDK${PORTVERSION}"

.include <bsd.port.mk>
