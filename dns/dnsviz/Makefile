# $FreeBSD$

PORTNAME=	dnsviz
PORTVERSION=	0.8.2
DISTVERSIONPREFIX=v
CATEGORIES=	dns

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Analysis and visualization of DNS/DNSSEC behavior

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygraphviz>=1.1:graphics/py-pygraphviz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}m2crypto>=0.24.0:security/py-m2crypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>=1.11.0:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libnacl>=1.5.2:security/py-libnacl@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils concurrent optsuffix
USE_GITHUB=	yes
PYDISTUTILS_INSTALLNOSINGLE=	yes
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|share/man/man1|man/man1|" ${WRKSRC}/setup.py

.include <bsd.port.mk>
