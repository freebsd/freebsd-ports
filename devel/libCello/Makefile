PORTNAME=	libCello
DISTVERSION=	2.1.0
CATEGORIES=	devel
MASTER_SITES=	https://libcello.org/static/

MAINTAINER=	matthew.closson@gmail.com
COMMENT=	Higher level programming in C
WWW=		https://libcello.org/ \
		https://github.com/orangeduck/Cello/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		gmake
USE_LDCONFIG=	yes

MAKE_ENV=	DESTDIR=${STAGEDIR}
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}.so

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
