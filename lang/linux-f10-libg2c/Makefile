# Created by: bsam
# $FreeBSD$

PORTNAME=	libg2c
PORTVERSION=	3.4.6
CATEGORIES=	lang linux
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Fortran 77 shared library (Linux Fedora 10)

CONFLICTS=	linux-libg2c-[0-9]* linux-f8-libg2c-[0-9]*

USES=		linux:f10
USE_LINUX_RPM=	yes
LINUX_NAME=	compat-libf2c-34
RPMVERSION=	9
USE_LDCONFIG=	yes
SRC_DISTFILES=	compat-gcc-34-${PORTVERSION}-${RPMVERSION}.src.rpm:SOURCE

PLIST_FILES=	usr/lib/libg2c.so.0 usr/lib/libg2c.so.0.0.0

.include <bsd.port.mk>
