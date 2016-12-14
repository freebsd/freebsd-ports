# Created by: vanilla
# $FreeBSD$

PORTNAME=	protobuf
PORTVERSION=	3.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Data interchange format library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_sparc64=	fails to compile: no atomic ops available

CFLAGS+=	-DGOOGLE_PROTOBUF_NO_RTTI
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_CSTD=	c99	# for audio/clementine-player support
USE_LDCONFIG=	yes
USES=		autoreconf gmake libtool pathfix pkgconfig

GH_ACCOUNT=	google
USE_GITHUB=	yes

.include <bsd.port.mk>
