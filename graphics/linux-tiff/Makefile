# New ports collection makefile for: linux-tiff
# Date created:		2001.02.08
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	tiff
PORTVERSION=	3.6.1
PORTREVISION=	4
CATEGORIES=	graphics linux
MASTER_SITES=	${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR=	updates/3/${ARCH}
PKGNAMEPREFIX=	linux-

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	TIFF library, Linux/i386 binary

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libjpeg.so.62:${PORTSDIR}/graphics/linux-jpeg

ONLY_FOR_ARCHS=	amd64 i386
RPM_SET=	libtiff-${PORTVERSION}-10.fc3.${ARCH}.rpm

BINFILES=	fax2ps fax2tiff gif2tiff pal2rgb ppm2tiff ras2tiff raw2tiff \
		rgb2ycbcr thumbnail tiff2bw tiff2pdf tiff2ps tiff2rgba tiffcmp \
		tiffcp tiffdither tiffdump tiffinfo tiffmedian tiffset tiffsplit

.for file in ${BINFILES}
BRANDFILES+=	${PREFIX}/usr/bin/${file}
.endfor

post-install:
	@${BRANDELF} -t Linux ${BRANDFILES}

.include "../../x11-toolkits/linux-gtk/Makefile"
