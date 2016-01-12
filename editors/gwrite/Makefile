# Created by: Ju Pengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	gwrite
PORTVERSION=	0.5.1
PORTREVISION=	4
CATEGORIES=	editors python
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple HTML format editor

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-distutils-extra>=2.15:${PORTSDIR}/devel/py-python-distutils-extra \
		${PYTHON_PKGNAMEPREFIX}jswebkit>=0:${PORTSDIR}/www/py-jswebkit \
		${PYTHON_PKGNAMEPREFIX}webkitgtk>=0:${PORTSDIR}/www/py-webkitgtk
RUN_DEPENDS=	gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme \
		wvHtml:${PORTSDIR}/textproc/wv \
		${PYTHON_PKGNAMEPREFIX}jswebkit>=0:${PORTSDIR}/www/py-jswebkit \
		${PYTHON_PKGNAMEPREFIX}webkitgtk>=0:${PORTSDIR}/www/py-webkitgtk

USES=		desktop-file-utils gettext-tools python
USE_GNOME=	intltool pygtk2
USE_PYTHON=	distutils

.include <bsd.port.mk>
