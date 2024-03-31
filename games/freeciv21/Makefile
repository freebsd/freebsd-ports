PORTNAME=	freeciv21
PORTVERSION=	${FC21_VERSION:S/^v//:S/-patch//}
CATEGORIES=	games
MASTER_SITES=	https://github.com/longturn/${PORTNAME}/releases/download/${FC21_VERSION}/
DISTNAME=	${PORTNAME:S/^f/F/}-${FC21_VERSION}

PATCH_SITES=	https://github.com/longturn/${PORTNAME}/commit/
PATCHFILES=	1c314496c1cabf6e582e10d8660bb1b31ae461d3.patch
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

FC21_VERSION=	v3.0-patch.4

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
