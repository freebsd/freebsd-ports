# New ports collection makefile for:	linux-arts
# Date created:				6 October 2003
# Whom:					bms@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		arts
DISTVERSION=		1.5.3-0.1.fc4
PORTREVISION=		2
CATEGORIES=		audio kde linux

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Audio system for the KDE integrated X11 desktop (Linux version)

CONFLICTS=		linux-f8-arts-[0-9]* linux-f10-arts-[0-9]*

ONLY_FOR_ARCHS=		i386 amd64
USE_LINUX_RPM=		yes
LINUX_DIST_VER=		4
USE_LDCONFIG=		yes
AUTOMATIC_PLIST=	yes
DESCR=			${.CURDIR}/../${PORTNAME}/pkg-descr

BRANDELF_DIRS=	usr

.include <bsd.port.mk>
