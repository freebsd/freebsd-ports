# New ports collection makefile for:	linux-sdl
# Date created:				8 October 2001
# Whom:                         Martin Matuska <martin@tradex.sk>
# Based on:		emulators/linux_base by marcel@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	sdl
PORTVERSION=	1.2.5
PORTREVISION=	1
CATEGORIES=	devel linux
MASTER_SITES=	http://www.libsdl.org/release/ \
		ftp://ftp.icm.edu.pl/vol/rzm9/linux-pld/pool/s/SDL/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME:U}-${PORTVERSION:S/.1$/-1/}-1.${MACHINE_ARCH}
EXTRACT_SUFX=	.rpm
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform multi-media development API (linux version)

BUILD_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm

USE_LINUX_PREFIX=	yes
LDCONFIG_LINUX=	${LINUXBASE}/sbin/ldconfig

ONLY_FOR_ARCHS=	i386 alpha
DIST_SUBDIR=	rpm
NO_BUILD=	yes
NO_FILTER_SHLIBS=	yes
PLIST=		${MASTERDIR}/pkg-plist.${MACHINE_ARCH}
MD5_FILE=	${MASTERDIR}/distinfo.${MACHINE_ARCH}

DBPATH=		/var/lib/rpm
RPMFLAGS=	--ignoreos --root ${PREFIX} --dbpath ${DBPATH} \
		--nodeps --replacepkgs
RPMDIR=		${DISTDIR}/${DIST_SUBDIR}

do-install:
	@${LOCALBASE}/bin/rpm -U ${RPMFLAGS} ${RPMDIR}/${DISTFILES}
	@${LDCONFIG_LINUX}

.include <bsd.port.mk>
