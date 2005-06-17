# New ports collection makefile for:	linux jre 1.1.8
# Date created:				10 Sep 2003
# Whom:					Simun Mikecin <sime@logos.hr>
#
# $FreeBSD$
#

PORTNAME=	jre
PORTVERSION=	${JRE_VERSION}
PORTREVISION=	3
CATEGORIES=	java devel
MASTER_SITES=	ftp://gd.tuwien.ac.at/opsys/linux/java/JDK-${PORTVERSION}/${ARCH}/v3/ \
		ftp://metalab.unc.edu/pub/linux/devel/lang/java/blackdown.org/JDK-${PORTVERSION}/i386/v3/ \
		ftp://ftp.tux.org/pub/java/JDK-${PORTVERSION}/i386/v3/ \
		ftp://ftp.funet.fi/pub/Linux/java/jdk/blackdown.org/JDK-${PORTVERSION}/i386/v3/ \
		ftp://ftp.uk.linux.org/pub/linux/java/JDK-${PORTVERSION}/i386/v3/
PKGNAMEPREFIX=	linux-blackdown-
DISTNAME=	jre118_v3-glibc-2.1.3

MAINTAINER=	sime@logos.hr
COMMENT=	Blackdown Linux Java Runtime Environment 1.1.8

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

NO_CDROM=	"License doesn\'t allow distribution with fee"
NO_PACKAGE=     "License doesn\'t allow binary distributions"

ONLY_FOR_ARCHS=	i386 amd64

USE_BZIP2=	YES
USE_LINUX=	yes
USE_XLIB=	yes
WRKSRC=		${WRKDIR}/jre118_v3
JRE_VERSION=	1.1.8
PLIST_SUB+=	JRE_VERSION=${JRE_VERSION}
NO_BUILD=	YES
APP_HOME?=	${PREFIX}/linux-blackdown-jre${PORTVERSION}
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///}

post-patch:
	${FIND} ${WRKSRC} \( -name '*.orig' -o -name '.*.orig' \) -delete
	${CP} ${FILESDIR}/arch ${WRKSRC}/bin/
	${CHMOD} a+rx ${WRKSRC}/bin/arch
	${CHMOD} a+r ${WRKSRC}/README.linux

# XXX: This is missing a "${BRANDELF} -t Linux <executables>".

do-install:
	${MKDIR} ${APP_HOME}
	cd ${WRKSRC} && ${FIND} . -print \
	  | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} ${APP_HOME}
	cd ${APP_HOME}/bin && \
		${LN} -sf .java_wrapper java && \
	cd ${APP_HOME}/bin/i386/green_threads && \
		${LN} -sf jre java && \
	cd ${APP_HOME}/bin/i386/native_threads && \
		${LN} -sf jre java

post-install:
	${LOCALBASE}/bin/registervm "${APP_HOME}/bin/java # Linux-Blackdown-JRE${PORTVERSION}"

.include <bsd.port.mk>
