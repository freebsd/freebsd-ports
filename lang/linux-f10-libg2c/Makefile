# New ports collection makefile for:	lang/linux-f10-libg2c
# Date created:				2009-05-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	libg2c
PORTVERSION=	3.4.6
CATEGORIES=	lang linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Fortran 77 shared library (Linux Fedora 10)

CONFLICTS=	linux-libg2c-[0-9]* linux-f8-libg2c-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_NAME=	compat-libf2c-34
LINUX_DIST_VER=	10
RPMVERSION=	9
USE_LDCONFIG=	yes
SRC_DISTFILES=	compat-gcc-34-${PORTVERSION}-${RPMVERSION}.src.rpm

PLIST_FILES=	usr/lib/libg2c.so.0 usr/lib/libg2c.so.0.0.0

.include <bsd.port.mk>
