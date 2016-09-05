# Created by: bsam
# $FreeBSD$

PORTNAME=	libogg
PORTVERSION=	1.1.3
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Ogg bitstream library (Linux Fedora 10)

CONFLICTS=	linux-libogg-[0-9]* linux-f8-libogg-[0-9]*

USES=		linux:f10
USE_LINUX_RPM=	yes

RPMVERSION=	9.fc9
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libogg.so.0 usr/lib/libogg.so.0.5.3
PORTDOCS=	AUTHORS CHANGES COPYING README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
