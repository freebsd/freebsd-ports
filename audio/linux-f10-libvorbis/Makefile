# Created by: bsam
# $FreeBSD$

PORTNAME=	libvorbis
PORTVERSION=	1.2.0
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Audio compression codec library (Linux Fedora 10)

CONFLICTS=	linux-libvorbis-[0-9]* linux-f8-libvorbis-[0-9]*

USES=		linux:f10
USE_LINUX_RPM=	yes
USE_LINUX=	libogg

RPMVERSION=	5.fc10
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libvorbis.so.0 usr/lib/libvorbis.so.0.4.0 \
		usr/lib/libvorbisenc.so.2 usr/lib/libvorbisenc.so.2.0.3 \
		usr/lib/libvorbisfile.so.3 usr/lib/libvorbisfile.so.3.2.0
PORTDOCS=	AUTHORS COPYING README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
