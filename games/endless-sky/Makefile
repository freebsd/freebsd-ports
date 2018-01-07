# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	endless-sky
PORTVERSION=	0.9.8
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Space exploration and combat game similar to Escape Velocity

LICENSE=	GPLv3+ CC-BY-4.0 CC-BY-SA-3.0 CC-BY-SA-4.0 PD
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/license.txt

LIB_DEPENDS=	libpng.so:graphics/png \
		libmad.so:audio/libmad

USE_GITHUB=	yes

USES=		compiler:c++11-lib jpeg localbase:ldflags openal scons
USE_SDL=	sdl2
USE_GL=		gl glew
LLD_UNSAFE=	yes
INSTALLS_ICONS=	yes

PORTDATA=	*

post-build:
	@${REINPLACE_CMD} -e 's|/usr/local/|${PREFIX}/|; s|share/games|share|' \
		${WRKSRC}/source/Files.cpp

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${LN} -s ../icons/hicolor/32x32/apps/endless-sky.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
