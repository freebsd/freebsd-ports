PORTNAME=       git-lab
DISTVERSION=    0.1
CATEGORIES=     devel

MAINTAINER=     adridg@FreeBSD.org
COMMENT=        GitLab management commands for git CLI

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gitpython>=2.1.8:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-gitlab>=2.7.1:devel/py-python-gitlab@${PY_FLAVOR}

USES=           python
USE_PYTHON=	autoplist concurrent distutils

USE_GITLAB=	yes
GL_SITE=	https://invent.kde.org
GL_ACCOUNT=	sdk
GL_PROJECT=	${PORTNAME}
GL_COMMIT=	68c892f1f5268652d23cea04b1af294b8fc32dbb

.include <bsd.port.mk>
