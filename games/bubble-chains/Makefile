PORTNAME=	bubble-chains
PORTVERSION=	0.2.0
DISTVERSIONPREFIX=	V
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free crossplatform 2D arcade-puzzle game
WWW=		https://github.com/ArsMasiuk/bubble-chains

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	ArsMasiuk

USES=		qmake qt:5 xorg
USE_QT=		core gui widgets xml opengl multimedia x11extras \
		qmake_build buildtools_build
USE_XORG=	x11 xrandr

QMAKE_ARGS=	DATADIR="${DATADIR}"

PORTDOCS=	README
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/main.cpp

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
