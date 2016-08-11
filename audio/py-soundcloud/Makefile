# Created by: Bernard Spil <brnrd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	soundcloud
PORTVERSION=	0.5.0
CATEGORIES=	audio devel www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	A friendly wrapper library for the Soundcloud API

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=1.1.2:devel/py-nose

USES=		python
USE_PYTHON=	autoplist distutils

PORTDOCS=	README.rst
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.rst ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${WRKSRC} ; nosetests --with-doctest

.include <bsd.port.mk>
