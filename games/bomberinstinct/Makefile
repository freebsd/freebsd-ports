# New ports collection makefile for:	bomberinstinct
# Date created:				28 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bomberinstinct
PORTVERSION=	0.8.9
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Bomber%20Instinct/BomberInstinct-${PORTVERSION}
DISTNAME=	BomberInstinct-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A nice Bomberman-like multiplayer game

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_SDL=	mixer sdl
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_PERL5_BUILD=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS} -lintl"

pre-patch:
	@${FIND} ${WRKSRC} -name "*.[ch]" | \
		${XARGS} ${PERL} -pi -e 's|<SDL/|<|g'

.include <bsd.port.mk>
