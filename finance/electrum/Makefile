# Created by: Neil Booth
# $FreeBSD$

PORTNAME=	electrum
PORTVERSION=	3.0.2
CATEGORIES=	finance python
MASTER_SITES=	https://download.electrum.org/${PORTVERSION}/ \
		http://download.electrum.org/${PORTVERSION}/
DISTNAME=	Electrum-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Easy to use Bitcoin client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>0:dns/py-dnspython@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ecdsa>0:security/py-ecdsa@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0:www/py-httplib2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonrpclib-pelix>0:devel/py-jsonrpclib-pelix@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbkdf2>=1.3:security/py-pbkdf2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=2.6.0:devel/py-protobuf@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyaes>0:security/py-pyaes@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysocks>=0:net/py-pysocks@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qrcode>=5.1:textproc/py-qrcode@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.4.3:www/py-requests@${FLAVOR}

CONFLICTS_INSTALL=	electrum2-*

USES=		desktop-file-utils pyqt:5 python:3.4+
USE_PYQT=	gui_run sip widgets
USE_PYTHON=	autoplist distutils optsuffix
PYDISTUTILS_PKGNAME=	Electrum
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
