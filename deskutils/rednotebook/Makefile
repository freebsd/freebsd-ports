# Ports collection makefile for:	rednotebook
# Date created:				Mon Auguest 1, 2011
# Whom:					Hon-Yu Lawrence Cheung (cheunghonyu@gmail.com)
#
# $FreeBSD$
#

PORTNAME=		rednotebook
PORTVERSION=		1.2.0
CATEGORIES=		deskutils python
MASTER_SITES=		SF
MASTER_SITE_SUBDIR=	rednotebook
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=		cheunghonyu@gmail.com
COMMENT=		A modern journal written in python

LICENSE=		GPLv2

RUN_DEPENDS=		${PYTHON_SITELIBDIR}/yaml/__init__.py:${PORTSDIR}/devel/py-yaml \
			${PYTHON_SITELIBDIR}/webkit/__init__.py:${PORTSDIR}/www/py-webkitgtk \
			${LOCALBASE}/bin/xdg-open:${PORTSDIR}/devel/xdg-utils \
			${PYTHON_SITELIBDIR}/chardet/__init__.py:${PORTSDIR}/textproc/py-chardet

USE_GETTEXT=		yes

INSTALLS_ICONS=		yes
USE_GNOME=		pygtk2
USE_PYTHON=		2.5-2.7
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
