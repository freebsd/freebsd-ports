# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	xmltodict
PORTVERSION=	0.8.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xmj@chaot.net
COMMENT=	XML parser that returns python dictionaries

LICENSE=	MIT

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_AUTOPLIST=	yes
PYTHON_PY3K_PLIST_HACK=	yes

# setuptools module doesn't support STAGEDIR
NO_STAGE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|setup_|#setup_|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
