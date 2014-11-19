# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	nspr
PORTVERSION=	4.10.6
CATEGORIES=	devel linux
PKGNAMEPREFIX=	linux-${USE_LINUX}-

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Netscape Portable Runtime (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f10-nspr-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
RPMVERSION=	1.el6_5
USE_LINUX=	c6

USE_LINUX_RPM=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libnspr4.so lib/libplc4.so lib/libplds4.so
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
