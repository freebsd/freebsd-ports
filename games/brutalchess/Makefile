# New ports collection makefile for:   Brutalchess
# Date created:         2005-02-07
# Whom:                 Gustavo Perez Querol <gustau.perez@gmail.com>
#
# $FreeBSD$
#

PORTNAME=		brutalchess
PORTVERSION=		0.5.1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		${PORTNAME}-alpha-${PORTVERSION}-src

MAINTAINER=		gustau.perez@gmail.com
COMMENT=		Nice looking OpenGL chess game

WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}

CONFIGURE_TARGET=	--target=${ARCH}-unknown-freebsd${OSREL}

USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool:15

USE_GL=			yes
USE_SDL=		sdl image

pre-build:
	${CHMOD} 0755 ${WRKSRC}/install-sh

MANCOMPRESSED=		yes

.include <bsd.port.mk>
