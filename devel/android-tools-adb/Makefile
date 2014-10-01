# $FreeBSD$

PORTNAME=	android-tools-adb
DISTVERSION=	4.4.4_r1
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	android-platform_system_core-${GH_COMMIT}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Android debug bridge command line tool

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	android
GH_PROJECT=	platform_system_core
GH_TAGNAME=	android-${DISTVERSION}
GH_COMMIT=	c33036b

USES=		gmake
WRKSRC=		${WRKDIR}/${DISTNAME}/adb
MAKEFILE=	${FILESDIR}/Makefile
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/adb

.include <bsd.port.mk>
