# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	heimdall
PORTVERSION=	1.4.2
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tool suite used to flash firmware onto Samsung mobile devices

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
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

.include <bsd.port.pre.mk>

# does not compile with clang 6.0.0
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1101513
USE_GCC=	yes
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/heimdall ${STAGEDIR}${PREFIX}/bin

do-install-GUI-on:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/heimdall-frontend ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Linux/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
