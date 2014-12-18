# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	demjson
PORTVERSION=	2.2.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		http://deron.meranda.us/python/demjson/dist/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Encoder, Decoder and Lint/Validator for JSON

LICENSE=	LGPL3

USES=		python
USE_PYTHON=	distutils autoplist

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/jsonlint ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
