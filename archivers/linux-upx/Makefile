# New ports collection makefile for:	archivers/linux-upx
# Date created:				03 Jun 2007
# Whom:					Boris Samorodov <bsam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		upx
PORTVERSION=		1.25
PORTREVISION=		2
CATEGORIES=		archivers linux
MASTER_SITE_SUBDIR=	../extras/${LINUX_DIST_VER}/${LINUX_RPM_ARCH}
DISTNAME=		${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=		emulation@FreeBSD.org
COMMENT=		RPM of UPX, a high-performance executable packer

CONFLICTS=		linux-f8-upx-[0-9]* linux-f10-upx-[0-9]*

USE_LINUX_RPM=		yes
USE_LINUX_APPS=		ucl
RPMVERSION=		4
LINUX_DIST_VER=		4
BRANDELF_FILES=		usr/bin/upx
MASTER_SITE_SRC_SUBDIR=	../extras/${LINUX_DIST_VER}/SRPMS
DESCR=			${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
