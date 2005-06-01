# New ports collection makefile for:	guilib
# Date created:				20 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	guilib
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/projects/GUIlib/src/
DISTNAME=	GUIlib-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A very simple GUI framework for use with SDL

USE_SDL=	sdl
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-release $$(LT_RELEASE)||g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
