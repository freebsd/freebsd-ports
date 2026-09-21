PORTNAME=	mysql-config-coder
DISTVERSION=	g20260914
CATEGORIES=	databases
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	Encoder and decoder for .mylogin.cnf files
WWW=		https://github.com/isotopp/mysql-config-coder

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycryptodome>=0:security/py-pycryptodome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=0:devel/py-click@${PY_FLAVOR}

PLIST_FILES=	bin/${SNAME}
USES=		python

USE_PYTHON=	flavors
USE_GITHUB=	yes

GH_ACCOUNT=	isotopp
GH_TAGNAME=	f16fdde

NO_ARCH=	yes
NO_BUILD=	yes

SNAME=		mysql_config_coder.py

do-install:
		@cd ${WRKSRC} && \
		${REINPLACE_CMD} $$'1s,^.*,#!${PYTHON_CMD},' ${SNAME} && \
		${INSTALL_SCRIPT} ${SNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
