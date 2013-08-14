# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	fishsupper
PORTVERSION=	0.1.6
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Guide a cat across a series of rivers, jumping from log to log

BUILD_DEPENDS=	${LOCALBASE}/include/boost/bind.hpp:${PORTSDIR}/devel/boost-libs

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl image mixer
USE_GL=		gl

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	README

DESKTOP_ENTRIES="Fish Supper" \
		"Guide a cat across a series of rivers, jumping from log to log" \
		"${DATADIR}/images/fs_image_30.png" \
		"fishsupper" \
		"Game;ArcadeGame;" \
		false

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
