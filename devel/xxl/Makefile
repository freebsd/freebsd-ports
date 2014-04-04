# Created by: Robert Schlotterbeck <robert@rs.tarrant.tx.us>
# $FreeBSD$

PORTNAME=	xxl
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/39195019/ \
		http://www.zork.org/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C/C++ library for exception handling and asset management

LICENSE=	BSD3CLAUSE

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

PLIST_FILES=	include/xxl.h lib/libxxl.a lib/libxxl.la lib/libxxl.so \
		lib/libxxl.so.2
PORTDOCS=	xxl.html xxl.pdf

OPTIONS_DEFINE=	THREADS DOCS
OPTIONS_DEFAULT=THREADS

THREADS_CONFIGURE_WITH=	threads

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libxxl.so.2

regression-test test: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
