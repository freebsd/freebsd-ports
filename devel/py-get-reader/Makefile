PORTNAME=	get-reader
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	get_reader-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Return csv.reader-like objects from multiple sources
WWW=		https://github.com/shawnbrown/get_reader

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	DBF EXCEL
OPTIONS_DEFAULT=DBF EXCEL
DBF_DESC=	DBF support
EXCEL_DESC=	Excel support

DBF_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbfread>=0:textproc/py-dbfread@${PY_FLAVOR}
EXCEL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xlrd>=0:textproc/py-xlrd@${PY_FLAVOR}

.include <bsd.port.mk>
