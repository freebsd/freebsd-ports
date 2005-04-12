# New ports collection makefile for:	glob2
# Date created:		Wed 21 apr 2004
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=		glob2
PORTVERSION=		0.8.6
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=		thierry@FreeBSD.org
COMMENT=		Globulation 2 - a free and innovative strategy game

LIB_DEPENDS=		vorbis.3:${PORTSDIR}/audio/libvorbis	\
			freetype.9:${PORTSDIR}/print/freetype2

USE_SDL=		image net sdl
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=		CFLAGS="${CFLAGS} -I${LOCALBASE}/include"	\
			LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
USE_GCC=		3.4

PLIST_FILES=		bin/glob2

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=			"Does not build on alpha"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/glob2 ${PREFIX}/bin

.include <bsd.port.post.mk>
