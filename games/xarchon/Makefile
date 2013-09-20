# Created by: Marc Fonvieille <blackend@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xarchon
PORTVERSION=	0.50
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.seul.org/pub/xarchon/ \
		http://xarchon.seul.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A chess-like strategy game with battle options

USE_GNOME=	esound gtk12
USE_GMAKE=	yes
USE_XORG=	x11 xpm ice
GNU_CONFIGURE=	yes

MAN6=	xarchon.6

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e '169s|^static ||' ${WRKSRC}/src/board.c
	@${REINPLACE_CMD} -e 's|Xarchon_Evolution::||' \
		${WRKSRC}/src/Xarchon_Genetic.hpp

NOT_FOR_ARCHS=	sparc64

.include <bsd.port.mk>
