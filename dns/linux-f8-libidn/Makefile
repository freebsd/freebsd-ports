# New ports collection makefile for:	dns/linux-f8-libidn
# Date created:				2009-04-05
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	libidn
PORTVERSION=	0.6.14
PORTREVISION=	1
CATEGORIES=	dns linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Internationalized Domain Name support library (Linux Fedora 8)

CONFLICTS=	linux-libidn-[0-9]* linux-f10-libidn-[0-9]*

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	8
RPMVERSION=	4
BRANDELF_FILES=	usr/bin/idn
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
