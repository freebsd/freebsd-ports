# New ports collection makefile for: linux-libaudiofile
# Date created:		01/09/18
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libaudiofile
PORTVERSION=	0.1.9
CATEGORIES=	audio linux
.if (${MACHINE_ARCH} == "i386")
MASTER_SITES= ftp://ftp.redhat.com/pub/redhat/linux/6.1/en/os/i386/RedHat/RPMS/
.elif (${MACHINE_ARCH} == "alpha")
MASTER_SITES= ftp://ftp.redhat.com/pub/redhat/linux/6.1/en/os/alpha/RedHat/RPMS/
.endif

MAINTAINER=	taoka@FreeBSD.org

.if (${MACHINE_ARCH} == "i386")
RPM_SET=	audiofile-${PORTVERSION}-1.${MACHINE_ARCH}.rpm
.elif (${MACHINE_ARCH} == "alpha")
RPM_SET=	audiofile-${PORTVERSION}-2.${MACHINE_ARCH}.rpm
.endif

.include "../../x11-toolkits/linux-gtk/Makefile"
