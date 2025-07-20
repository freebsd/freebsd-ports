PORTNAME=	vit
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.3
CATEGORIES=	deskutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry.dussuet@protonmail.com
COMMENT=	Curses-based interface to taskwarrior
WWW=		https://github.com/vit-project/vit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	task:deskutils/taskwarrior \
		${PYTHON_PKGNAMEPREFIX}tasklib>=2.3:devel/py-tasklib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzlocal>=1.5:devel/py-tzlocal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwid>=0.6:devel/py-urwid@${PY_FLAVOR}

USES=		python:3.5+,run
USE_GITHUB=	yes
GH_ACCOUNT=	vit-project
GH_PROJECT=	vit
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes
.include <bsd.port.mk>
