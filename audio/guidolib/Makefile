PORTNAME=	guidolib
PORTVERSION=	1.7.1 # https://guido.grame.fr/dox/api/ has version in the format N.N.N
PORTEPOCH=	1
CATEGORIES=	audio graphics print

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for graphic rendering of music scores

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmidisharelight.so:audio/midisharelight

USES=		compiler:c++11-lang gl cmake gnome localbase:ldflags pkgconfig qt:5 xorg
USE_QT=		core gui widgets printsupport xml buildtools_build qmake_build
USE_GL=		gl
USE_GNOME=	cairo
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	grame-cncm
GH_TAGNAME=	v${PORTVERSION:S/.//g}

CMAKE_SOURCE_PATH=	${WRKSRC}/build

LDFLAGS+=	-lmidisharelight

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	*
PORTEXAMPLES=	*

BINARY_ALIAS=	qmake=${QMAKE}

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
