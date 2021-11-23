# Created by: Craig Leres <leres@FreeBSD.org>

PORTNAME=	nvi2
PORTVERSION=	2.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	editors

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Updated implementation of the ex/vi text editor

LICENSE=	BSD3CLAUSE

USES=		bdb cmake compiler:c11 ncurses
USE_GITHUB=	yes

GH_ACCOUNT=	lichray

CONFLICTS_INSTALL=	nvi-m17n nvi

OPTIONS_DEFINE=		DEBUG WIDECHAR ICONV
OPTIONS_DEFAULT=	WIDECHAR ICONV

WIDECHAR_DESC=		Enable wide-character support (UTF-8)
ICONV_DESC=		Enable iconv support

DEBUG_CMAKE_BOOL=	ENABLE_DEBUG
ICONV_CMAKE_BOOL=	ENABLE_ICONV
ICONV_USES=		iconv
WIDECHAR_CMAKE_BOOL=	ENABLE_WIDECHAR

PLIST_FILES=	bin/nex \
		bin/nvi \
		bin/nview \
		man/man1/nex.1.gz \
		man/man1/nvi.1.gz \
		man/man1/nview.1.gz

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/nvi ${STAGEDIR}${PREFIX}/bin
	${LN} ${STAGEDIR}${PREFIX}/bin/nvi ${STAGEDIR}${PREFIX}/bin/nex
	${LN} ${STAGEDIR}${PREFIX}/bin/nvi ${STAGEDIR}${PREFIX}/bin/nview
	${INSTALL_MAN} ${WRKSRC}/man/vi.1 \
	    ${STAGEDIR}${MAN1PREFIX}/man/man1/nvi.1
	${LN} -sf nvi.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/nex.1
	${LN} -sf nvi.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/nview.1

.include <bsd.port.mk>
