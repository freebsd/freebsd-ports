# New ports collection makefile for:		linux-libg2c
# Date created:					2006.07.05
# Whom:						bsam
#
# $FreeBSD$

PORTNAME=	libg2c
PORTVERSION=	3.2.3
CATEGORIES=	lang linux
DISTNAME=	compat-libf2c-32-${PORTVERSION}-47.fc4

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Fortran 77 compatibility runtime

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
INSTALLS_SHLIB=	yes
SRC_DISTFILES=	compat-gcc-32-${PORTVERSION}-47.fc4.src.rpm

PLIST_FILES=	usr/lib/libg2c.so.0 usr/lib/libg2c.so.0.0.0

.include <bsd.port.mk>
