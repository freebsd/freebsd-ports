PORTNAME=	xds
PORTVERSION=	0.9.3
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	OSSP/lib/${PORTNAME}
PKGNAMEPREFIX=	ossp-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic and extensible framework for serialization
WWW=		http://www.ossp.org/pkg/lib/xds/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		libtool
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_LDCONFIG=	yes
TEST_TARGET=	check  # XXX: 20 of 26 tests fail

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libxds.so

.include <bsd.port.mk>
