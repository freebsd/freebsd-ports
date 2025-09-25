PORTNAME=	zathura
DISTVERSION=	0.5.13
CATEGORIES=	graphics print
MASTER_SITES=	https://pwmt.org/projects/zathura/download/

MAINTAINER=	quentin.stievenart@gmail.com
COMMENT=	Customizable lightweight pdf viewer
WWW=		https://pwmt.org/projects/zathura/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgirara-gtk3.so:x11-toolkits/girara \
		libjson-glib-1.0.so:devel/json-glib

USES=		compiler:c17 gettext gnome meson pkgconfig sqlite tar:xz
USE_GNOME=	glib20 gtk30
MESON_ARGS=	-Dlandlock=disabled \
		-Dseccomp=disabled \
		-Dtests=disabled

OPTIONS_DEFINE=		MANPAGES SYNCTEX
OPTIONS_DEFAULT=	MANPAGES SYNCTEX
OPTIONS_SUB=		yes

SYNCTEX_DESC=	Direct and reverse synchronisation support with SyncTeX

MANPAGES_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR}
MANPAGES_USES=		python:build
MANPAGES_MESON_ENABLED=	manpages

SYNCTEX_BUILD_DEPENDS=	tex-synctex>0:devel/tex-synctex
SYNCTEX_RUN_DEPENDS=	${SYNCTEX_BUILD_DEPENDS}
SYNCTEX_MESON_ENABLED=	synctex

post-patch-MANPAGES-on:
	@${REINPLACE_CMD} -e 's|^/etc|${PREFIX}/etc|' ${WRKSRC}/doc/man/zathurarc.5.rst

.include <bsd.port.mk>
