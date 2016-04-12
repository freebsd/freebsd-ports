# $FreeBSD$

PORTNAME=	tbe
PORTVERSION=	0.9.2.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	games

MAINTAINER=	johans@FreeBSD.org
COMMENT=	The Butterfly Effect

BUILD_DEPENDS=	${LOCALBASE}/bin/unzip:archivers/unzip

USES=		cmake compiler:c++11-lib execinfo gmake tar:tgz
USE_QT4=	gui linguisttools_build moc_build qmake_build rcc_build \
		svg uic_build xml

USE_GITHUB=	yes
GH_ACCOUNT=	kaa-ching

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} 's/ make/ $$(MAKE)/' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's:/share/games/tbe/:/share/tbe/:' \
		-e 's:/usr:${PREFIX}: ; s:/games:/bin:' \
		${WRKSRC}/CMakeLists.txt ${WRKSRC}/src/tbe_paths.h

.include <bsd.port.mk>
