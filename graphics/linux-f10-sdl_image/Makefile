# New ports collection makefile for:	linux-sdl_image
# Date created:				09 July 2004
# Whom:                         	Nicola Vitale <nivit@email.it>
# Based on:				devel/linux-sdl12 by martin@tradex.sk
#
# $FreeBSD$
#

PORTNAME=	sdl_image
PORTVERSION=	1.2.4
CATEGORIES=	graphics linux
MASTER_SITES=	http://www.libsdl.org/projects/SDL_image/release/
PKGNAMEPREFIX=	linux-
DISTNAME=	SDL_image-${PORTVERSION}-1.${MACHINE_ARCH}
EXTRACT_SUFX=	.rpm
EXTRACT_ONLY=

MAINTAINER=	nivit@users.sourceforge.net
COMMENT=	A simple library to load images as SDL interfaces (linux version)

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libSDL-1.2.so.0:${PORTSDIR}/devel/linux-sdl12
BUILD_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm

USE_LINUX=		yes
USE_LINUX_PREFIX=	yes
LDCONFIG_LINUX=	${LINUXBASE}/sbin/ldconfig

ONLY_FOR_ARCHS=	i386
DIST_SUBDIR=	rpm
NO_BUILD=	yes

DBPATH=		/var/lib/rpm
RPMFLAGS=	--ignoreos --root ${PREFIX} --dbpath ${DBPATH} \
		--nodeps --replacepkgs
.if defined(NOPORTDOCS)
RPMFLAGS+=	--excludedocs
.endif
RPMDIR=		${DISTDIR}/${DIST_SUBDIR}

do-install:
	@${LOCALBASE}/bin/rpm -U ${RPMFLAGS} ${RPMDIR}/${DISTFILES}
	@${LDCONFIG_LINUX}

.include <bsd.port.mk>
