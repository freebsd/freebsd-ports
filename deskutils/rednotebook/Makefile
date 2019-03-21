# Created by: Hon-Yu Lawrence Cheung (cheunghonyu@gmail.com)
# $FreeBSD$

PORTNAME=	rednotebook
PORTVERSION=	1.9.0
PORTREVISION=	1
CATEGORIES=	deskutils python
MASTER_SITES=	SF/rednotebook
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cheunghonyu@gmail.com
COMMENT=	Modern journal written in Python

LICENSE=	GPLv2

DEPRECATED=	Uses webkit-gtk2 which has security issues
EXPIRATION_DATE=	2019-03-24

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webkitgtk>0:www/py-webkitgtk@${PY_FLAVOR} \
		${LOCALBASE}/bin/xdg-open:devel/xdg-utils \
		${PYTHON_PKGNAMEPREFIX}chardet>0:textproc/py-chardet@${PY_FLAVOR}

USES=		desktop-file-utils gettext python:2.7

INSTALLS_ICONS=	yes
USE_GNOME=	pygtk2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
