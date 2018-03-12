# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	oletools
PORTVERSION=	0.52.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Tools to analyze security characteristics of MS OLE2 files

LICENSE=	BSD2CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/oletools/LICENSE.txt

NO_ARCH=	yes
USES=		dos2unix python zip
USE_LOCALE=	en_US.UTF-8
USE_PYTHON=	distutils concurrent autoplist
DOS2UNIX_FILES=	oletools/oleform.py

.include <bsd.port.mk>
