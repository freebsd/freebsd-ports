# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	idna
PORTVERSION=	2.10
CATEGORIES=	dns python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Internationalized Domain Names in Applications (IDNA)

LICENSE=	BSD3CLAUSE PSFL
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

USES=		python	# Actually, 2.7,3.4-3.8
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m unittest discover -v

.include <bsd.port.mk>
