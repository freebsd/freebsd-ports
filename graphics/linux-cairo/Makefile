# New ports collection makefile for:	linux-cairo
# Date created:		4 November 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cairo
PORTVERSION=	1.0.2
DISTVERSIONSUFFIX=	-2.gst.1.4
PORTREVISION=	2
CATEGORIES=	graphics linux
MASTER_SITES=	http://gstreamer.freedesktop.org/pkg/%SUBDIR%/ CENKES/myports
MASTER_SITE_SUBDIR=	${LINUX_DIST}/${LINUX_DIST_VER}/${LINUX_RPM_ARCH}/RPMS.deps
MASTER_SITE_SRC_SUBDIR=	${LINUX_DIST}/${LINUX_DIST_VER}/${LINUX_RPM_ARCH}/SRPMS.deps

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Linux cairo binary

CONFLICTS=	linux-f8-cairo-[0-9]* linux-f10-cairo-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	fontconfig png xorglibs
PLIST_SUB=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>
