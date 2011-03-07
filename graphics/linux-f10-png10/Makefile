# New ports collection makefile for:	graphics/linux-f10-png10
# Date created:				2009-05-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	png10
PORTVERSION=	1.0.43
CATEGORIES=	graphics linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of the PNG lib (old 1.0 version, Linux Fedora 10)

CONFLICTS=	linux-png10-[0-9]* linux-f8-png10-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_NAME=	lib${PORTNAME}
LINUX_DIST_VER=	10
RPMVERSION=	1.fc10
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libpng.so.2 \
		usr/lib/libpng.so.2.${PORTVERSION}
DOCSDIR=	${PREFIX}/usr/share/doc/libpng10-${PORTVERSION}
PORTDOCS=	ANNOUNCE CHANGES LICENSE README TODO Y2KINFO
DESCR=		${.CURDIR}/../png/pkg-descr

.include <bsd.port.mk>
