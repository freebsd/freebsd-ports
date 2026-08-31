PORTNAME=	variety
PORTVERSION=	0.9.1
PORTREVISION=	0
CATEGORIES=	graphics

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Wallpaper changer
WWW=		https://github.com/varietywalls/variety

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=26.2:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-distutils-extra>=2.38:devel/py-python-distutils-extra@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-gettext>=0.1.3_1:devel/py-setuptools-gettext@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.48.0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libgexiv2.so:graphics/gexiv2 \
		libnotify.so:devel/libnotify
RUN_DEPENDS=	${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.3.2:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>=5.0.6:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dbus>=1.1.1_1:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0.9:www/py-httplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=3.4.1_1:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=7.0.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycairo>=1.10.0:graphics/py-pycairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		bash>=4.3.33:shells/bash \
		ca_root_nss>=3.17.4:security/ca_root_nss \
		coreutils>=8.23:sysutils/coreutils \
		yelp>=3.14.1:x11/yelp

USES=		desktop-file-utils gettext-tools gnome magick:run python \
		shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	varietywalls
USE_GNOME=	gdkpixbuf gtk30 intltool pygobject3:run
USE_PYTHON=	autoplist noflavors pep517

SHEBANG_FILES=	data/scripts/*

PLIST_FILES=	share/applications/variety.desktop \
		share/icons/hicolor/22x22/apps/variety-indicator-dark.png \
		share/icons/hicolor/22x22/apps/variety-indicator.png \
		share/icons/hicolor/scalable/apps/variety.svg
post-patch:
	@(cd ${WRKSRC} && ${REINPLACE_CMD} -E -i '' \
		-e 's,/usr(/share/backgrounds),${LOCALBASE}\1,1' \
		data/config/variety.conf po/*.po* \
		data/ui/PreferencesVarietyDialog.ui \
		variety/Options.py variety/ThumbsWindow.py \
		variety/VarietyWindow.py)

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/variety.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor
	(cd ${WRKSRC}/data/icons && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/icons/hicolor)

.include <bsd.port.mk>
