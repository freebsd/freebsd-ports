# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	jinja2-ansible-filters
PORTVERSION=	1.3.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Port of Ansible's jinja2 filters without requiring ansible core

LICENSE=	BSD2CLAUSE GPLv3
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${ECHO_CMD} ${PORTVERSION} > ${WRKSRC}/VERSION

.include <bsd.port.mk>
