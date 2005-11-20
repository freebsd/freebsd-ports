# New ports collection makefile for: linux-jpeg
# Date created:         9 April 2000
# Whom:                 sada@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	jpeg
PORTVERSION=	6b.33
PORTREVISION=	0
CATEGORIES=	graphics linux
MASTER_SITES=	${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR=	3/${ARCH}/os/Fedora/RPMS

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	RPM of the JPEG lib

ONLY_FOR_ARCHS=	i386 amd64
RPM_SET=	libjpeg-6b-33.${ARCH}.rpm

post-install:
	@${BRANDELF} -t Linux ${PREFIX}/usr/bin/cjpeg ${PREFIX}/usr/bin/djpeg \
		${PREFIX}/usr/bin/jpegtran ${PREFIX}/usr/bin/rdjpgcom \
		${PREFIX}/usr/bin/wrjpgcom

.include "../../x11-toolkits/linux-gtk/Makefile"
