# $FreeBSD$

PORTNAME=	android-tools-adb
DISTVERSION=	5.0.0_r7
CATEGORIES=	devel

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Android debug bridge command line tool

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	android
GH_PROJECT=	platform_system_core
GH_TAGNAME=	android-${DISTVERSION}

USES=		gmake
WRKSRC=		${WRKDIR}/${GH_PROJECT}-${GH_TAGNAME_EXTRACT}/adb
MAKEFILE=	${FILESDIR}/Makefile
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/adb

.include <bsd.port.mk>
