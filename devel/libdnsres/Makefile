PORTNAME=	libdnsres
PORTVERSION=	0.1a
PORTREVISION=	10
CATEGORIES=	devel
MASTER_SITES=	http://monkey.org/~provos/

MAINTAINER=	oz@nixil.net
COMMENT=	Provides a non-blocking thread-safe API for resolving DNS names

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libevent.a:devel/libevent

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-libevent=${LOCALBASE}
MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,CFLAGS =,CFLAGS +=, ; s|top_buildir|top_builddir|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
