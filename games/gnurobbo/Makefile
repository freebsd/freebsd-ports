PORTNAME=	gnurobbo
PORTVERSION=	0.68
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION:C/^([0-9]+\.[0-9]+)\..*$/\1/}/
EXTRACT_SUFX=	-source.tar.gz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Reimplementation of LK Avalon's Robbo for the Atari XE/XL

LICENSE=	AREV BITSTREAM_VERA GPLv2 CCSP
LICENSE_COMB=	multi
LICENSE_NAME_AREV=	Arev Fonts Copyright
LICENSE_PERMS_AREV=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_FILE_AREV=	${WRKSRC}/LICENSE-ttf
LICENSE_NAME_BITSTREAM_VERA=	Bitstream Vera Fonts Copyright
LICENSE_FILE_BITSTREAM_VERA=	${WRKSRC}/LICENSE-ttf
LICENSE_PERMS_BITSTREAM_VERA=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_NAME_CCSP=		Creative Commons Sampling Plus 1.0
LICENSE_FILE_CCSP=		${WRKSRC}/LICENSE-sound
LICENSE_PERMS_CCSP=		dist-mirror pkg-mirror auto-accept
LICENSE_FILE_GPLv2=		${WRKSRC}/COPYING

USES=		gmake sdl
USE_SDL=	sdl ttf mixer image

MAKE_ENV=	PACKAGE_DATA_DIR="${DATADIR}" \
		BINDIR="${PREFIX}/bin" \
		DOCDIR="${DOCSDIR}"
CFLAGS+=	-fcommon

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

WRKSRC_SUBDIR=	${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^install:/,$$ s|$$([A-Z_]*DIR)|$${DESTDIR}&| g' \
		-e '/^CFLAGS/s/-d//' \
		${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
