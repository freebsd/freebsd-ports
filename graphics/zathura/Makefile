PORTNAME=	zathura
DISTVERSION=	0.5.2
PORTREVISION=	2
CATEGORIES=	graphics print
MASTER_SITES=	https://git.pwmt.org/pwmt/${PORTNAME}/-/archive/${DISTVERSION}/

MAINTAINER=	quentin.stievenart@gmail.com
COMMENT=	Customizable lightweight pdf viewer
WWW=		https://pwmt.org/projects/zathura/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=1.2.2,1:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR}
LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libgirara-gtk3.so:x11-toolkits/girara \
		libsynctex.so:devel/tex-synctex

USES=		compiler:c11 desktop-file-utils gettext-tools:build gnome meson \
		ninja pkgconfig python
USE_GNOME=	gdkpixbuf2 glib20 gtk30
MESON_ARGS=	-Dseccomp=disabled -Dtests=disabled

OPTIONS_DEFINE=		SQLITE SYNCTEX
OPTIONS_DEFAULT=	SQLITE SYNCTEX

SQLITE_USES=		sqlite
SQLITE_MESON_ENABLED=	sqlite

SYNCTEX_DESC=		Direct and reverse synchronisation support with SyncTeX
SYNCTEX_BUILD_DEPENDS=	tex-synctex>=1.19.0:devel/tex-synctex
SYNCTEX_RUN_DEPENDS=	${SYNCTEX_BUILD_DEPENDS}
SYNCTEX_MESON_ENABLED=	synctex

.include <bsd.port.mk>
