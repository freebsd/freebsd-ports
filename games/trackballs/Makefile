# New ports collection makefile for:	trackballs
# Date created:				21 November 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	trackballs
PORTVERSION=	1.1.4
PORTREVISION=	14
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	SDL-based Marble Madness clone

LICENSE=	GPLv2

LIB_DEPENDS=	guile:${PORTSDIR}/lang/guile
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_GL=		gl
USE_SDL=	image mixer sdl ttf
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	desktopfileutils
INSTALLS_ICONS=	yes
MAKE_ARGS=	mkinstalldirs="${MKDIR}"

MAN6=	trackballs.6
MANCOMPRESSED=	no

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

post-patch:
	@${REINPLACE_CMD} -e 's|install -D|$$(INSTALL)|' \
		${WRKSRC}/share/Makefile.in

post-install:
	-@update-desktop-database

.include <bsd.port.mk>
