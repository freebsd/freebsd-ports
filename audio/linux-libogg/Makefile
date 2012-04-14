# New ports collection makefile for:	linux-libogg
# Date created:				25 Nov 2005
# Whom:					jylefort@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libogg
DISTVERSION=	1.1.2-2
PORTREVISION=	5
CATEGORIES=	audio linux

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ogg bitstream library (Linux version)

CONFLICTS=	linux-f8-libogg-[0-9]* linux-f10-libogg-[0-9]*

# EXPIRATION_DATE is the EoL of the last 7.x release
EXPIRATION_DATE=2013-02-28
ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
AUTOMATIC_PLIST=yes
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
