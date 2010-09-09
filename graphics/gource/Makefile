# New ports collection makefile for:   	gource
# Date created:         Nov 25 2009
# Whom:                 demon@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gource
PORTVERSION=	0.28
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	OpenGL-based 3D visualisation tool for source control repositories

LIB_DEPENDS=	SDL_image:${PORTSDIR}/graphics/sdl_image \
		ftgl:${PORTSDIR}/graphics/ftgl \
		pcre:${PORTSDIR}/devel/pcre \
		GLEW:${PORTSDIR}/graphics/glew

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MANCOMPRESSED=	yes

MAN1=		gource.1

.include <bsd.port.mk>
