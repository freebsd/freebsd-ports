# Created by: Hye-Shik Chang <perky@fallin.lv>
# $FreeBSD$

PORTNAME=	pymetar
PORTVERSION=	0.20
CATEGORIES=	astro python geography
MASTER_SITES=	http://www.schwarzvogel.de/pkgs/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python module that provides access to NOAA METAR weather reports

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils
USES=		python:2 shebangfix

SHEBANG_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
