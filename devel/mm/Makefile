PORTNAME=	mm
PORTVERSION=	1.4.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	OSSP/lib/${PORTNAME}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Shared memory allocation library for pre-forked process models
WWW=		http://www.ossp.org/pkg/lib/mm/

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

post-build:
	@${ECHO_MSG} "===>  Use 'make test' to run a quick test suite."

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmm.so

test:
	@cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
