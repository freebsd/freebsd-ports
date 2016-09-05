# Created by: bsam
# $FreeBSD$

PORTNAME=	freealut
PORTVERSION=	1.1.0
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Free implementation of OpenAL's ALUT standard (Linux Fedora 10)

CONFLICTS=	linux-freealut-[0-9]* linux-f8-freealut-[0-9]*

USES=		linux:f10
USE_LINUX_RPM=	yes
USE_LINUX=	openal

RPMVERSION=	6.fc9
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libalut.so.0 usr/lib/libalut.so.0.1.0
PORTDOCS=	AUTHORS COPYING ChangeLog README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
