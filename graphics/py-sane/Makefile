PORTNAME=	sane
DISTVERSIONPREFIX=	v
DISTVERSION=	2.9.2
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Python interface to the SANE scanner and frame grabber interface
WWW=		https://github.com/python-pillow/Sane

LICENSE=	MIT-CMU
LICENSE_NAME=	CMU License
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libsane.so:graphics/sane-backends

USES=		localbase python
USE_GITHUB=	yes
GH_ACCOUNT=	python-pillow
GH_PROJECT=	Sane
USE_PYTHON=	pep517

PLIST_SUB=	DISTVERSION=${DISTVERSION}

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
