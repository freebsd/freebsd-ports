PORTNAME=	variety
PORTVERSION=	0.8.13
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Wallpaper changer
WWW=		https://github.com/varietywalls/variety

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-distutils-extra>=2.38:devel/py-python-distutils-extra@${PY_FLAVOR}
LIB_DEPENDS=	libgexiv2.so:graphics/gexiv2 \
		libnotify.so:devel/libnotify
RUN_DEPENDS=	${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.3.2:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cairo>=1.10.0:graphics/py-cairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>=5.0.6:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dbus>=1.1.1_1:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0.9:www/py-httplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml5>=3.4.1_1:devel/py-lxml5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=7.0.0:graphics/py-pillow@${PY_FLAVOR} \
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
USE_PYTHON=	autoplist distutils noflavors

SHEBANG_FILES=	bin/variety data/scripts/*

PLIST_FILES=	share/variety/config/quotes.txt

post-patch:
	@(cd ${WRKSRC} && ${REINPLACE_CMD} \
		-i '' \
		-E -e 's,%%LOCALBASE%%,${LOCALBASE},1' \
		-e 's,%%PREFIX%%,${PREFIX},1' \
		-e 's,/usr(/share/backgrounds),${LOCALBASE}\1,1' \
		data/config/variety.conf po/*.po* \
		data/ui/PreferencesVarietyDialog.ui \
		variety/Options.py variety/ThumbsWindow.py \
		variety/__init__.py variety/VarietyWindow.py)

post-install:
	${INSTALL_DATA} ${WRKSRC}/variety/plugins/builtin/quotes/quotes.txt \
		${STAGEDIR}/${DATADIR}/config/quotes.txt

.include <bsd.port.pre.mk>

# PYDISTUTILS_INSTALLNOSINGLE is deprecated so...
PYDISTUTILS_INSTALLARGS:=	${PYDISTUTILS_INSTALLARGS:N--single-version-externally-managed}

.include <bsd.port.post.mk>
