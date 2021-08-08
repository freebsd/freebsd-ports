# Created by: Peter Haight <peterh@sapros.com>

PORTNAME=	scons
PORTVERSION=	4.2.0
CATEGORIES=	devel python
MASTER_SITES=	SF
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Build tool alternative to make

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes
WRKSRC=		${WRKDIR}/SCons-${PORTVERSION}

.include <bsd.port.mk>
