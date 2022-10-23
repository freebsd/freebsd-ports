PORTNAME=	starfetch
DISTVERSION=	0.0.3
CATEGORIES=	astro
MASTER_SITES=	https://github.com/Haruno19/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Command line tool that displays constellations
WWW=		https://github.com/Haruno19/starfetch/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

CXXFLAGS+=	-std=c++17

post-patch:
	@${REINPLACE_CMD} -e '/^string path = /s#=.*#= "${DATADIR}/";#' ${WRKSRC}/src/${PORTNAME}.cpp

do-build:
	${CXX} ${CXXFLAGS} ${WRKSRC}/src/${PORTNAME}.cpp -o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/res && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
