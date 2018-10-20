# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyral
PORTVERSION=	1.4.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python toolkit for Agile Central (Rally) REST API

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.12.5:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

PORTEXAMPLES=	*.py

SHEBANG_GLOB=	*.py

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.py ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
