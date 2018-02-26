# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	avro
PORTVERSION=	1.8.2
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Data serialization system for python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/src/avro/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-snappy>=0:archivers/py-python-snappy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.0.9:devel/py-simplejson@${FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
