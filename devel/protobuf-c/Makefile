# New Ports collection makefile for:	protobuf
# Date created:				2011.05.16
# Whom:					Aaron Hurt <ahurt@anbcs.com>
#
# $FreeBSD$
#

PORTNAME=	protobuf-c
PORTVERSION=	0.15
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	ahurt@anbcs.com
COMMENT=	This package provides a code generator and runtime libraries to use Protocol Buffers from pure C (not C++)

LIB_DEPENDS=	protobuf.7:${PORTSDIR}/devel/protobuf

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack pkgconfig

CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	LDFLAGS=-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|GREP "\\-L"|GREP "bin/ld"|g' ${WRKSRC}/configure

tests: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
