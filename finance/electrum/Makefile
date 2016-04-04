# Created by: Neil Booth
# $FreeBSD$

PORTNAME=	electrum
PORTVERSION=	2.5.4
CATEGORIES=	finance python
MASTER_SITES=	https://download.electrum.org/${PORTVERSION}/ \
		http://download.electrum.org/${PORTVERSION}/
DISTNAME=	Electrum-${PORTVERSION}

MAINTAINER=	kyuupichan@gmail.com
COMMENT=	Easy to use Bitcoin client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENCE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}slowaes>0:security/py-slowaes \
		${PYTHON_PKGNAMEPREFIX}ecdsa>0:security/py-ecdsa \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=4.10.3:x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}requests>=2.4.3:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}qrcode>=5.1:textproc/py-qrcode \
		${PYTHON_PKGNAMEPREFIX}tlslite>=0.4.6:security/py-tlslite \
		${PYTHON_PKGNAMEPREFIX}pbkdf2>=1.3:security/py-pbkdf2 \
		${PYTHON_PKGNAMEPREFIX}protobuf>=2.6.0:devel/py-protobuf \
		${PYTHON_PKGNAMEPREFIX}dnspython>0:dns/py-dnspython

USES=		desktop-file-utils python:-2.7
USE_PYTHON=	autoplist distutils
PYDISTUTILS_PKGNAME=	Electrum

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
