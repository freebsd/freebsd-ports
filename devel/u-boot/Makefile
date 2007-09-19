# New ports collection makefile for:   u-boot-mkimage
# Date created:        18 September 2007
# Whom:                Marius Nuennerich <mn@bsdgroup.de>
#
# $FreeBSD$
#

PORTNAME=	u-boot
PORTVERSION=	1.2.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.denx.de/pub/u-boot/ \
		http://people.bsdgroup.de/~as/freebsd/distfiles/
PKGNAMESUFFIX=	-mkimage

MAINTAINER=	mn@bsdgroup.de
COMMENT=	The mkimage utility of the u-boot bootloader

USE_BZIP2=	yes

PLIST_FILES=	bin/mkimage

do-patch:
	@${CP} ${PATCHDIR}/BSDmakefile ${WRKSRC}/tools

do-build:
	@cd ${WRKSRC}/tools && make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/mkimage ${PREFIX}/bin

.include <bsd.port.mk>
