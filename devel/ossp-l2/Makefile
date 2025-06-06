PORTNAME=	l2
PORTVERSION=	0.9.13
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	OSSP/lib/${PORTNAME}
PKGNAMEPREFIX=	ossp-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library for a flexible and sophisticated Unix logging facility
WWW=		http://www.ossp.org/pkg/lib/l2/

DEPRECATED=	Abandoned upstream, last release in 2007
EXPIRATION_DATE=2025-07-31

USES=		libtool
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_LDCONFIG=	yes

check:	build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/l2tool ${STAGEDIR}${PREFIX}/lib/libl2.so

.include <bsd.port.mk>
