# $FreeBSD$

PORTNAME=	android-tools-fastboot
DISTVERSIONPREFIX=	${GH_ACCOUNT}-
DISTVERSION=	4.0.4_r2.1
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Android Fastboot protocol CLI tool

LICENSE=	APACHE20 BSD2CLAUSE
LICENSE_COMB=	multi

USE_GITHUB=	yes
GH_ACCOUNT=	android
GH_PROJECT=	platform_system_core

USES=		uidfix
WRKSRC_SUBDIR=	fastboot
MAKEFILE=	${FILESDIR}/Makefile
MAKE_ENV=	FILESDIR="${FILESDIR}" BINDIR="${PREFIX}/bin"
PLIST_FILES=	bin/fastboot

.include <bsd.port.mk>
