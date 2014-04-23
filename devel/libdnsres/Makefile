# Created by: Phil Oleson <oz@nixil.net>
# $FreeBSD$

PORTNAME=	libdnsres
PORTVERSION=	0.1a
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	http://monkey.org/~provos/

MAINTAINER=	oz@nixil.net
COMMENT=	Provides a non-blocking thread-safe API for resolving DNS names

BUILD_DEPENDS=	${LOCALBASE}/lib/libevent.a:${PORTSDIR}/devel/libevent

USES=		libtool:keepla
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=--with-libevent=${LOCALBASE}
MAKE_JOBS_UNSAFE=	yes

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

post-patch:
	@${REINPLACE_CMD} -e 's,CFLAGS =,CFLAGS +=, ; s|top_buildir|top_builddir|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
