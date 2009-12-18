# New ports collection makefile for:	gnapster
# Date created:		24 December 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnapster
PORTVERSION=	1.5.0
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME client for the online mp3 community called napster

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	imlib
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomelibs}!=""
USE_GNOME+=	gnomehack gnomelibs
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share
PKGNAMESUFFIX=	-gnome
.else
CONFIGURE_ARGS+=--disable-gnome --disable-gdk-pixbuf
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
