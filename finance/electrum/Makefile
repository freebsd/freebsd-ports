# Created by: Neil Booth
# $FreeBSD$

PORTNAME=	electrum
PORTVERSION=	1.9.8
PORTREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	http://download.electrum.org/
DISTNAME=	Electrum-${PORTVERSION}

MAINTAINER=	kyuupichan@gmail.com
COMMENT=	Easy to use Bitcoin client

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}slowaes>0:${PORTSDIR}/security/py-slowaes \
		${PYTHON_PKGNAMEPREFIX}ecdsa>0:${PORTSDIR}/security/py-ecdsa \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=4.10.3:${PORTSDIR}/x11-toolkits/py-qt4-gui

USE_PYTHON=	-2.7
USE_PYDISTUTILS=yes
USES=		desktop-file-utils gettext
PYDISTUTILS_PKGNAME=	Electrum

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
		${WRKSRC}/setup.py ${WRKSRC}/lib/util.py

.include <bsd.port.mk>
