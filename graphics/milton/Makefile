# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	milton
PORTVERSION=	1.6.0
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Infinite-canvas paint program

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	serge-rgb

USES=		cmake gl gnome
USE_GL=		gl
USE_GNOME=	gtk20
USE_SDL=	sdl2

PLIST_FILES=	bin/milton

post-patch:
	@${REINPLACE_CMD} -e 's:__linux__:__${OPSYS}__:' \
		${WRKSRC}/src/easytab.h

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/Milton \
		${STAGEDIR}${PREFIX}/bin/milton

.include <bsd.port.mk>
