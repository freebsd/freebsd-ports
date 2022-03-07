# Created by: Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>

PORTNAME=	fabric
PORTVERSION=	2.5.0
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High level SSH command execution

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=2.4:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}invoke>=1.1,<2.0:devel/py-invoke@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=1.1:security/py-cryptography@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=3.2.5:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=2.0.0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-relaxed>0:devel/py-pytest-relaxed@${PY_FLAVOR}

USES=		cpe python:3.6+
CPE_VENDOR=	fabfile
USE_PYTHON=	distutils concurrent autoplist

CONFLICTS_INSTALL=	py*-fabric3 # bin/fab

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs \
		-k 'not python_dash_m_acts_like_fab'

.include <bsd.port.mk>
