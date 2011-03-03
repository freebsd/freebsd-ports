# New ports collection makefile for:	gwrite
# Date created:				07 Mar 2010
# Whom:					Ju Pengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=		gwrite
PORTVERSION=		0.3.0
CATEGORIES=		editors python
MASTER_SITES=		GOOGLE_CODE

MAINTAINER=		jupengfei@gmail.com
COMMENT=		A simple HTML format editor

BUILD_DEPENDS=		pygtk-demo:${PORTSDIR}/x11-toolkits/py-gtk2 \
			${PYTHON_PKGNAMEPREFIX}distutils-extra>=2.15:${PORTSDIR}/devel/py-distutils-extra \
			${PYTHON_SITELIBDIR}/webkit/__init__.py:${PORTSDIR}/www/py-webkitgtk \
			${PYTHON_SITELIBDIR}/jswebkit.so:${PORTSDIR}/www/py-jswebkit \
			${LOCALBASE}/bin/intltool-update:${PORTSDIR}/textproc/intltool
RUN_DEPENDS=		${BUILD_DEPENDS} \
			${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
			${LOCALBASE}/share/icons/Tango/index.theme:${PORTSDIR}/x11-themes/icons-tango \
			wvHtml:${PORTSDIR}/textproc/wv

PLIST_SUB=		PYTHON_VER=${PYTHON_VER}
PROJECTHOST=		gwrite

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_NOEGGINFO=	yes

.include <bsd.port.mk>
