# Created by: bsam
# $FreeBSD$

PORTNAME=		upx
PORTVERSION=		3.03
CATEGORIES=		archivers linux
PKGNAMEPREFIX=		linux-f10-

MAINTAINER=		emulation@FreeBSD.org
COMMENT=		UPX, a high-performance executable packer (Linux Fedora 10)

CONFLICTS=		linux-upx-[0-9]* linux-f8-upx-[0-9]*

USES=			linux:f10
USE_LINUX_RPM=		yes
USE_LINUX=		ucl
RPMVERSION=		1.fc10

PLIST_FILES=		usr/bin/upx usr/share/man/man1/upx.1.gz
PORTDOCS=		BUGS COPYING LICENSE NEWS PROJECTS README README.1ST \
			THANKS TODO elf-to-mem.txt filter.txt loader.txt selinux.txt
DESCR=			${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
