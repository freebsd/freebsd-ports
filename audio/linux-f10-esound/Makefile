# New ports collection makefile for: linux-esound
# Date created:		01/09/18
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	esound
CATEGORIES=	audio linux
PORTVERSION=	0.2.22
PORTREVISION=	4

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	RPM of esound

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libaudiofile.so.0:${PORTSDIR}/audio/linux-libaudiofile

RPM_SET=	esound-${PORTVERSION}-1.${MACHINE_ARCH}.rpm

.include "../../x11-toolkits/linux-gtk/Makefile"

