# New ports collection makefile for:	linux-alsa-lib
# Date created:				25 Nov 2005
# Whom:					jylefort@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	alsa-lib
DISTVERSION=	1.0.10-3
PORTREVISION=	2
CATEGORIES=	audio linux
DISTNAME=	${PORTNAME}-${DISTVERSION}.FC4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Advanced Linux Sound Architecture libraries

CONFLICTS=	linux-f8-alsa-lib-[0-9]* linux-f10-alsa-lib-[0-9]*

# EXPIRATION_DATE is the EoL of the last 7.x release
EXPIRATION_DATE=2013-02-28
ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
AUTOMATIC_PLIST=yes
BRANDELF_DIRS=	usr/bin

.include <bsd.port.mk>
