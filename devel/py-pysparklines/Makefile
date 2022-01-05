PORTNAME=	pysparklines
PORTVERSION=	1.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Unicode sparkline generation library in Python

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

PLIST_FILES=	man/man1/sparkline.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/sparkline.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
