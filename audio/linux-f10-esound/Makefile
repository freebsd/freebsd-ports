# New ports collection makefile for: linux-esound
# Date created:		01/09/18
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	esound
CATEGORIES=	audio linux
.if (${MACHINE_ARCH} == "i386")
PORTVERSION=	0.2.14
.elif (${MACHINE_ARCH} == "alpha")
PORTVERSION=	0.2.17
.endif
.if (${MACHINE_ARCH} == "i386")
MASTER_SITES= ftp://ftp.redhat.com/pub/redhat/linux/6.1/en/os/i386/RedHat/RPMS/
.elif (${MACHINE_ARCH} == "alpha")
MASTER_SITES= ftp://ftp.redhat.com/pub/redhat/linux/6.1/en/os/alpha/RedHat/RPMS/
.endif

MAINTAINER=	taoka@FreeBSD.org

RPM_SET=	esound-${PORTVERSION}-1.${MACHINE_ARCH}.rpm

.include "../../x11-toolkits/linux-gtk/Makefile"

