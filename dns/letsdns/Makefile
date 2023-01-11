PORTNAME=	letsdns
DISTVERSION=	1.0.1
CATEGORIES=	dns

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Manage DANE TLSA records in DNS servers
WWW=		https://letsdns.org/

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>0:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	LetsDNS
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>
