PORTNAME=	pyderasn
PORTVERSION=	9.5
CATEGORIES=	devel python
MASTER_SITES=	http://www.pyderasn.stargrave.org/download/ \
		http://www.grosbein.net/freebsd/distfiles/ \
		LOCAL/eugen
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tar.zst

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	Strict and fast ASN.1 DER/CER/BER library for Python
WWW=		http://www.pyderasn.stargrave.org/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.7:devel/py-python-dateutil@${PY_FLAVOR}

USES=		tar:zst python
USE_PYTHON=	autoplist concurrent distutils optsuffix

NO_ARCH=	yes

.include <bsd.port.mk>
