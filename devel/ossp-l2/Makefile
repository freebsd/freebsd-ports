PORTNAME=	l2
PORTVERSION=	0.9.13
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	OSSP/lib/${PORTNAME}
PKGNAMEPREFIX=	ossp-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library for a flexible and sophisticated Unix logging facility

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

check:	build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/l2tool ${STAGEDIR}${PREFIX}/lib/libl2.so

.include <bsd.port.mk>
