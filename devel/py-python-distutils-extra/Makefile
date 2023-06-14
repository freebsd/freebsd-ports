PORTNAME=	python-distutils-extra
PORTVERSION=	2.50
CATEGORIES=	devel python
MASTER_SITES=	DEBIAN
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Add support for i18n, documentation, and icons to distutils
WWW=		https://salsa.debian.org/python-team/packages/python-distutils-extra

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python tar:xz
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
