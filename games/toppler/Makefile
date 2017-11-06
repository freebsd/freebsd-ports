# Created by: Dom Mitchell <dom@happygiraffe.net>
# $FreeBSD$

PORTNAME=	toppler
PORTVERSION=	1.1.6
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Climb a tower and avoid monsters

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext gmake localbase
USE_SDL=	mixer sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var/games

OPTIONS_DEFINE=	DOCS

SCOREFILE=	/var/games/toppler/toppler.hsc

post-install:
	@${MV} ${STAGEDIR}${SCOREFILE} ${STAGEDIR}${SCOREFILE}.sample

.include <bsd.port.mk>
