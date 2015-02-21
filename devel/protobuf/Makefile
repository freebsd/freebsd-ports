# Created by: vanilla
# $FreeBSD$

PORTNAME=	protobuf
PORTVERSION=	2.6.0
CATEGORIES=	devel
MASTER_SITES=	https://protobuf.googlecode.com/svn/rc/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Data interchange format library

LICENSE=	BSD3CLAUSE

CFLAGS+=	-DGOOGLE_PROTOBUF_NO_RTTI
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
ONLY_FOR_ARCHS=	amd64 armv6 i386
USE_LDCONFIG=	yes
USES=		gmake libtool pathfix pkgconfig tar:bzip2

# Clang will generate code that just doesn't work with clementine-player
# if this isn't compiled as though it were C99.
USE_CSTD=	c99

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} check

.include <bsd.port.mk>
