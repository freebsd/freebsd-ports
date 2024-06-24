PORTNAME=	sopel-help
DISTVERSION=	0.5.1
CATEGORIES=	irc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	sopel_help-${PORTVERSION}

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Help plugin for Sopel
WWW=		https://github.com/sopel-irc/${PORTNAME}

LICENSE=	EFLv2
LICENSE_GROUPS=	FSF GPL OSI
LICENSE_NAME=	Eiffel Forum License, version 2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sopel>=0:irc/py-sopel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
