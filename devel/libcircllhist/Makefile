PORTNAME=	libcircllhist
PORTVERSION=	g20211005
CATEGORIES=	devel

MAINTAINER=	fuz@fuz.su
COMMENT=	Circonus log-linear histogram C implementation

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf gmake
USE_GITHUB=	yes
GH_ACCOUNT=	openhistogram
GH_TAGNAME=	79fab69ee82597e3940cab017d7b0cd50ef3e9c1
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
ALL_TARGET=	all

OPTIONS_DEFINE=	DOCS
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
DOCS_ALL_TARGET=	docs

post-install:
	${LN} -s libcircllhist.so.0.0.1 \
		${STAGEDIR}${PREFIX}/lib/libcircllhist.so.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/circllhist_print
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcircllhist.so.0.0.1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
