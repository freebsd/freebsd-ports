PORTNAME=	pbs-installer
PORTVERSION=	2025.8.8
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pbs_installer-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Installer for Python Build Standalone
WWW=		https://pbs-installer.readthedocs.io/en/latest/ \
		https://github.com/frostming/pbs-installer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>=0:devel/py-pdm-backend@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	DOWNLOAD INSTALL
OPTIONS_DEFAULT=DOWNLOAD INSTALL
DOWNLOAD_DESC=	Download support
INSTALL_DESC=	Install support

DOWNLOAD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httpx>=0.27.0<1:www/py-httpx@${PY_FLAVOR}
INSTALL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zstandard>=0.21.0:archivers/py-zstandard@${PY_FLAVOR}

.include <bsd.port.mk>
