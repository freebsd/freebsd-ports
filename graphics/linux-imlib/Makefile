# New ports collection makefile for: linux-imlib
# Date created:		01/09/18
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	imlib
PORTVERSION=	1.9.13
CATEGORIES=	graphics linux
DISTNAME=	${PORTNAME}-${PORTVERSION}-21

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RPM of imlib

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	3
INSTALLS_SHLIB=	yes
BRANDELF_DIRS=	usr/bin
PLIST=		pkg-plist.${LINUX_RPM_ARCH}
PLIST_SUB=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>
