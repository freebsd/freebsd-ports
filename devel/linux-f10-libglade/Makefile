# New ports collection makefile for: linux-libglade
# Date created:		2001.02.08
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libglade
.if (${MACHINE_ARCH} == "i386")
PORTVERSION=	0.6
.elif (${MACHINE_ARCH} == "alpha")
PORTVERSION=	0.7
.endif
CATEGORIES=	devel linux

MAINTAINER=	taoka@FreeBSD.org

RPM_SET=	libglade-${PORTVERSION}-1.${MACHINE_ARCH}.rpm

.include "../../x11-toolkits/linux-gtk/Makefile"
