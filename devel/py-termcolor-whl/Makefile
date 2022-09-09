PORTNAME=	termcolor-whl
PORTVERSION=	1.1.2
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ANSI Color formatting for output in terminal, successor to termcolor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	matthewdeanmartin
GH_PROJECT=	termcolor
GH_TAGNAME=	4ecd396

post-patch:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}/

.include <bsd.port.mk>
