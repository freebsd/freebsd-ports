PORTNAME=	guidolib
DISTVERSION=	1.7.7
PORTEPOCH=	1
CATEGORIES=	audio graphics print

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for graphic rendering of music scores
WWW=		https://guido.grame.fr/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmidisharelight.so:audio/midisharelight

USES=		compiler:c++17-lang cmake gnome localbase:ldflags pkgconfig
USE_GNOME=	cairo
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	grame-cncm

CMAKE_SOURCE_PATH=	${WRKSRC}/build

LDFLAGS+=	-lmidisharelight

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	*
PORTEXAMPLES=	*

PORTSCOUT=	limit:^.*\..* # prevent tags like v171

post-extract:
	@${RM} -r ${WRKSRC}/src/midisharelight

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/* ${STAGEDIR}${PREFIX}/lib/libGUIDOEngine.so.*
	${RM} -r ${STAGEDIR}${DATADIR}/python

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/package/doc/*.pdf ${STAGEDIR}${DOCSDIR}
	${CP} -r ${WRKSRC}/package/doc/html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
