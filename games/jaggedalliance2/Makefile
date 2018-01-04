# Created by: Christoph Mallon <christoph.mallon@gmx.de>
# $FreeBSD$

PORTNAME=	ja2
PORTVERSION=	0.14.01
CATEGORIES=	games
MASTER_SITES=	https://bitbucket.org/gennady/ja2-stracciatella/get/
DISTNAME=	v${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Port of "Jagged Alliance 2" using SDL

# Ignore this if you feel adventurous
ONLY_FOR_ARCHS=		aarch64 amd64 arm armv6 armv7 i386
ONLY_FOR_ARCHS_REASON=	Needs a little endian environment

NO_CDROM=	License only permits non-commerical use

USES=		gmake tar:bzip2
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_SDL=	sdl

MAKE_ENV=	Q=

WRKSRC=		${WRKDIR}/gennady-ja2-stracciatella-5585014471a7
SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|/some/place/where/the/data/is|${DATADIR}|' \
		${WRKSRC}/sgp/SGP.cc

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ja2
	${INSTALL_DATA} ${WRKSRC}/_build/distr-files-linux/ja2-stracciatella.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/Build/Res/jagged3.ico \
		${STAGEDIR}${PREFIX}/share/pixmaps/jagged2.ico

.include <bsd.port.mk>
