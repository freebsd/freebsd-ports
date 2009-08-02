# New ports collection makefile for:	gnomememoryblocks
# Date created:				10th July 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomememoryblocks
PORTVERSION=	0.2
PORTREVISION=	6
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnome-memblocks
DISTNAME=	gnome-memblocks-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Memory Blocks game for GNOME

USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs gdkpixbuf
USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		s|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|games\.|games:| ; s|2111|2555|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
