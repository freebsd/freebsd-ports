# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	deadbeef-jack-plugin
DISTVERSION=	0.0.2011.03.22
CATEGORIES=	audio

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	JACK output plugin for DeaDBeeF music player

BUILD_DEPENDS=	${LOCALBASE}/include/deadbeef/deadbeef.h:audio/deadbeef
LIB_DEPENDS=	libjack.so:audio/jack
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	Alexey-Yakovenko
GH_PROJECT=	jack
GH_TAGNAME=	62d1e6a

PLIST_FILES=	lib/deadbeef/jack.so

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -std=c99 -fPIC -shared -Wall \
		-I${LOCALBASE}/include -L${LOCALBASE}/lib \
		-o jack.so jack.c -ljack

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/deadbeef
	${INSTALL_LIB} ${WRKSRC}/jack.so ${STAGEDIR}${PREFIX}/lib/deadbeef

.include <bsd.port.mk>
