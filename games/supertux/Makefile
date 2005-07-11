# New ports collection makefile for:	supertux
# Date created:		2004-04-17
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	supertux
PORTVERSION=	0.1.3
CATEGORIES=	games
MASTER_SITES=	http://download.berlios.de/supertux/

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Super Tux is a side-scroller similar to Super Mario Brothers

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_SDL=	image mixer
USE_GL=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--disable-debug
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|SDL/|SDL11/|' \
		${WRKSRC}/src/type.h

.include <bsd.port.post.mk>
