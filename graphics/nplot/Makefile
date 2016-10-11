# $FreeBSD$

PORTNAME=	nplot
PORTVERSION=	0.9.11
CATEGORIES=	graphics

MAINTAINER=	cs@innolan.dk
COMMENT=	Charting library for .NET

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgdiplus.so:x11-toolkits/libgdiplus \
		libcairo.so:graphics/cairo
RUN_DEPENDS=	webfonts>=0:x11-fonts/webfonts

USE_GITHUB=	yes
GH_ACCOUNT=	mhowlett
GH_TAGNAME=	9a92e78

SUB_FILES=	NPlot.pc
USES=		mono ssl

PLIST_FILES=	lib/mono/NPlot/NPlot.dll \
		lib/mono/gac/NPlot/0.9.11.0__1d82a50c5d01c44e/NPlot.dll \
		libdata/pkgconfig/NPlot.pc

pre-build:
	openssl enc -base64 -d <${PATCHDIR}/Dynamic.key >${WRKSRC}/src/Dynamic.snk

do-build:
	(cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} xbuild NPlot.csproj \
		/p:Configuration=Release /p:SignAssembly=true \
		/p:AssemblyOriginatorKeyFile=Dynamic.snk)

do-install:
	(cd ${WRKSRC}/src && ${SETENV} MONO_SHARED_DIR=${WRKDIR} ${LOCALBASE}/bin/gacutil \
		-root ${STAGEDIR}${PREFIX}/lib/ -package NPlot -i bin/NPlot.dll)
	(cd ${WRKDIR} && ${INSTALL_DATA} NPlot.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig)

.include <bsd.port.mk>
