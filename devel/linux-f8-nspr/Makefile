# New ports collection makefile for:	devel/linux-f8-nspr
# Date created:				2009-04-05
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	nspr
PORTVERSION=	4.7.3
PORTREVISION=	1
CATEGORIES=	devel linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Netscape Portable Runtime (Linux Fedora 8)

CONFLICTS=	linux-nspr-[0-9]* linux-f10-nspr-[0-9]*

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	8
RPMVERSION=	1.fc8

PLIST_FILES=	usr/lib/libnspr4.so usr/lib/libplc4.so usr/lib/libplds4.so
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
