# New ports collection makefile for:	devel/linux-f10-nspr
# Date created:				2009-05-04
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	nspr
PORTVERSION=	4.7.3
CATEGORIES=	devel linux
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Netscape Portable Runtime (Linux Fedora 10)

CONFLICTS=	linux-f8-nspr-[0-9]*

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
RPMVERSION=	2.fc10

PLIST_FILES=	lib/libnspr4.so lib/libplc4.so lib/libplds4.so
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
