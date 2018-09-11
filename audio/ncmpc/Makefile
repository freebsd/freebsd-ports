# Created by: Mark Reidel <ports@mark.reidel.info>
# $FreeBSD$

PORTNAME=	ncmpc
PORTVERSION=	0.30
CATEGORIES=	audio
MASTER_SITES=	http://www.musicpd.org/download/ncmpc/0/

MAINTAINER=	laurent@nuxi.ca
COMMENT=	Ncurses client for the musicpd

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient

USES=		compiler:c++14-lang gnome iconv localbase meson ncurses pkgconfig tar:xz
USE_GNOME=	glib20

OPTIONS_DEFINE=		DOCS LYRICS MANPAGES NLS
OPTIONS_DEFAULT=	LYRICS MANPAGES
OPTIONS_SUB=		yes

LYRICS_DESC=		Compile with lyrics screen

DOCS_IMPLIES=		MANPAGES
DOCS_MESON_TRUE=	html_manual

LYRICS_MESON_TRUE=	lyrics_screen

MANPAGES_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR}
MANPAGES_MAKE_ENV=	PYTHON=${PYTHON_CMD} \
			SPHINX=sphinx-build-${PYTHON_VER}
MANPAGES_MESON_TRUE=	manual
MANPAGES_USES=		python:build

NLS_MESON_TRUE=		nls
NLS_USES=		gettext

.include <bsd.port.mk>
