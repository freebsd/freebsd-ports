# Created by: Robert Schlotterbeck <robert@rs.tarrant.tx.us>
# $FreeBSD$

PORTNAME=	xxl
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/39195019/ \
		http://www.zork.org/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C/C++ library for exception handling and asset management

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
TEST_TARGET=	check

PLIST_FILES=	include/xxl.h lib/libxxl.a lib/libxxl.so \
		lib/libxxl.so.1 lib/libxxl.so.1.1.0
PORTDOCS=	xxl.html xxl.pdf

OPTIONS_DEFINE=	THREADS DOCS
OPTIONS_DEFAULT=THREADS

THREADS_CONFIGURE_WITH=	threads

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libxxl.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
