PORTNAME=	atpublic
PORTVERSION=	3.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Very simple decorator and function of module's all

LICENSE=	APACHE20

USES=		python:3.8+
USE_PYTHON=	autoplist distutils

MAKE_ENV=	ATPUBLIC_BUILD_EXTENSION=1

post-extract:
	${CP} ${FILESDIR}/setup* ${WRKSRC}

.include <bsd.port.mk>
