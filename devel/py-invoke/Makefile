PORTNAME=	invoke
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python task execution tool and library
WWW=		https://www.pyinvoke.org/ \
		https://github.com/pyinvoke/invoke

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	SUDO
SUDO_DESC=	Run shell commands via sudo

SUDO_RUN_DEPENDS=	sudo:security/sudo

.include <bsd.port.mk>
