PORTNAME=	freeciv21
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.2
CATEGORIES=	games
MASTER_SITES=	https://github.com/longturn/${PORTNAME}/releases/download/${DISTVERSIONFULL}/
DISTNAME=	${PORTNAME:S/^f/F/}-${DISTVERSIONFULL}

MAINTAINER=	tobias.rehbein@web.de
COMMENT=	Freeciv for the 21st century
WWW=		https://github.com/longturn/freeciv21

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdw.so:devel/elfutils \
		libunwind.so:devel/libunwind
RUN_DEPENDS=	${LOCALBASE}/share/fonts/libertinus/LibertinusSans-Regular.otf:x11-fonts/libertinus

USES=		cmake desktop-file-utils kde:5 lua pkgconfig python qt:5 \
		readline sdl sqlite

USE_KDE=	archive
USE_QT=		core gui network svg widgets buildtools:build qmake:build
USE_SDL=	mixer2 sdl2

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Git
CMAKE_OFF=	FREECIV_DOWNLOAD_FONTS

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=			DOCS MANPAGES NLS
OPTIONS_DEFAULT=		MANPAGES
OPTIONS_SUB=			yes
MANPAGES_BUILD_DEPENDS=		${PYTHON_PKGNAMEPREFIX}sphinx>=0:textproc/py-sphinx@${PY_FLAVOR}
MANPAGES_CMAKE_BOOL=		FREECIV_ENABLE_MANPAGES
MANPAGES_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Sphinx
NLS_USES=			gettext-runtime gettext-tools
NLS_CMAKE_BOOL=			FREECIV_ENABLE_NLS

post-install-DOCS-off:
	@${RM} -r ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
