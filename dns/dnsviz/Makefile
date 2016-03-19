# $FreeBSD$

PORTNAME=	dnsviz
PORTVERSION=	0.5.1
DISTVERSIONPREFIX=v
CATEGORIES=	dns

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Analysis and visualization of DNS/DNSSEC behavior

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygraphviz>=1.0:${PORTSDIR}/graphics/py-pygraphviz \
		${PYTHON_PKGNAMEPREFIX}m2crypto>0:${PORTSDIR}/security/py-m2crypto \
		${PYTHON_PKGNAMEPREFIX}dnspython>0:${PORTSDIR}/dns/py-dnspython

USES=		python
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes
PYDISTUTILS_INSTALLNOSINGLE=	yes

BROKEN_FreeBSD_9=	dependency py-m2crypto requires OpenSSL 1.0.1e+.

.include <bsd.port.mk>
