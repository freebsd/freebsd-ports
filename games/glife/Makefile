# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glife
PORTVERSION=	0.2.1
PORTREVISION=	11
CATEGORIES=	games gnome
MASTER_SITES=	SF
DISTNAME=	gLife-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Conway's Game of Life for GNOME

GNU_CONFIGURE=	yes
USES=        pathfix
USE_GNOME=	gnomeprefix libglade
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		s|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
