# Created by: Kimura Fuyuki <fuyuki@nigredo.org>
# $FreeBSD$

PORTNAME=	xds
PORTVERSION=	0.9.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	OSSP/lib/${PORTNAME}
PKGNAMEPREFIX=	ossp-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic and extensible framework for serialization

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
TEST_TARGET=	check  # XXX: 20 of 26 tests fail

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libxds.so

.include <bsd.port.mk>
