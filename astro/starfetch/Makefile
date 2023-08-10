PORTNAME=	starfetch
DISTVERSION=	0.0.4
CATEGORIES=	astro
MASTER_SITES=	https://github.com/Haruno19/starfetch/releases/download/${DISTVERSION}/

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Command line tool that displays constellations
WWW=		https://github.com/Haruno19/starfetch

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

CXXFLAGS+=	-std=c++17

post-patch:
	@${REINPLACE_CMD} -e '/^string path = /s#=.*#= "${DATADIR}/";#' ${WRKSRC}/src/starfetch.cpp

do-build:
	${CXX} ${CPPFLAGS} ${CXXFLAGS} ${LDFLAGS} ${WRKSRC}/src/starfetch.cpp -o ${WRKSRC}/starfetch

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/starfetch ${STAGEDIR}${PREFIX}/bin/starfetch
	(cd ${WRKSRC}/res && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} '! -name \._*')

.include <bsd.port.mk>
