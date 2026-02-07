PORTNAME=	str
PORTVERSION=	0.9.12
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	OSSP/lib/${PORTNAME}

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Generic String Library
WWW=		http://www.ossp.org/pkg/lib/str/

USES=		desthack libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-build:
	@${ECHO_MSG} "===>  Use 'make check' to run a quick test suite."

check:	build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test)

.include <bsd.port.mk>
