# New ports collection makefile for: linux-imlib
# Date created:		01/09/18
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	imlib
PORTVERSION=	1.9.7
CATEGORIES=	graphics linux
.if (${MACHINE_ARCH} == "i386")
MASTER_SITES= ftp://ftp.redhat.com/pub/redhat/linux/6.1/en/os/i386/RedHat/RPMS/
.elif (${MACHINE_ARCH} == "alpha")
MASTER_SITES= ftp://ftp.redhat.com/pub/redhat/linux/6.1/en/os/alpha/RedHat/RPMS/
.endif

MAINTAINER=	taoka@FreeBSD.org

RPM_SET=	imlib-${PORTVERSION}-1.${MACHINE_ARCH}.rpm

.include "../../x11-toolkits/linux-gtk/Makefile"
