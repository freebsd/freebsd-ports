# devel/hadoop2 needs version 2.5.0
PORTNAME=	protobuf
PORTVERSION=	2.5.0
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://pkgs.fedoraproject.org/repo/pkgs/protobuf/protobuf-2.5.0.tar.bz2/a72001a9067a4c2c4e0e836d0f92ece4/
PKGNAMESUFFIX=	25

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Data interchange format library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.txt

GNU_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/protobuf25
USE_LDCONFIG=	${PREFIX}/protobuf25/lib
USES=		cpe gmake pathfix pkgconfig tar:bzip2 libtool
ONLY_FOR_ARCHS=	i386 amd64
INSTALL_TARGET=	install-strip

CPE_VENDOR=	google

# clang will generate code that just doesn't work with clementine-player
# if this isn't compiled as though it were C99.
CFLAGS+=	-std=c99 -DGOOGLE_PROTOBUF_NO_RTTI

tests: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
