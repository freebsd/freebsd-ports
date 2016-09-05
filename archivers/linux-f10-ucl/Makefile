# Created by: bsam
# $FreeBSD$

PORTNAME=		ucl
PORTVERSION=		1.03
CATEGORIES=		archivers linux

MAINTAINER=		emulation@FreeBSD.org
COMMENT=		UCL, a lossless data compression library (Linux Fedora 10)

CONFLICTS=		linux-ucl-[0-9]* linux-f8-ucl-[0-9]*

USES=			linux:f10
USE_LINUX_RPM=		yes
RPMVERSION=		8.fc9
USE_LDCONFIG=		yes

PLIST_FILES=		usr/lib/libucl.so.1 usr/lib/libucl.so.1.0.0
PORTDOCS=		COPYING NEWS README THANKS TODO
DESCR=			${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
