# Created by: Hye-Shik Chang <perky@fallin.lv>

PORTNAME=	pymetar
PORTVERSION=	1.2
CATEGORIES=	astro geography python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python module that provides access to NOAA METAR weather reports

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python:3.5+ shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

SHEBANG_FILES=	bin/pymetar

.include <bsd.port.mk>
