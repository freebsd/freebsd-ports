# New ports collection makefile for: linux-tiff
# Date created:		2001.02.08
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	tiff
PORTVERSION=	3.5.5
PORTREVISION=	2
CATEGORIES=	graphics linux

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	RPM of tiff lib

FORBIDDEN=	http://vuxml.FreeBSD.org/f6680c03-0bd8-11d9-8a8a-000c41e2cdad.html \
		http://vuxml.FreeBSD.org/8f86d8b5-6025-11d9-a9e7-0001020eed82.html \
		http://vuxml.FreeBSD.org/fc7e6a42-6012-11d9-a9e7-0001020eed82.html \
		http://vuxml.FreeBSD.org/14e8f315-600e-11d9-a9e7-0001020eed82.html \
		http://vuxml.FreeBSD.org/3897a2f8-1d57-11d9-bc4a-000c41e2cdad.html
DEPRECATED=	${FORBIDDEN}
EXPIRATION_DATE=2005-02-10

RPM_SET=	libtiff-${PORTVERSION}-10.${MACHINE_ARCH}.rpm

.include "../../x11-toolkits/linux-gtk/Makefile"
