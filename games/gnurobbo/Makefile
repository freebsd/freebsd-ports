# New ports collection makefile for:	gnurobbo
# Date created:		05 Mar 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnurobbo
PORTVERSION=	0.65.6
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION:C/\.[0-9]$//}
EXTRACT_SUFX=	-source.tar.gz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Reimplementation of LK Avalon's Robbo for the Atari XE/XL

USE_GMAKE=	yes
USE_SDL=	sdl ttf mixer image

MAKE_ENV=	PACKAGE_DATA_DIR="${DATADIR}" \
		BINDIR="${PREFIX}/bin" \
		DOCDIR="${DOCSDIR}"

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e '/define DEBUG_DUMP_VM_USAGE/ d' ${WRKSRC}/game.c
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/DOCDIR/ d' ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
