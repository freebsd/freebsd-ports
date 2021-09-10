PORTNAME=	SRB2
PORTVERSION=	2.2.9
DISTVERSIONPREFIX=	SRB2_release_
CATEGORIES=	games
MASTER_SITES=	https://github.com/STJr/SRB2/releases/download/SRB2_release_${PORTVERSION}/:assets
DISTFILES+=	SRB2-v${PORTVERSION:C/\.//g}-Full.zip:assets
EXTRACT_ONLY=	STJr-SRB2-SRB2_release_${PORTVERSION}_GH0.tar.gz

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	3D Sonic the Hedgehog fangame

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libgme.so:audio/libgme \
		libopenmpt.so:audio/libopenmpt \
		libpng.so:graphics/png

USES=		cmake sdl

USE_GITHUB=	yes
GH_ACCOUNT=	STJr

USE_SDL=	mixer2 sdl2

CXXFLAGS+=	-DDEFAULTWADLOCATION5=${DATADIR}
LDFLAGS+=	-lexecinfo -lm

post-extract:
	@${MKDIR} ${WRKSRC}/assets/installer
	@cd ${WRKSRC}/assets/installer && ${UNZIP_NATIVE_CMD} ${DISTDIR}/SRB2-v229-Full.zip srb2.pk3
	@cd ${WRKSRC}/assets/installer && ${UNZIP_NATIVE_CMD} ${DISTDIR}/SRB2-v229-Full.zip player.dta
	@cd ${WRKSRC}/assets/installer && ${UNZIP_NATIVE_CMD} ${DISTDIR}/SRB2-v229-Full.zip zones.pk3
	@cd ${WRKSRC}/assets/installer && ${UNZIP_NATIVE_CMD} ${DISTDIR}/SRB2-v229-Full.zip patch.pk3

post-install:
	@${MKDIR} ${STAGEDIR}/${DATADIR}
	@${MV} ${STAGEDIR}/${PREFIX}/srb2.pk3 ${STAGEDIR}/${DATADIR}
	@${MV} ${STAGEDIR}/${PREFIX}/player.dta ${STAGEDIR}/${DATADIR}
	@${MV} ${STAGEDIR}/${PREFIX}/zones.pk3 ${STAGEDIR}/${DATADIR}
	@${MV} ${STAGEDIR}/${PREFIX}/patch.pk3 ${STAGEDIR}/${DATADIR}
	@${MV} ${STAGEDIR}/${PREFIX}/srb2 ${STAGEDIR}/${PREFIX}/bin
	@${MV} ${STAGEDIR}/${PREFIX}/srb2-${PORTVERSION} ${STAGEDIR}/${PREFIX}/bin

.include <bsd.port.mk>
