# Created by: Andrej Zverev <az@inec.ru>
# $FreeBSD$

PORTNAME=	ne
PORTVERSION=	3.0.1
CATEGORIES=	editors
MASTER_SITES=	http://ne.di.unimi.it/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nice and powerful editor

LICENSE=	GPLv3+
#LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_WRKSRC=	${WRKSRC}/src

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

INFO=		ne
PORTDOCS=	*
PORTDATA=	*
PLIST_FILES=	bin/ne man/man1/ne.1.gz

OPTIONS_DEFINE=		DEBUG DOCS

DEBUG_MAKE_ARGS=	NE_DEBUG=1

post-patch:
	@${FIND} ${BUILD_WRKSRC} -name "*.c" | ${XARGS} ${REINPLACE_CMD} -e \
		's|"regex\.h"|<gnu/regex.h>|g'
	@${REINPLACE_CMD} -e \
		's|-O3|| ; \
		 /[[:space:]]regex.o/d ; \
		 s|regex.h$$||g' ${BUILD_WRKSRC}/makefile

post-build:
	cd ${WRKSRC}/doc && makeinfo ne.texinfo

do-install:
	(cd ${BUILD_WRKSRC} && ${INSTALL_PROGRAM} ne \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} ne.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} ne.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH})
	@${MKDIR} ${STAGEDIR}${DATADIR}/macros
	(cd ${WRKSRC}/macros && ${INSTALL_DATA} * \
		${STAGEDIR}${DATADIR}/macros)
	@${MKDIR} ${STAGEDIR}${DATADIR}/syntax
	(cd ${WRKSRC}/syntax && ${INSTALL_DATA} *.jsf \
		${STAGEDIR}${DATADIR}/syntax)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} CHANGES NEWS README.md \
		${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} default.* ne.pdf ne.txt \
		${STAGEDIR}${DOCSDIR})
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
