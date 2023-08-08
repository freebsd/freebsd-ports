PORTNAME=	pymetar
PORTVERSION=	1.4
CATEGORIES=	astro geography python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python module that provides access to NOAA METAR weather reports
WWW=		https://github.com/klausman/pymetar

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

SHEBANG_FILES=	bin/pymetar

.include <bsd.port.mk>
