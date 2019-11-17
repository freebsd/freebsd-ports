# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	taisei
PORTVERSION=	1.2
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open source Touhou clone

LICENSE=	MIT CC0-1.0 PD
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libzip.so:archivers/libzip

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}-project

USES=		compiler:c11 desktop-file-utils meson pkgconfig python:3.6+,build sdl shebangfix shared-mime-info
SHEBANG_FILES=	scripts/*.py
MESON_ARGS=	-Dversion_fallback=${PORTVERSION} -Db_lto=false
USE_SDL=	sdl2 ttf2 mixer2

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=rst2html5.py:textproc/py-docutils
DOCS_MESON_TRUE=docs

post-install:
	@${RM} ${STAGEDIR}${DOCSDIR}/COPYING.txt

.include <bsd.port.mk>
