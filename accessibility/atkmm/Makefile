# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/accessibility/atkmm/Makefile,v 1.12 2012/09/01 23:02:08 mezz Exp $

PORTNAME=	atkmm
PORTVERSION=	2.22.6
PORTREVISION=	1
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrapper for ATK API library

USES=		gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	atk glibmm
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-documentation

.include <bsd.port.mk>
