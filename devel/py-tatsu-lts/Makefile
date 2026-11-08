PORTNAME=	tatsu-lts
DISTVERSION=	5.16.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	LTS fork of TatSu PEG/Packrat parser generator
WWW=		https://github.com/dnicolodi/TatSu-LTS

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517
SHEBANG_GLOB=	*.py

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}TatSu \
			${PYTHON_PKGNAMEPREFIX}tatsu

NO_ARCH=	yes

.include <bsd.port.mk>
