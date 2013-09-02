# Created by: Aaron Hurt <ahurt@anbcs.com>
# $FreeBSD$

PORTNAME=	protobuf-c
PORTVERSION=	0.15
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	ahurt@anbcs.com
COMMENT=	This package provides a code generator and runtime libraries to use Protocol Buffers from pure C (not C++)

LIB_DEPENDS=	protobuf:${PORTSDIR}/devel/protobuf

USES=		gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|GREP "\\-L"|GREP "bin/ld"|g' ${WRKSRC}/configure

tests: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc" && ${OSVERSION} > 900000
BROKEN=		Does not build on powerpc-9
.endif

.include <bsd.port.post.mk>
