# New ports collection makefile for:	archivers/linux-ucl
# Date created:				03 Jun 2007
# Whom:					Boris Samorodov <bsam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		ucl
PORTVERSION=		1.03
PORTREVISION=		2
CATEGORIES=		archivers linux
MASTER_SITE_SUBDIR=	../extras/${LINUX_DIST_VER}/${LINUX_RPM_ARCH}
DISTNAME=		${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=		emulation@FreeBSD.org
COMMENT=		RPM of UCL, a lossless data compression library

CONFLICTS=		linux-f8-ucl-[0-9]* linux-f10-ucl-[0-9]*

USE_LINUX_RPM=		yes
RPMVERSION=		3
LINUX_DIST_VER=		4
USE_LDCONFIG=		yes
MASTER_SITE_SRC_SUBDIR=	../extras/${LINUX_DIST_VER}/SRPMS
DESCR=			${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
