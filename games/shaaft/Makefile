# New ports collection makefile for:  	shaaft
# Date created:       		02 Jan 2004
# Whom:  			krion@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	shaaft
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sourceforge/criticalmass
DISTNAME=	Shaaft-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shaaft is an OpenGL 3D falling block game similar to Blockout

USE_BZIP2=	yes
USE_SDL=	mixer image sdl
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN6=		${PORTNAME}.6

.include <bsd.port.mk>
