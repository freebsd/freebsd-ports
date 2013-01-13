# $FreeBSD$

PORTNAME=	qjson
PORTVERSION=	0.8.1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Library to manage JSON objects with Qt

LICENSE=	LGPL21

USE_QT4=	corelib moc_build qmake_build rcc_build uic_build
USE_BZIP2=	yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
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
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} \* ${DOCSDIR}
.endif

.include <bsd.port.mk>
