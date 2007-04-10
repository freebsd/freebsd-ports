# New ports collection makefile for:	guilib
# Date created:				20 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	guilib
PORTVERSION=	1.2.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/projects/GUIlib/src/
DISTNAME=	GUIlib-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A very simple GUI framework for use with SDL

USE_SDL=	sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	 aclocal:19

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-release $$(LT_RELEASE)||g' ${WRKSRC}/Makefile.in

post-configure:
	@${REINPLACE_CMD} -e 's|^ACLOCAL =.*|ACLOCAL = ${ACLOCAL}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
