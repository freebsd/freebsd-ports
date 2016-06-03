# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	wmminichess
PORTVERSION=	0.8
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	AFTERSTEP/apps/miniCHESS/ \
		http://tigr.net/afterstep/download/miniCHESS/
DISTNAME=	miniCHESS-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window Maker chess dockapp game

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

LICENSE=	GPLv2+

RUN_DEPENDS=	${LOCALBASE}/bin/gnuchess:games/gnuchess

USE_XORG=	xpm

CPPFLAGS+=	-I${LOCALBASE}/include -DENGINE=\"${LOCALBASE}/bin/gnuchessx\"
LDFLAGS+=	-L${LOCALBASE}/lib -lXpm -lXext -lX11

PORTDOCS=	README TODO
PLIST_FILES=	bin/minichess

OPTIONS_DEFINE=	DOCS

do-build:
	(cd ${WRKSRC} \
		&& ${CC} ${CFLAGS} ${CPPFLAGS} -o minichess *.c ${LDFLAGS})

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} minichess ${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
