# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>

PORTNAME=	komposter
DISTVERSION=	g20201211
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Lightweight music composing system

LICENSE=	GPLv2

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		autoreconf compiler:c++11-lang gl libtool openal pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	electronoora
GH_TAGNAME=	f75eeb7
USE_GL=		gl glu glut
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-optimizations \
		--disable-silent-rules \
		--without-auto-arch

CFLAGS_i386=	-Wl,-znotext

DESKTOP_ENTRIES=	"Komposter" \
			"${COMMENT}" \
			"${DATADIR}/komposter_icon.png" \
			"${PORTNAME}" \
			"Audio;" \
			false

OPTIONS_DEFINE=	EXAMPLES

post-extract:
	@${RM} ${WRKSRC}/resources/libfreetype* ${WRKSRC}/resources/komposter.*
	@${RM} -rf ${WRKSRC}/resources/GLUT.framework

post-install:
	(cd ${WRKSRC}/resources && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
