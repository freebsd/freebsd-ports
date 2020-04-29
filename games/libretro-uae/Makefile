# $FreeBSD$

PORTNAME=	libretro-uae
PORTVERSION=	0.20200313
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Libretro port of UAE

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake gl
USE_LDCONFIG=	yes
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_TAGNAME=	8333daa

PLIST_FILES=	libexec/libretro/puae_libretro.so

post-patch:
	${REINPLACE_CMD} 's/" GIT_VERSION/${GH_TAGNAME}"/' ${WRKSRC}/libretro/libretro.c

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/libexec/libretro;
	${INSTALL_LIB} $$(find ${WRKSRC}/${COREDIR}/ -name "*.so") ${STAGEDIR}/${PREFIX}/libexec/libretro;

.include <bsd.port.mk>
