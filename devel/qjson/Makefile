# $FreeBSD$

PORTNAME=	qjson
PORTVERSION=	0.8.1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Library to manage JSON objects with Qt

LICENSE=	LGPL21

USE_QT4=	corelib moc_build qmake_build rcc_build uic_build
USES=		cmake tar:bzip2
USE_LDCONFIG=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	doxygen:devel/doxygen
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/pkgconfig,/../libdata/pkgconfig,' \
		${WRKSRC}/CMakeLists.txt

post-build:
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC}/doc && doxygen
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
