# Created by: bsam
# $FreeBSD: head/devel/linux-f10-allegro/Makefile 340722 2014-01-22 17:00:46Z mat $

PORTNAME=	allegro
PORTVERSION=	4.2.2
CATEGORIES=	devel linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Cross-platform game programming library (Linux Fedora 10)

CONFLICTS=	linux-allegro-[0-9]* linux-f8-allegro-[0-9]*

USE_LINUX_RPM=		yes
USE_LINUX_APPS=		xorglibs
ONLY_FOR_ARCHS=		i386 amd64
LINUX_DIST_VER=		10
RPMVERSION=		10.fc10
USE_LDCONFIG=		yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
