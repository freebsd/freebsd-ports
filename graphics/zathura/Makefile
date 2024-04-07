PORTNAME=	zathura
DISTVERSION=	0.5.4
CATEGORIES=	graphics print
MASTER_SITES=	https://git.pwmt.org/pwmt/${PORTNAME}/-/archive/${DISTVERSION}/

MAINTAINER=	quentin.stievenart@gmail.com
COMMENT=	Customizable lightweight pdf viewer
WWW=		https://pwmt.org/projects/zathura/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libgirara-gtk3.so:x11-toolkits/girara

USES=		compiler:c11 desktop-file-utils gettext-tools:build gnome meson \
		ninja pkgconfig python
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30
MESON_ARGS=	-Dseccomp=disabled -Dtests=disabled -Dmanpages=disabled

OPTIONS_DEFINE=		MANPAGES SQLITE SYNCTEX
OPTIONS_DEFAULT=	MANPAGES SQLITE SYNCTEX
OPTIONS_SUB=		yes

MANPAGES_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=1.2.2,1:textproc/py-sphinx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR}
MANPAGES_MESON_ENABLED=	manpages

SQLITE_USES=		sqlite
SQLITE_MESON_ENABLED=	sqlite

SYNCTEX_DESC=		Direct and reverse synchronisation support with SyncTeX
SYNCTEX_BUILD_DEPENDS=	tex-synctex>=1.19.0:devel/tex-synctex
SYNCTEX_RUN_DEPENDS=	${SYNCTEX_BUILD_DEPENDS}
SYNCTEX_MESON_ENABLED=	synctex

.include <bsd.port.mk>
