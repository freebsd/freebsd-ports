# New ports collection makefile for:	audio/linux-f10-arts
# Date created:				2009-05-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=		arts
PORTVERSION=		1.5.10
CATEGORIES=		audio kde linux
PKGNAMEPREFIX=		linux-f10-
DISTNAME=		${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=		emulation@FreeBSD.org
COMMENT=		Audio system for the KDE integrated X11 desktop (Linux Fedora 10)

CONFLICTS=		linux-arts-[0-9]* linux-f8-arts-[0-9]*

ONLY_FOR_ARCHS=		i386 amd64
USE_LINUX_RPM=		yes
LINUX_DIST_VER=		10
RPMVERSION=		1.fc10
BRANDELF_DIRS=		usr/bin
USE_LDCONFIG=		yes
DESCR=			${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
