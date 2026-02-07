PORTNAME=	termbox2
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.0
CATEGORIES=	devel

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Terminal rendering library for creating TUIs
WWW=		https://github.com/termbox/termbox2/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	termbox
USE_LDCONFIG=	yes

INSTALL_TARGET=	install install_lib

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so.2.0.0

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/demo && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} "! -name keyboard")
	${INSTALL_PROGRAM} ${WRKSRC}/demo/keyboard ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
