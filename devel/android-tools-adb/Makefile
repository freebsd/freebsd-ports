# $FreeBSD$

PORTNAME=	android-tools-adb
DISTVERSIONPREFIX=	android-
DISTVERSION=	5.0.0_r7
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Android debug bridge command line tool

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	android
GH_PROJECT=	platform_system_core

USES=		uidfix
WRKSRC_SUBDIR=	adb
MAKEFILE=	${FILESDIR}/Makefile
MAKE_ENV=	BINDIR="${PREFIX}/bin"

PLIST_FILES=	bin/adb

.include <bsd.port.mk>
