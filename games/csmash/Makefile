# ex:ts=8
# Ports collection makefile for:	csmash
# Date created:			Nov 11, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	csmash
PORTVERSION=	0.6.6
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cannonsmash

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 3D tabletennis game

USE_SDL=	image mixer sdl
USE_GL=		yes
USE_GNOME=	gnometarget gtk20
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|/games/|/|g'

.include <bsd.port.mk>
