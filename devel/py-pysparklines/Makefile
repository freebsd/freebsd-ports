PORTNAME=	pysparklines
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Unicode sparkline generation library in Python
WWW=		https://github.com/RedKrieg/pysparklines

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

PLIST_FILES=	share/man/man1/sparkline.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/sparkline.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
