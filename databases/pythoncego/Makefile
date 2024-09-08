PORTNAME=	pythoncego
PORTVERSION=	1.0.1

CATEGORIES=	databases
MASTER_SITES=	http://www.lemke-it.com/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Cego database support for Python
WWW=		https://www.lemke-it.com/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcego.so:databases/cego

USES=		python
USE_PYTHON=	autoplist concurrent distutils pytest

.include <bsd.port.mk>
