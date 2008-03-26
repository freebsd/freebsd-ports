# New ports collection makefile for:	trackballs
# Date created:				21 November 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	trackballs
PORTVERSION=	1.1.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SDL-based Marble Madness clone

LIB_DEPENDS=	guile.18:${PORTSDIR}/lang/guile
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_GL=		yes
USE_SDL=	image mixer sdl ttf
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	desktopfileutils
INSTALLS_ICONS=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_ARGS=	mkinstalldirs="${MKDIR}"

MAN6=		${PORTNAME}.6

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib -lintl

post-patch:
	@${REINPLACE_CMD} -e 's|install -D|$$(INSTALL)|' \
		${WRKSRC}/share/Makefile.in

post-install:
	-@update-desktop-database

.include <bsd.port.mk>
