# Created by: Hye-Shik Chang <perky@fallin.lv>
# $FreeBSD$

PORTNAME=	metar
PORTVERSION=	0.20
CATEGORIES=	astro python geography
MASTER_SITES=	http://www.schwarzvogel.de/pkgs/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python module that provides access to NOAA METAR weather reports

LICENSE=	GPLv2

USE_PYTHON=	autoplist distutils
USES=		python:2 shebangfix

SHEBANG_FILES=	bin/py${PORTNAME}
python_CMD=	${PYTHON_CMD}

.include <bsd.port.mk>
