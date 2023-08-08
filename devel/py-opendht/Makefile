PORTNAME=	opendht
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.10
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
USE_GITHUB=	yes
GH_ACCOUNT=	savoirfairelinux
USE_PYTHON=	distutils cython autoplist pytest

WRKSRC_SUBDIR=	python

post-stage:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/opendht*.so

.include <bsd.port.mk>
