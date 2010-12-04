# New ports collection makefile for:	guilib
# Date created:				20 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	guilib
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/projects/GUIlib/src/
DISTNAME=	GUIlib-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A very simple GUI framework for use with SDL

USE_SDL=	sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	 aclocal:env

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

post-configure:
	@${REINPLACE_CMD} -e 's|^ACLOCAL =.*|ACLOCAL = ${ACLOCAL}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
