# $FreeBSD$

PORTNAME=	libiocage
PORTVERSION=	0.3.1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	maintainers@iocage.io
COMMENT=	Library to manage jails with iocage

BROKEN=		unfetchable

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}GitPython>0:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ucl>0:textproc/py-ucl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libzfs>0:devel/py-libzfs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sysctl>0:devel/py-sysctl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}texttable>0:textproc/py-texttable@${PY_FLAVOR} \
		ca_root_nss>0:security/ca_root_nss \
		rsync:net/rsync

USE_GITHUB=	yes
GH_ACCOUNT=	iocage
GH_PROJECT=	libiocage

NO_ARCH=	yes
USES=		python:3.6+
USE_PYTHON=	distutils py3kplist

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/ioc ${STAGEDIR}${PREFIX}/etc/rc.d/ioc

.include <bsd.port.mk>
