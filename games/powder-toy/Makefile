# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	powder-toy
PORTVERSION=	92.1
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	.332 # build number, not part of official version
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	'Falling sand' physics sandbox with air pressure and velocity support

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfftw3f.so:math/fftw3-float \
		libfftw3.so:math/fftw3

USE_GITHUB=	yes
GH_ACCOUNT=	simtr
GH_PROJECT=	The-Powder-Toy

USES=		scons localbase:ldflags lua:51
USE_SDL=	sdl
USE_XORG=	x11

MAKE_ENV=	LINKFLAGS="${LINKFLAGS}"

SUB_FILES=	${PORTNAME}.sh

PORTDOCS=	README.md TODO

DESKTOP_ENTRIES="The Powder Toy" \
		"" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.ico" \
		"${PORTNAME}" \
		"Game;Simulation;" \
		""

OPTIONS_DEFINE=		DOCS OPTIMIZED_CFLAGS SSE
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS
OPTIONS_DEFAULT_amd64=	SSE
# upstream also uses -funsafe-loop-optimizations, but it's not supported by clang
OPTIMIZED_CFLAGS_CXXFLAGS=	-O3 -ftree-vectorize -funsafe-math-optimizations -ffast-math -fomit-frame-pointer
SSE_MAKE_ARGS_OFF=	--no-sse

post-patch:
	@${REINPLACE_CMD} -e '/#include/ s|lua5.1/|lua51/|' ${WRKSRC}/src/lua/LuaCompat.h

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/build/powder* ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/resources/powder.ico ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.ico

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
