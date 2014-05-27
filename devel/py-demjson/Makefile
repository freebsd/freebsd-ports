# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	demjson
PORTVERSION=	2.0.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		http://deron.meranda.us/python/demjson/dist/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@robakdesign.com
COMMENT=	Encoder, Decoder, and Lint/Validator for JSON

LICENSE=	LGPL3

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/jsonlint ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
