PORTNAME=	gnurobbo
PORTVERSION=	0.68
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION:C/^([0-9]+\.[0-9]+)\..*$/\1/}/
EXTRACT_SUFX=	-source.tar.gz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Reimplementation of LK Avalon's Robbo for the Atari XE/XL

BROKEN_FreeBSD_13=	ld: error: duplicate symbol: K_direction
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: K_direction

USES=		gmake sdl
USE_SDL=	sdl ttf mixer image

MAKE_ENV=	PACKAGE_DATA_DIR="${DATADIR}" \
		BINDIR="${PREFIX}/bin" \
		DOCDIR="${DOCSDIR}"

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
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
