PORTNAME=	ansi
PORTVERSION=	0.3.6
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ANSI cursor movement and graphics
WWW=		https://github.com/tehmaze/ansi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}/

.include <bsd.port.mk>
