# $FreeBSD$

PORTNAME=	nplot
PORTVERSION=	0.9.10
CATEGORIES=	graphics
MASTER_SITES=	http://suyai.innolan.net/
DISTNAME=	nplot-0.9.10.1

MAINTAINER=	cs@innolan.dk
COMMENT=	Charting library for .NET

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgdiplus.so:x11-toolkits/libgdiplus \
		libcairo.so:graphics/cairo
RUN_DEPENDS=	webfonts>=0:x11-fonts/webfonts

USES=		mono
WRKSRC=		${WRKDIR}/anguist-nplot-bed1ca9c4048

PLIST_FILES=	lib/mono/gac/NPlot/0.9.10.1__4eda430eb4395eb1/NPlot.dll

do-install:
	${LOCALBASE}/bin/gacutil -root ${STAGEDIR}${PREFIX}/lib/ -gacdir ${STAGEDIR}${PREFIX}/lib -i ${WRKSRC}/bin/NPlot.dll

.include <bsd.port.mk>
