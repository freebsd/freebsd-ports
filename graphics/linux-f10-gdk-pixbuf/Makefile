# New ports collection makefile for:	devel/linux-f10-gdk-pixbuf
# Date created:				2009-05-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	gdk-pixbuf
PORTVERSION=	0.22.0
CATEGORIES=	graphics linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Image loading library for GTK+ (Linux Fedora 10)

CONFLICTS=	linux-gdk-pixbuf-[0-9]* linux-f8-gdk-pixbuf-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
RPMVERSION=	36.fc9
USE_LDCONFIG=	yes

.include <bsd.port.mk>
