# Created by: John Hixson <john@pcbsd.org>
# $FreeBSD$

PORTNAME=	pithos
PORTVERSION=	1.5.0
CATEGORIES=	audio

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Pandora client for the GNOME desktop

LICENSE=	GPLv3

BUILD_DEPENDS=	appstream-util:devel/appstream-glib \
		desktop-file-validate:devel/desktop-file-utils \
		help2man:misc/help2man

RUN_DEPENDS=	gnome-keyring:security/gnome-keyring \
		gsettings-desktop-schemas>3.0.0:devel/gsettings-desktop-schemas \
		${PYTHON_SITELIBDIR}/dbus/__init__.py:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/gi/overrides/Gst.py:multimedia/py-gstreamer1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylast>0:audio/py-pylast@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/xdg/__init__.py:devel/py-xdg@${PY_FLAVOR}

USES=	pkgconfig:run python:3.4+ gnome meson ninja gettext shebangfix

USE_GITHUB=	yes
USE_GNOME=	glib20
USE_GSTREAMER1=	core good bad soup

GLIB_SCHEMAS=	io.github.Pithos.gschema.xml

INSTALLS_ICONS=	yes

SHEBANG_FILES=	bin/pithos.in docs/conf.py meson_post_install.py

post-patch:
	${REINPLACE_CMD} -i '' -e \
		"s|\(\([^.]\)pkgdatadir\)|\2'${PYTHONPREFIX_SITELIBDIR}'|g" \
		${WRKSRC}/meson.build
	${REINPLACE_CMD} -i '' -e "s|'pithos', ||" \
		${WRKSRC}/meson_post_install.py

pre-install:
	${MKDIR} ${STAGEDIR}/${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/glib-2.0/schemas
	${MKDIR} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
