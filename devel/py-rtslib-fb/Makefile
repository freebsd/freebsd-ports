PORTNAME=	rtslib-fb
PORTVERSION=	2.2.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	rtslib_fb-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	API for Linux kernel SCSI target (aka LIO)
WWW=		https://github.com/open-iscsi/rtslib-fb

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyudev>=0.18<1:devel/py-pyudev@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

SHEBANG_FILES=	rtslib/targetctl.py

.include <bsd.port.mk>
