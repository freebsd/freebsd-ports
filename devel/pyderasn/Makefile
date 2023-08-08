PORTNAME=	pyderasn
PORTVERSION=	9.3
CATEGORIES=	devel python
MASTER_SITES=	http://www.pyderasn.cypherpunks.ru/download/ \
		http://www.grosbein.net/freebsd/distfiles/ \
		LOCAL/eugen
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tar.zst

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	Strict and fast ASN.1 DER/CER/BER library for Python
WWW=		http://www.pyderasn.cypherpunks.ru/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=2.7:devel/py-dateutil@${PY_FLAVOR}

USES=		tar:zst python
USE_PYTHON=	autoplist concurrent distutils optsuffix

NO_ARCH=	yes

.include <bsd.port.mk>
