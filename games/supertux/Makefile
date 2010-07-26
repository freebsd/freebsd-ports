# New ports collection makefile for:	supertux
# Date created:		2004-04-17
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	supertux
PORTVERSION=	0.1.3
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Super Tux is a side-scroller similar to Super Mario Brothers

USE_BZIP2=	yes
USE_SDL=	image mixer
USE_GL=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=		--disable-debug

post-patch:
	@${REINPLACE_CMD} -e 's,Menu::,,' ${WRKSRC}/src/menu.h

.include <bsd.port.mk>
