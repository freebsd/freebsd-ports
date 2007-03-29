# New ports collection makefile for:	stfl
# Date created:		28 March 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	stfl
PORTVERSION=	0.7
CATEGORIES=	devel
MASTER_SITES=	http://www.clifford.at/stfl/ CENKES

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Structured Terminal Forms Language/Library

USE_LDCONFIG=	yes
USE_GMAKE=	yes
ALL_TARGET=	libstfl.so
CFLAGS+=	-fPIC
PLIST_FILES=	lib/libstfl.so.0 lib/libstfl.so include/stfl.h

post-patch:
	@${REINPLACE_CMD} -e 's|\.a|.so|g;/ranlib/d;s|ar qc|${CC} -shared -fPIC -o|'\
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|alloca.h|stdlib.h|' ${WRKSRC}/widgets/*.c
	@${ECHO_CMD} 'prefix = ${PREFIX}' > ${WRKSRC}/Makefile.cfg

pre-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} Makefile.deps)

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/libstfl.so ${PREFIX}/lib/libstfl.so.0
	@${LN} -sf ${PREFIX}/lib/libstfl.so.0 ${PREFIX}/lib/libstfl.so
	@${INSTALL_DATA} ${WRKSRC}/stfl.h ${PREFIX}/include/

.include <bsd.port.mk>
