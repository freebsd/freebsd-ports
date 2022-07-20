PORTNAME=	mm
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	OSSP/lib/${PORTNAME}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Shared memory allocation library for pre-forked process models

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

post-build:
	@${ECHO_MSG} "===>  Use 'make test' to run a quick test suite."

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmm.so

test:
	@cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
