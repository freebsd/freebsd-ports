# New ports collection makefile for:	linux-sdl
# Date created:				8 October 2001
# Whom:                         Martin Matuska <martin@tradex.sk>
# Based on:		emulators/linux_base by marcel@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	sdl
PORTVERSION=	1.2.12
CATEGORIES=	devel linux
MASTER_SITES=	http://www.libsdl.org/release/ \
		ftp://ftp.icm.edu.pl/vol/rzm9/linux-pld/pool/s/SDL/
DISTNAME=	${PORTNAME:U}-${PORTVERSION:S/.1$/-1/}-1

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Cross-platform multi-media development API (linux version)

USE_LINUX_RPM=	yes
USE_XLIB=	yes
INSTALL_SHLIB=	yes

ONLY_FOR_ARCHS=	i386 amd64
DIST_SUBDIR=	rpm
PLIST=		${MASTERDIR}/pkg-plist.${LINUX_RPM_ARCH}
PLIST_SUB+=	SDLVER=${PORTVERSION}

.include <bsd.port.mk>
