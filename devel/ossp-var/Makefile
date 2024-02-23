PORTNAME=	var
PORTVERSION=	1.1.3
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	OSSP/lib/${PORTNAME}
PKGNAMEPREFIX=	ossp-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flexible, full-featured, and fast variable expansion library
WWW=		http://www.ossp.org/pkg/lib/var/

USES=		libtool
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_LDCONFIG=	yes

check:	build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libvar.so

.include <bsd.port.mk>
