# Created by: Dom Mitchell <dom@happygiraffe.net>
# $FreeBSD$

PORTNAME=	toppler
PORTVERSION=	1.1.5
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Climb a tower and avoid monsters

LICENSE=	GPLv2

USE_SDL=	mixer sdl
USES=		gettext gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var/games

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

SCOREFILE=	/var/games/toppler/toppler.hsc

post-install:
	${MV} ${STAGEDIR}${SCOREFILE} ${STAGEDIR}${SCOREFILE}.sample

.include <bsd.port.mk>
