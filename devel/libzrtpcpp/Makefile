# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>

PORTNAME=	libzrtpcpp
PORTVERSION=	2.3.4
PORTREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	GNU/ccrtp

MAINTAINER=	acm@FreeBSD.org
COMMENT=	ZRTP extension for GNU ccRTP

BROKEN=		incompatible with current SSL, bad C++ code

LIB_DEPENDS=	libccrtp.so:devel/ccrtp \
		libgcrypt.so:security/libgcrypt

USES=		cmake:noninja pkgconfig ssl

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON \
		-DOPENSSL_INCLUDE_DIRS="${OPENSSLINC}" \
		-DOPENSSL_LIBDIR="${OPENSSLLIB}"
CXXFLAGS+=	-I${LOCALBASE}/include -I${OPENSSLINC}
LDFLAGS+=	-L${LOCALBASE}/lib -L${OPENSSLLIB}
USE_LDCONFIG=	yes

post-patch:
	@${FIND} ${WRKSRC}/src -type f | ${XARGS} ${REINPLACE_CMD} -i "" \
		-e "s|<malloc.h>|<stdlib.h>|"	\
		-e "s|<stdint.h>|<inttypes.h>|"

.include <bsd.port.mk>
