PORTNAME=	al
PORTVERSION=	0.9.3
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	OSSP/lib/${PORTNAME}
PKGNAMEPREFIX=	ossp-

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Defines an abstract type of buffer that can move data without copying
WWW=		http://www.ossp.org/pkg/lib/al/

DEPRECATED=	Obsolete and abandoned upstream, last release in 2005
EXPIRATION_DATE=2025-07-31

LIB_DEPENDS=	libex.so:devel/ossp-ex

USES=		libtool
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--with-ex=${LOCALBASE}
USE_LDCONFIG=	yes

check:	build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libal.so

.include <bsd.port.mk>
