# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	pure-stlvec
PORTVERSION=	0.2
CATEGORIES=	devel

MAINTAINER=	lichray@gmail.com
COMMENT=	Pure interface to C++ STL vector

USE_PURE=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|^PROD_FLAGS =.*|PROD_FLAGS = $$(CPPFLAGS) $$(CFLAGS) $$(LDFLAGS)|' \
		${WRKSRC}/Makefile

.include "${PORTSDIR}/lang/pure/bsd.pure.mk"
.include <bsd.port.mk>
