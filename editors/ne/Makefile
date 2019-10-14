# Created by: Andrej Zverev <az@inec.ru>
# $FreeBSD$

PORTNAME=	ne
PORTVERSION=	3.2.1
CATEGORIES=	editors
MASTER_SITES=	http://ne.di.unimi.it/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nice and powerful editor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake makeinfo perl5
USE_PERL5=	build
USE_CSTD=	c99

MAKEFILE=	makefile
MAKE_ARGS=	CC="${CC}" \
		OPTS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		NE_GLOBAL_DIR="${DATADIR}"
ALL_TARGET=	ne

LDFLAGS+=	-lgnuregex

BUILD_WRKSRC=	${WRKSRC}/src
INFO=		ne
DOCS=		CHANGES NEWS README.md doc/default.* \
		doc/ne.pdf doc/ne.txt doc/html/*

OPTIONS_DEFINE=		DEBUG DOCS

DEBUG_MAKE_ARGS=	NE_DEBUG=1

post-patch:
	@${FIND} ${BUILD_WRKSRC} -name "*.c" | ${XARGS} ${REINPLACE_CMD} -e \
		's|"regex\.h"|<gnu/regex.h>|g'
	@${REINPLACE_CMD} -e \
		's|-O3|| ; \
		/[[:space:]]regex.o/d ; \
		 s|regex.h$$||g' ${BUILD_WRKSRC}/makefile
	@${REINPLACE_CMD} -e '/cp -pR/d' ${WRKSRC}/makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ne
	${INSTALL_MAN} ${WRKSRC}/doc/ne.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/doc/ne.info.gz \
		${STAGEDIR}${PREFIX}/${INFO_PATH}/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
