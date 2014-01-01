# $FreeBSD$

PORTNAME=	android-tools-adb
PORTVERSION=	4.3
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	android-platform_system_core-${GH_COMMIT}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Android debug bridge command line tool

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	android
GH_PROJECT=	platform_system_core
GH_TAGNAME=	android-4.3_r2.1
GH_COMMIT=	9cbdf50

USES=		gmake
WRKSRC=		${WRKDIR}/${DISTNAME}/adb
MAKEFILE=	${FILESDIR}/Makefile
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/adb

NO_STAGE=	yes
.include <bsd.port.mk>
