# New ports collection makefile for:	eclipse
# Date created:				March 7, 2003
# Whom:					Alexander Kabaev <kan@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	eclipse
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE}
MASTER_SITE_SUBDIR=	R-2.1.1-200306271545
DISTNAME=	eclipse-sourceBuild-srcIncluded-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	java@FreeBSD.ORG
COMMENT=	An open extensible IDE for anything and nothing in particular

LIB_DEPENDS=	gtk-x11-2.0:${PORTSDIR}/x11-toolkits/gtk20
BUILD_DEPENDS=	ant:${PORTSDIR}/devel/jakarta-ant \
		pkg-config:${PORTSDIR}/devel/pkgconfig

ONLY_FOR_ARCHS=	i386
USE_ZIP=	yes
USE_JAVA=	1.3+
USE_REINPLACE=	yes
NO_WRKSUBDIR=	yes

MAKE_ARGS=	ECLIPSE_BUILD=${ECLIPSE_BUILD} \
		ECLIPSE_ARCH=${ECLIPSE_ARCH} \
		ECLIPSE_OS=${ECLIPSE_OS} \
		ECLIPSE_WS=${ECLIPSE_WS} \
		JAVA_HOME=${JAVA_HOME}
MAKE_ENV=	ANT_OPTS=-Xmx256M

ECLIPSE_BUILD=	2135
ECLIPSE_OS=	freebsd
ECLIPSE_WS=	gtk
ECLIPSE_ARCH=	x86

post-patch:
		@${FIND} ${WRKSRC} -name build.xml | ${XARGS} ${REINPLACE_CMD} 's@verbose="true"@verbose="false"@g'

.include <bsd.port.mk>
