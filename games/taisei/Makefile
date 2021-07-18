PORTNAME=	taisei
PORTVERSION=	1.3.2
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open source Touhou clone

LICENSE=	MIT CC0-1.0 PD
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libzip.so:archivers/libzip \
		libwebp.so:graphics/webp \
		libfreetype.so:print/freetype2 \
		libopusfile.so:audio/opusfile \
		libcglm.so:math/cglm
BUILD_DEPENDS=	glslc:graphics/shaderc

USE_GITHUB=	yes
GH_ACCOUNT=	taisei-project
GH_TUPLE=	taisei-project:SDL_GameControllerDB:74e31d7:gamecontrollerdb/external/gamecontrollerdb

USES=		compiler:c11 desktop-file-utils meson pkgconfig \
		python:3.6+,build sdl ssl shebangfix shared-mime-info
SHEBANG_FILES=	scripts/*.py
MESON_ARGS=	-Dversion_fallback=${PORTVERSION} -Db_lto=false
MESON_ARGS+=	--wrap-mode=nofallback
MESON_ARGS+=	-DOPENSSLLIB="${OPENSSLLIB}" -DOPENSSLINC="${OPENSSLINC}"
USE_SDL=	sdl2 ttf2 mixer2

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=rst2html5.py:textproc/py-docutils
DOCS_MESON_TRUE=docs

post-install:
	@${RM} ${STAGEDIR}${DOCSDIR}/COPYING.txt

.include <bsd.port.mk>
