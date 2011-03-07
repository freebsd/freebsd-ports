# New ports collection makefile for:	graphics/linux-f8-jpeg
# Date created:				2008-03-28
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	jpeg
PORTVERSION=	6b
PORTREVISION=	1
CATEGORIES=	graphics linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of the JPEG lib (Linux Fedora 8)

CONFLICTS=	linux-jpeg-[0-9]* linux-f10-jpeg-[0-9]*

DEPRECATED=	End of Life since Jan 7, 2009
EXPIRATION_DATE=2011-04-01

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_NAME=	lib${PORTNAME}
LINUX_DIST_VER=	8
RPMVERSION=	39.fc8
BRANDELF_DIRS=	usr/bin
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
