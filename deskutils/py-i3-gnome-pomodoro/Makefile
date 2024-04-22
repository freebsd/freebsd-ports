PORTNAME=	i3-gnome-pomodoro
DISTVERSION=	0.1.0
CATEGORIES=	deskutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYDISTNAME}-${DISTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Integrate gnome-pomodoro into i3bar, polybar or waybar
WWW=		https://github.com/kantord/i3-gnome-pomodoro

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.7.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}blinkstick>=g20230504:sysutils/py-blinkstick@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.1.7:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}i3ipc>=2.2.1:x11/py-i3ipc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydbus>=0.6.0:devel/py-pydbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyusb>=1.2.1:devel/py-pyusb@${PY_FLAVOR} \
		gnome-pomodoro:deskutils/gnome-pomodoro \
		pygobject3-common>=3.42.0:devel/pygobject3-common

USES=		python shebangfix

USE_PYTHON=	autoplist pep517

SHEBANG_FILES=	${WRKSRC}/${PYDISTNAME}/pomodoro_client.py

PYDISTNAME=	${PORTNAME:S/-/_/g}

.include <bsd.port.mk>
