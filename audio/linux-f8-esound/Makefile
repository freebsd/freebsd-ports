# New ports collection makefile for: linux-esound
# Date created:		01/09/18
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	esound
CATEGORIES=	audio linux
PORTVERSION=	0.2.35
PORTREVISION=	0
MASTER_SITES=	${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR=	3/i386/os/Fedora/RPMS 3/SRPMS

.if defined(PACKAGE_BUILDING)
SRC_DISTFILES+=	esound-${PORTVERSION}-2.src.rpm
ALWAYS_KEEP_DISTFILES=  yes
.endif

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	RPM of esound

NOT_FOR_ARCHS=	amd64

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libaudiofile.so.0:${PORTSDIR}/audio/linux-libaudiofile

RPM_SET=	esound-${PORTVERSION}-2.${MACHINE_ARCH}.rpm

.include "../../x11-toolkits/linux-gtk/Makefile"

