# $FreeBSD$

PORTNAME=	libmill
PORTVERSION=	1.17
CATEGORIES=	devel
MASTER_SITES=	http://libmill.org/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Go-style concurrency in CGo-style concurrency in C

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pathfix libtool
INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
TEST_TARGET=	check

.include <bsd.port.mk>
