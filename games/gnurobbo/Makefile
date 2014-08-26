# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnurobbo
PORTVERSION=	0.66
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION:C/^([0-9]+\.[0-9]+)\..*$/\1/}/
EXTRACT_SUFX=	-source.tar.gz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Reimplementation of LK Avalon's Robbo for the Atari XE/XL

USES=		gmake
USE_SDL=	sdl ttf mixer image

MAKE_ENV=	PACKAGE_DATA_DIR="${DATADIR}" \
		BINDIR="${PREFIX}/bin" \
		DOCDIR="${DOCSDIR}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/define DEBUG_DUMP_VM_USAGE/ d' ${WRKSRC}/game.c
	@${REINPLACE_CMD} -e '/^install:/,$$ s|$$([A-Z_]*DIR)|${STAGEDIR}&| g' \
		-e '/^LIBS=/s/$$/ -lm/' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
