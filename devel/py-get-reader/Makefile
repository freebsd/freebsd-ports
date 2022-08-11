PORTNAME=	get-reader
PORTVERSION=	1.0.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	get_reader-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Return csv.reader-like objects from multiple sources

LICENSE=	APACHE20

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	DBF EXCEL
OPTIONS_DEFAULT=DBF EXCEL
DBF_DESC=	DBF support
EXCEL_DESC=	Excel support

DBF_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbfread>=0:textproc/py-dbfread@${PY_FLAVOR}
EXCEL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xlrd>=0:textproc/py-xlrd@${PY_FLAVOR}

.include <bsd.port.mk>
