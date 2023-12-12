PORTNAME=	opendht
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.6
CATEGORIES=	devel net
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight Distributed Hash Table implementation
WWW=		https://github.com/savoirfairelinux/opendht/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/predef/other/endian.h:devel/boost-libs
LIB_DEPENDS=	libopendht.so:devel/opendht \
		libgnutls.so:security/gnutls

USES=		cmake compiler:c++17-lang localbase python
USE_PYTHON=	distutils cython autoplist pytest # 4 tests fail, see https://github.com/savoirfairelinux/opendht/issues/683

USE_GITHUB=	yes
GH_ACCOUNT=	savoirfairelinux

WRKSRC_SUBDIR=	python

post-stage:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/opendht*.so

.include <bsd.port.mk>
