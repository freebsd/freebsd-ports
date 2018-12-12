# $FreeBSD$

PORTNAME=	tbe
PORTVERSION=	0.9.2.1
DISTVERSIONPREFIX=	v
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Butterfly Effect

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

BUILD_DEPENDS=	${LOCALBASE}/bin/unzip:archivers/unzip

USE_GITHUB=	yes
GH_ACCOUNT=	kaa-ching

USES=		cmake compiler:c++11-lib qt:4
USE_QT=		corelib gui linguisttools_build moc_build qmake_build rcc_build \
		svg uic_build xml

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's/ make/ $$(MAKE)/' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's:/share/games/tbe/:/share/tbe/:' \
		-e 's:/usr:${PREFIX}: ; s:/games:/bin:' \
		${WRKSRC}/CMakeLists.txt ${WRKSRC}/src/tbe_paths.h

.include <bsd.port.mk>
