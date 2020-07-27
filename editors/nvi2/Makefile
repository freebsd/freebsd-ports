# Created by: Craig Leres <leres@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nvi2
PORTVERSION=	2.1.3.g2020726
CATEGORIES=	editors

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Updated implementation of the ex/vi text editor

LICENSE=	BSD3CLAUSE

USES=		bdb cmake:noninja ncurses
USE_GITHUB=	yes

GH_ACCOUNT=	lichray
GH_TAGNAME=	0ef1c82

CONFLICTS_INSTALL=	nvi-m17n-[0-9]* nvi-[0-9]*

OPTIONS_DEFINE=		DEBUG WIDECHAR ICONV
OPTIONS_DEFAULT=	WIDECHAR ICONV

WIDECHAR_DESC=		Enable wide-character support (UTF-8)
ICONV_DESC=		Enable iconv support

DEBUG_CMAKE_BOOL=	ENABLE_DEBUG
ICONV_CMAKE_BOOL=	ENABLE_ICONV
ICONV_USES=		iconv
WIDECHAR_CMAKE_BOOL=	ENABLE_WIDECHAR

CMAKE_SOURCE_PATH=	${WRKSRC}/build

PLIST_FILES=	bin/nex \
		bin/nvi \
		bin/nview \
		man/man1/nvi.1.gz

post-patch:
	${REINPLACE_CMD} -E \
	    -e 's,\.\./(cl|common|ex|regex|vi)/,${WRKSRC}/\1/,g' \
	    -e 's,\.\./(regex|README),${WRKSRC}/\1,g' \
	    ${WRKSRC}/build/CMakeLists.txt

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/nvi ${STAGEDIR}${PREFIX}/bin
	${LN} ${STAGEDIR}${PREFIX}/bin/nvi ${STAGEDIR}${PREFIX}/bin/nex
	${LN} ${STAGEDIR}${PREFIX}/bin/nvi ${STAGEDIR}${PREFIX}/bin/nview
	${INSTALL_MAN} ${WRKSRC}/man/vi.1 \
	    ${STAGEDIR}${MAN1PREFIX}/man/man1/nvi.1

.include <bsd.port.mk>
