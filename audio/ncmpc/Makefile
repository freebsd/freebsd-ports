PORTNAME=	ncmpc
PORTVERSION=	0.41
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://www.musicpd.org/download/ncmpc/0/

MAINTAINER=	laurent@nilio.ca
COMMENT=	Ncurses client for the musicpd

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libmpdclient.so:audio/libmpdclient \
		libpcre.so:devel/pcre

USES=		compiler:c++17-lang cpe iconv localbase:ldflags meson ncurses \
		pkgconfig tar:xz

CPE_VENDOR=	ncmpc_project

OPTIONS_DEFINE=		COLORS DOCS LYRICS MANPAGES NLS
OPTIONS_DEFAULT=	COLORS LYRICS MANPAGES
OPTIONS_SUB=		yes

COLORS_DESC=		Compile with color support
LYRICS_DESC=		Compile with lyrics screen

COLORS_MESON_TRUE=	colors

DOCS_IMPLIES=		MANPAGES
DOCS_MESON_TRUE=	html_manual

LYRICS_MESON_TRUE=	lyrics_screen

MANPAGES_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
MANPAGES_MAKE_ENV=	PYTHON=${PYTHON_CMD} \
			SPHINX=sphinx-build-${PYTHON_VER}
MANPAGES_MESON_TRUE=	manual
MANPAGES_USES=		python:build,3.6+

NLS_LDFLAGS=		-lintl
NLS_MESON_ENABLED=	nls
NLS_USES=		gettext

PORTDOCS=	*

.include <bsd.port.mk>
