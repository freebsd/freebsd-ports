PORTNAME=	minigalaxy
DISTVERSION=	1.4.0
CATEGORIES=	games
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Simple GOG client for Linux
WWW=		https://sharkwouter.github.io/minigalaxy

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		webkit2-gtk_40>0:www/webkit2-gtk@40

USES=		gettext gnome python
USE_GITHUB=	yes
GH_ACCOUNT=	sharkwouter
USE_GNOME=	pygobject3:run
USE_PYTHON=	distutils

NO_ARCH=	yes

.include <bsd.port.mk>
