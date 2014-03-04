# Created by: Rafal Lesniak <fbsd@grid.einherjar.de>
# $FreeBSD$

PORTNAME=	idnkit-python
PORTVERSION=	2.3
CATEGORIES=	dns
MASTER_SITES=	http://jprs.co.jp/idn/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fbsd@grid.einherjar.de
COMMENT=	Python bindings for Internationalized Domain Name toolkit 2

LIB_DEPENDS=	libidnkitlite.so:${PORTSDIR}/dns/idnkit2

USE_BZIP2=		yes
USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
