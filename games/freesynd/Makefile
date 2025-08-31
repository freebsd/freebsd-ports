PORTNAME=	freesynd
DISTVERSION=	0.8
DISTVERSIONSUFFIX=	-Source
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	Freesynd-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Reimplementation of the classic Bullfrog game Syndicate
WWW=		http://freesynd.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng16.so:graphics/png

USES=		cmake sdl zip
USE_SDL=	image2 mixer2 sdl2

CMAKE_ARGS=	-DCMAKE_INSTALL_DOCDIR=${DOCSDIR}

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		DOXYGEN
OPTIONS_DEFAULT=	DOXYGEN
OPTIONS_SUB=		yes

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

post-patch-DOXYGEN-off:
	@${REINPLACE_CMD} -e '/find_package(Doxygen)/d' \
		${WRKSRC}/CMakeLists.txt

post-install:
	@${MV} ${STAGEDIR}/${ETCDIR}/freesynd.ini \
		${STAGEDIR}/${ETCDIR}/freesynd.ini.sample

.include <bsd.port.mk>
