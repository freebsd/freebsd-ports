# New ports collection makefile for:	lang/linux-f8-libg2c
# Date created:				2008-04-02
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	libg2c
PORTVERSION=	3.4.6
PORTREVISION=	1
CATEGORIES=	lang linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Fortran 77 shared library (Linux Fedora 8)

CONFLICTS=	linux-libg2c-[0-9]* linux-f10-libg2c-[0-9]*

DEPRECATED=	End of Life since Jan 7, 2009
EXPIRATION_DATE=2011-04-01

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_NAME=	compat-libf2c-34
LINUX_DIST_VER=	8
RPMVERSION=	8
USE_LDCONFIG=	yes
SRC_DISTFILES=	compat-gcc-34-${PORTVERSION}-${RPMVERSION}.src.rpm

PLIST_FILES=	usr/lib/libg2c.so.0 usr/lib/libg2c.so.0.0.0

.include <bsd.port.mk>
