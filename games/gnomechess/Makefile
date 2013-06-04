# Created by: Jeremy Lea <reg@shale.csir.co.za>
# $FreeBSD$

PORTNAME=	gnomechess
PORTVERSION=	0.3.3
PORTREVISION=	11
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/gnome-chess/0.3
DISTNAME=	gnome-chess-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GUI chess front-end to crafy, for the GNOME Desktop Environment

DEPRECATED=	Unsupported upstream
EXPIRATION_DATE=	2013-07-04

BUILD_DEPENDS=	crafty:${PORTSDIR}/games/crafty
RUN_DEPENDS=	crafty:${PORTSDIR}/games/crafty

USES=        pathfix
USE_GNOME=	gnomecanvas gnomeprefix libglade
USE_GMAKE=	yes
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ARGS=	XML_I18N_UPDATE="${TRUE}" XML_I18N_EXTRACT="${TRUE}"

.include <bsd.port.mk>
