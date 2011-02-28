# New ports collection makefile for:	devel/linux-f8-allegro
# Date created:				2008-04-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	allegro
PORTVERSION=	4.2.2
PORTREVISION=	1
CATEGORIES=	devel linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Cross-platform game programming library (Linux Fedora 8)

CONFLICTS=	linux-allegro-[0-9]* linux-f10-allegro-[0-9]*

DEPRECATED=	End of Life since Jan 7, 2009
EXPIRATION_DATE=2011-04-01

USE_LINUX_RPM=		yes
USE_LINUX_APPS=		xorglibs
ONLY_FOR_ARCHS=		i386 amd64
LINUX_DIST_VER=		8
RPMVERSION=		10.fc8
USE_LDCONFIG=		yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
