# New ports collection makefile for:   sage
# Date created:        4 February 2005
# Whom:                Janni
#
# $FreeBSD$
#

PORTNAME=	sage
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	worldforge

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	OpenGL extension library

USE_SDL=	sdl
USE_GL=		yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack
CONFIGURE_ARGS=	--program-transform-name=
MAN3=		sage.3 sage_init.3

CFLAGS=		-I${X11BASE}/include
CONFIGURE_ENV=	"CFLAGS=${CFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|g; \
		s|-DSAGE_COMPILE||g' ${WRKSRC}/configure

.include <bsd.port.mk>
