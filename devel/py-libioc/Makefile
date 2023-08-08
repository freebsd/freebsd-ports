PORTNAME=	libioc
PORTVERSION=	0.8.2
PORTREVISION=	2
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	ceea85bbabaafa0be700.diff:-p1

MAINTAINER=	stefan@gronke.net
COMMENT=	Library to manage jails with iocage and iocell
WWW=		https://github.com/bsdci/libioc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gitpython>0:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libzfs>0:devel/py-libzfs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sysctl>0:devel/py-sysctl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ucl>0:textproc/py-ucl@${PY_FLAVOR} \
		ca_root_nss>0:security/ca_root_nss \
		rsync:net/rsync

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	bsdci

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils py3kplist

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
