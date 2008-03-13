# New ports collection makefile for:	toycars
# Date created:		15 Dec 2005
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	toycars
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Physics-based 2D racing game

LIB_DEPENDS=	openal.0:${PORTSDIR}/audio/openal \
		alut.1:${PORTSDIR}/audio/freealut

USE_SDL=	mixer image sdl
USE_GL=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}lib -L${X11BASE}/lib"

PORTDOCS=	README

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
