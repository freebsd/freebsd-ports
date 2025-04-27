PORTNAME=	focuswriter
DISTVERSION=	1.8.11
CATEGORIES=	editors
MASTER_SITES=	https://gottcode.org/${PORTNAME}/

PATCH_SITES=	https://github.com/gottcode/focuswriter/commit/
PATCHFILES+=	dd74ed4559a141653a06e7984c1251b992925775.patch:-p1 # Fix build with Qt >= 6.9.0

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Simple, distraction-free writing environment
WWW=		https://gottcode.org/focuswriter/

LICENSE=	GPLv3+ LGPL3+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3+ =	${WRKSRC}/resources/images/icons/oxygen/COPYING

LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell

USES=		cmake desktop-file-utils gettext-tools gl iconv pkgconfig qt:6 \
		tar:bz2
USE_GL=		opengl
USE_QT=		base multimedia tools:build

PORTDATA=	*
PORTDOCS=	CREDITS ChangeLog README
OPTIONS_DEFINE=	DOCS LTO

LTO_CMAKE_BOOL=	ENABLE_LINK_TIME_OPTIMIZATION

post-install-DOCS-on:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
