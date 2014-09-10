# Created by: Dom Mitchell <dom@happygiraffe.net>
# $FreeBSD$

PORTNAME=	toppler
PORTVERSION=	1.1.5
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Climb a tower and avoid monsters

LICENSE=	GPLv2

USE_SDL=	mixer sdl
USES=		gettext gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var/games

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
