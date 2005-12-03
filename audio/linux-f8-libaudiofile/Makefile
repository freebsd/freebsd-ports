# New ports collection makefile for: linux-libaudiofile
# Date created:		01/09/18
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libaudiofile
PORTVERSION=	0.2.6
PORTREVISION=	0
CATEGORIES=	audio linux
MASTER_SITES=	${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR=	3/i386/os/Fedora/RPMS 3/SRPMS

.if defined(PACKAGE_BUILDING)
SRC_DISTFILES+=		audiofile-${PORTVERSION}-1.src.rpm
ALWAYS_KEEP_DISTFILES=	yes
.endif

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	RPM of audiofile

RPM_SET=	audiofile-${PORTVERSION}-1.${ARCH}.rpm

.include "../../x11-toolkits/linux-gtk/Makefile"
