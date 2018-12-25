# $FreeBSD$

PORTNAME=	opendht
DISTVERSION=	1.8.0
PORTREVISION=	1
CATEGORIES=	devel net
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight Distributed Hash Table implementation

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS=	libopendht.so:devel/opendht \
		libgnutls.so:security/gnutls

USES=		cmake compiler:c++11-lib localbase python:3.4+
USE_GITHUB=	yes
GH_ACCOUNT=	savoirfairelinux
USE_PYTHON=	distutils cython autoplist

WRKSRC_SUBDIR=	python

post-stage:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/opendht.so

.include <bsd.port.mk>
