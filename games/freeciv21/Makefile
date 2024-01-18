PORTNAME=	freeciv21
PORTVERSION=	${FC21_VERSION:S/^v//:S/-patch//}
CATEGORIES=	games
MASTER_SITES=	https://github.com/longturn/${PORTNAME}/releases/download/${FC21_VERSION}/
DISTNAME=	${PORTNAME:S/^f/F/}-${FC21_VERSION}

PATCH_SITES=	https://github.com/longturn/${PORTNAME}/commit/
PATCHFILES=	f48ff4982826447bb7a8dd3ffac0706a0dad8f44.patch \
		a8aa91533705fdb1a2e8bc08e7e09514ece3976f.patch \
		849164f9ef86e2c6a063540869173f30166da4a0.patch \
		18971d188d451a970c0cca9b4604efcba602ec65.patch \
		3fbe8a3f773289b577a2131f9d9282b3848765a1.patch \
		71c6e2f7144fb0b30ba01fcccdba8b0172664dad.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tobias.rehbein@web.de
COMMENT=	Freeciv for the 21st century
WWW=		https://github.com/longturn/freeciv21

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdw.so:devel/elfutils \
		libunwind.so:devel/libunwind
RUN_DEPENDS=	${LOCALBASE}/share/fonts/libertinus/LibertinusSans-Regular.otf:x11-fonts/libertinus

USES=		cmake desktop-file-utils kde:5 lua pkgconfig python:3.9+ qt:5 \
		readline sdl sqlite

USE_KDE=	archive
USE_QT=		core gui network svg widgets buildtools:build qmake:build
USE_SDL=	mixer2

FC21_VERSION=	v3.0-patch.2

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Git \
		CMAKE_DISABLE_FIND_PACKAGE_Sphinx
CMAKE_OFF=	FREECIV_DOWNLOAD_FONTS

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CMAKE_BOOL=	FREECIV_ENABLE_NLS

post-install-DOCS-off:
	@${RM} -r ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
