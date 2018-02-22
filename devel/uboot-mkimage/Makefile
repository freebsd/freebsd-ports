# Created by: Marius Nuennerich <mn@bsdgroup.de>
# $FreeBSD$

PORTNAME=	uboot
DISTVERSION=	2010.12
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.denx.de/pub/u-boot/ \
		http://people.bsdgroup.de/~as/freebsd/distfiles/
PKGNAMESUFFIX=	-mkimage
DISTNAME=	u-boot-${PORTVERSION}

MAINTAINER=	ray@FreeBSD.org
COMMENT=	The mkimage utility of the u-boot bootloader

DEPRECATED=	Use sysutils/u-boot-tools
EXPIRATION_DATE=2019-02-28

USES=	tar:bzip2
BUILD_WRKSRC=	${WRKSRC}/tools
MAKEFILE=	BSDmakefile

PLIST_FILES=	bin/mkimage

post-extract:
	${CP} ${PATCHDIR}/BSDmakefile ${WRKSRC}/tools

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/mkimage ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
