# New ports collection makefile for:	Mesa3 for Linux compat
# Date created:		May 18 2000
# Whom:			Masahiro TAKEMURA
#
# $FreeBSD$
#

PORTNAME=	mesa
PORTVERSION=	3.4.2
PORTREVISION=	6
CATEGORIES=	graphics linux
MASTER_SITES=	ftp://ftp.leo.org/pub/comp/os/unix/linux/redhat/redhat/updates/7.2/en/os/i386/ \
		ftp://ftp.uni-kl.de/pub/linux/redhat/redhat/updates/7.2/en/os/i386/ \
		ftp://ftp.icm.edu.pl/mirrors/ftp.redhat.com/pub/redhat/linux/updates/7.2/en/os/i386/ \
		ftp://ftp.rediris.es/pub/linux/distributions/redhat/redhat/linux/updates/7.2/en/os/i386/ \
		ftp://sunsite.cnlab-switch.ch/mirror/redhat/linux/updates/7.2/en/os/i386/ \
		ftp://ftp.dulug.duke.edu/pub/redhat/linux/updates/7.2/en/os/i386/ \
		ftp://mirror.sit.wisc.edu/mirrors/linux/distributions/redhat/updates/7.2/en/os/i386/

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	A graphics library similar to SGI's OpenGL, used from Linux programs

DEPRECATED=	Superceded by graphics/linux_dri
EXPIRATION_DATE=2005-10-01

USE_XLIB=	yes
BASEVERSION=7.2
ONLY_FOR_ARCHS=	i386
PLIST=		${PKGDIR}/pkg-plist
MD5_FILE=	${PKGDIR}/distinfo
RPM_SET=	Mesa-3.4.2-10.i386.rpm

.include "../../x11-toolkits/linux-gtk/Makefile"
