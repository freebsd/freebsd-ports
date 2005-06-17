# New ports collection makefile for: linux-ungif
# Date created:         22 November 2002
# Whom:                 Nakata Maho <maho@FreeBSD.org>
# $FreeBSD$
#
PORTNAME=	ungif
PORTVERSION=	4.1.0
PORTREVISION=	3
CATEGORIES=	graphics linux

MAINTAINTER=	maho@FreeBSD.org
COMMENT=	RPM of the ungif lib

.if (${MACHINE_ARCH} == "i386")
RPM_SET=	libungif-4.1.0-7.${MACHINE_ARCH}.rpm
.else
RPM_SET=	libungif-4.1.0-8.${MACHINE_ARCH}.rpm
.endif

.include "../../x11-toolkits/linux-gtk/Makefile"
