# New ports collection makefile for:	archivers/linux-f8-upx
# Date created:				2008-04-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=		upx
PORTVERSION=		3.02
PORTREVISION=		1
CATEGORIES=		archivers linux
PKGNAMEPREFIX=		linux-f8-
DISTNAME=		${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=		emulation@FreeBSD.org
COMMENT=		UPX, a high-performance executable packer (Linux Fedora 8)

CONFLICTS=		linux-upx-[0-9]* linux-f10-upx-[0-9]*

USE_LINUX_RPM=		yes
USE_LINUX_APPS=		ucl
LINUX_DIST_VER=		8
RPMVERSION=		1.fc8
BRANDELF_FILES=		usr/bin/upx

PLIST_FILES=		usr/bin/upx usr/share/man/man1/upx.1.gz
DOCSDIR=		${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=		BUGS COPYING LICENSE NEWS PROJECTS README README.1ST \
			THANKS TODO elf-to-mem.txt filter.txt loader.txt selinux.txt
DESCR=			${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
