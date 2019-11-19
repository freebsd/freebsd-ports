# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	taisei
PORTVERSION=	1.3.1
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
		libopusfile.so:audio/opusfile

USE_GITHUB=	yes
GH_ACCOUNT=	taisei-project
GH_TUPLE=	taisei-project:cglm:ee15b56:cglm/external/cglm \
		taisei-project:SDL_GameControllerDB:5651071:gamecontrollerdb/external/gamecontrollerdb

USES=		compiler:c11 desktop-file-utils meson pkgconfig \
		python:3.6+,build sdl shebangfix shared-mime-info
SHEBANG_FILES=	scripts/*.py
MESON_ARGS=	-Dversion_fallback=${PORTVERSION} -Db_lto=false -Duse_libcrypto=false
USE_SDL=	sdl2 ttf2 mixer2
USE_GCC=	yes

CPPFLAGS+=	-D__BSD_VISIBLE

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=rst2html5.py:textproc/py-docutils
DOCS_MESON_TRUE=docs

post-install:
	@${RM} ${STAGEDIR}${DOCSDIR}/COPYING.txt

post-patch:
	@${REINPLACE_CMD} -e "/^dep_crypto/ s|.*|\
		dep_crypto = declare_dependency(link_with:shared_library('${OPENSSLLIB}/libcrypto.so'), include_directories:include_directories('${OPENSSLINC}'))|" \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
