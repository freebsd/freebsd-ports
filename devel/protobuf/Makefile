# Created by: vanilla
# $FreeBSD$

PORTNAME=	protobuf
PORTVERSION=	2.6.1
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Data interchange format library

LICENSE=	BSD3CLAUSE

CFLAGS+=	-DGOOGLE_PROTOBUF_NO_RTTI
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
ONLY_FOR_ARCHS=	amd64 armv6 i386
PATHFIX_MAKEFILEIN=	Makefile.am
USE_CSTD=	c99	# for audio/clementine-player support
USE_LDCONFIG=	yes
USES=		autoreconf gmake libtool pathfix pkgconfig tar:bzip2

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_PROJECT=	protobuf
GH_TAGNAME=	v${PORTVERSION}

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} check

.include <bsd.port.mk>
