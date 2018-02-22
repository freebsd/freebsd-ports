# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	variety
PORTVERSION=	0.5.4
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	https://launchpad.net/variety/trunk/${PORTVERSION}/+download/ \
		http://nivit.altervista.org/FreeBSD/ports/distfiles/
DISTNAME=	variety_${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Wallpaper changer

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-distutils-extra>=2.38:devel/py-python-distutils-extra@${FLAVOR}  \
		intltool-update:textproc/intltool
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.3.2:www/py-beautifulsoup@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cairo>=1.10.0:graphics/py-cairo@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>=5.0.6:devel/py-configobj@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycurl>=7.19.5.1:ftp/py-pycurl@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dbus>=1.1.1_1:devel/py-dbus@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}exiv2>=0.3.2_3:graphics/py-exiv2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0.9:www/py-httplib2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=2.6.0:graphics/py-pillow@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=3.4.1_1:devel/py-lxml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.8.0:devel/py-six@${FLAVOR} \
		ImageMagick>=6.9.0.4,1:graphics/ImageMagick \
		bash>=4.3.33:shells/bash \
		ca_root_nss>=3.17.4:security/ca_root_nss \
		coreutils>=8.23:sysutils/coreutils \
		gsettings:devel/glib20 \
		notify-send:devel/libnotify \
		pango>=1.36.8:x11-toolkits/pango \
		webkit-gtk3>=2.4.8:www/webkit-gtk3 \
		yelp>=3.14.1:x11/yelp

SHEBANG_FILES=	bin/variety data/scripts/*

USES=	desktop-file-utils gettext python:2.7 shebangfix gnome
USE_GNOME=	pygobject3:run
USE_PYTHON=	distutils

WRKSRC=	${WRKDIR}/variety

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

.include <bsd.port.pre.mk>

# PYDISTUTILS_INSTALLNOSINGLE is deprecated so...
PYDISTUTILS_INSTALLARGS:=	${PYDISTUTILS_INSTALLARGS:N--single-version-externally-managed}

.include <bsd.port.post.mk>
