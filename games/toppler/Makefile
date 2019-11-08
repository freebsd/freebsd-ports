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

USES=		gmake localbase sdl
USE_SDL=	mixer sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var/games

SCOREFILE=	/var/games/toppler/toppler.hsc

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

post-install:
	@${MV} ${STAGEDIR}${SCOREFILE} ${STAGEDIR}${SCOREFILE}.sample

.include <bsd.port.mk>
