# Created by: Neil Booth
# $FreeBSD$

PORTNAME=	electrum
PORTVERSION=	1.7.3
CATEGORIES=	finance python
MASTER_SITES=	http://download.electrum.org/download/
DISTNAME=	Electrum-${PORTVERSION}

MAINTAINER=	kyuupichan@gmail.com
COMMENT=	Easy to use Bitcoin client

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}slowaes>0:${PORTSDIR}/security/py-slowaes \
		${PYTHON_PKGNAMEPREFIX}ecdsa>0:${PORTSDIR}/security/py-ecdsa \
		${PYTHON_PKGNAMEPREFIX}qt4>=4.9:${PORTSDIR}/devel/py-qt4

USE_PYTHON=	2
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	Electrum

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
		${WRKSRC}/setup.py ${WRKSRC}/lib/util.py

.include <bsd.port.mk>
