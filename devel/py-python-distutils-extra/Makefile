# Created by: Ju Pengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	python-distutils-extra
PORTVERSION=	2.44
CATEGORIES=	devel python
MASTER_SITES=	DEBIAN
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Add support for i18n, documentation, and icons to distutils

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python tar:xz
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
