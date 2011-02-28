# New ports collection makefile for:	audio/linux-f8-arts
# Date created:				2008-04-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=		arts
PORTVERSION=		1.5.10
PORTREVISION=		1
CATEGORIES=		audio kde linux
PKGNAMEPREFIX=		linux-f8-
DISTNAME=		${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=		emulation@FreeBSD.org
COMMENT=		Audio system for the KDE integrated X11 desktop (Linux Fedora 8)

CONFLICTS=		linux-arts-[0-9]* linux-f10-arts-[0-9]*

DEPRECATED=	End of Life since Jan 7, 2009
EXPIRATION_DATE=2011-04-01

ONLY_FOR_ARCHS=		i386 amd64
USE_LINUX_RPM=		yes
LINUX_DIST_VER=		8
RPMVERSION=		1.fc8.1
BRANDELF_DIRS=		usr/bin
USE_LDCONFIG=		yes
DESCR=			${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
