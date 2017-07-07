# Created by: Neil Booth
# $FreeBSD$

PORTNAME=	electrum
PORTVERSION=	2.8.3
CATEGORIES=	finance python
MASTER_SITES=	https://download.electrum.org/${PORTVERSION}/ \
		http://download.electrum.org/${PORTVERSION}/
DISTNAME=	Electrum-${PORTVERSION}

MAINTAINER=	amutu@amutu.com
COMMENT=	Easy to use Bitcoin client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>0:dns/py-dnspython \
		${PYTHON_PKGNAMEPREFIX}ecdsa>0:security/py-ecdsa \
		${PYTHON_PKGNAMEPREFIX}jsonrpclib>0:devel/py-jsonrpclib \
		${PYTHON_PKGNAMEPREFIX}pbkdf2>=1.3:security/py-pbkdf2 \
		${PYTHON_PKGNAMEPREFIX}protobuf>=2.6.0:devel/py-protobuf \
		${PYTHON_PKGNAMEPREFIX}pyaes>0:security/py-pyaes \
		${PYTHON_PKGNAMEPREFIX}pysocks>=0:net/py-pysocks \
		${PYTHON_PKGNAMEPREFIX}requests>=2.4.3:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}qrcode>=5.1:textproc/py-qrcode

USES=		desktop-file-utils pyqt:4 python:-2.7
USE_PYQT=	gui_run
USE_PYTHON=	autoplist distutils
PYDISTUTILS_PKGNAME=	Electrum
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
