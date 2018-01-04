# Created by: Ju Pengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	gwrite
PORTVERSION=	0.5.1
PORTREVISION=	4
CATEGORIES=	editors python
MASTER_SITES=	http://archive.ubuntu.com/ubuntu/pool/universe/g/gwrite/
DISTNAME=	gwrite_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple HTML format editor

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-distutils-extra>=2.15:devel/py-python-distutils-extra@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jswebkit>=0:www/py-jswebkit@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webkitgtk>=0:www/py-webkitgtk@${FLAVOR}
RUN_DEPENDS=	gnome-icon-theme>=0:misc/gnome-icon-theme \
		wvHtml:textproc/wv \
		${PYTHON_PKGNAMEPREFIX}jswebkit>=0:www/py-jswebkit@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webkitgtk>=0:www/py-webkitgtk@${FLAVOR}

NO_ARCH=	yes
USES=		desktop-file-utils gettext-tools python:2.7
USE_GNOME=	intltool pygtk2
USE_PYTHON=	distutils
WRKSRC=		${WRKDIR}/gwrite-${PORTVERSION}

.include <bsd.port.mk>
