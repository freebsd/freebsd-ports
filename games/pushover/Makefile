# New ports collection makefile for:	pushover
# Date created:		15 Nov 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pushover
PORTVERSION=	0.0.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Pushover/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Pushover Screenshot Pushover a lot of dominos

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer ttf
USE_LUA=	5.1

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e '/PKG_CONFIG/ s|lua5.1|lua-5.1|' \
		${WRKSRC}/configure
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/install-data-am/ s|install-dist_docDATA||' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
