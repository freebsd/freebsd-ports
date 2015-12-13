# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	variety
PORTVERSION=	0.5.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://launchpad.net/variety/trunk/${PORTVERSION}/+download/ \
		http://nivit.altervista.org/FreeBSD/ports/distfiles/
DISTNAME=	variety_${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Wallpaper changer

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}distutils-extra>=2.38:${PORTSDIR}/devel/py-distutils-extra  \
		intltool-update:${PORTSDIR}/textproc/intltool
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.3.2:${PORTSDIR}/www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}cairo>=1.10.0:${PORTSDIR}/graphics/py-cairo \
		${PYTHON_PKGNAMEPREFIX}configobj>=5.0.6:${PORTSDIR}/devel/py-configobj \
		${PYTHON_PKGNAMEPREFIX}pycurl>=7.19.5.1:${PORTSDIR}/ftp/py-pycurl \
		${PYTHON_PKGNAMEPREFIX}dbus>=1.1.1_1:${PORTSDIR}/devel/py-dbus \
		${PYTHON_PKGNAMEPREFIX}exiv2>=0.3.2_3:${PORTSDIR}/graphics/py-exiv2 \
		${PYTHON_PKGNAMEPREFIX}gobject3>=3.14.0:${PORTSDIR}/devel/py-gobject3 \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0.9:${PORTSDIR}/www/py-httplib2 \
		${PYTHON_PKGNAMEPREFIX}pillow>=2.6.0:${PORTSDIR}/graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}lxml>=3.4.1_1:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}six>=1.8.0:${PORTSDIR}/devel/py-six \
		ImageMagick>=6.9.0.4,1:${PORTSDIR}/graphics/ImageMagick \
		bash>=4.3.33:${PORTSDIR}/shells/bash \
		ca_root_nss>=3.17.4:${PORTSDIR}/security/ca_root_nss \
		coreutils>=8.23:${PORTSDIR}/sysutils/coreutils \
		gsettings:${PORTSDIR}/devel/glib20 \
		notify-send:${PORTSDIR}/devel/libnotify \
		pango>=1.36.8:${PORTSDIR}/x11-toolkits/pango \
		webkit-gtk3>=2.4.8:${PORTSDIR}/www/webkit-gtk3 \
		yelp>=3.14.1:${PORTSDIR}/x11/yelp

SHEBANG_FILES=	bin/variety data/scripts/*

USES=	desktop-file-utils gettext python:2 shebangfix
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
