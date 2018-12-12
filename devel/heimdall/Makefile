# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	heimdall
PORTVERSION=	1.4.2
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tool suite used to flash firmware onto Samsung mobile devices

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang cmake
USE_GITHUB=	yes

OPTIONS_DEFINE=	DOCS GUI
OPTIONS_DEFAULT=GUI
OPTIONS_SUB=	yes

GUI_USES=	qt:5
GUI_USE=	QT=buildtools_build,core,gui,qmake_build,widgets
GUI_CMAKE_OFF=	-DDISABLE_FRONTEND=YES

GH_ACCOUNT=	Benjamin-Dobell
GH_PROJECT=	Heimdall

PORTDOCS=	README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/heimdall ${STAGEDIR}${PREFIX}/bin

do-install-GUI-on:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/heimdall-frontend ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Linux/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
