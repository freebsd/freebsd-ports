# New ports collection makefile for:	graphics/linux-f8-png10
# Date created:				2008-03-28
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	png10
PORTVERSION=	1.0.30
PORTREVISION=	1
CATEGORIES=	graphics linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	RPM of the PNG lib (old 1.0 version, Linux Fedora 8)

CONFLICTS=	linux-png10-[0-9]* linux-f10-png10-[0-9]*

DEPRECATED=	End of Life since Jan 7, 2009
EXPIRATION_DATE=2011-04-01

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_NAME=	lib${PORTNAME}
LINUX_DIST_VER=	8
RPMVERSION=	1.fc8
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libpng.so.2 \
		usr/lib/libpng.so.2.${PORTVERSION}
DOCSDIR=	${PREFIX}/usr/share/doc/libpng10-${PORTVERSION}
PORTDOCS=	ANNOUNCE CHANGES LICENSE README TODO Y2KINFO
DESCR=		${.CURDIR}/../png/pkg-descr

.include <bsd.port.mk>
