# New ports collection makefile for:	linux jdk 1.2.2
# Date created:		Nov 3 1999
# Whom:			Jose Marques
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	1.2.2
PORTREVISION=	3
CATEGORIES=	java devel
MASTER_SITES=	ftp://ftp.tux.org/pub/java/JDK-${PORTVERSION}/${ARCH}/FCS/ \
		http://www.metaverse.nl/~ernst/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	znerd
PKGNAMEPREFIX=	linux-blackdown-
DISTNAME=	j2sdk-${PORTVERSION}-FCS-linux-${ARCH}-glibc-2.1.3

MAINTAINER=	znerd@FreeBSD.org

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

NO_CDROM=	"License doesn\'t allow distribution with fee"
NO_PACKAGE=	"License doesn\'t allow binary distributions"

USE_LINUX=	YES
ONLY_FOR_ARCHS=	i386

USE_BZIP2=	YES
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}
NO_BUILD=	YES
APP_HOME?=	${PREFIX}/${PKGBASE}${PORTVERSION}
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///}

do-install:
	${MKDIR} ${APP_HOME}
	(cd ${WRKSRC} && tar --exclude "*.orig" -c -f - .) \
	| (cd ${APP_HOME} && tar fx -)
	${LOCALBASE}/bin/registervm "${APP_HOME}/bin/java # Linux-JDK${PORTVERSION}"

.include <bsd.port.mk>
