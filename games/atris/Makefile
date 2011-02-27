# New ports collection makefile for:	games/atris
# Date created:			9 Aug 2005
# Whom:				Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	atris
PORTVERSION=	1.0.7
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.sourcefiles.org/Games/Arcade/Block_Based/Tetris/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Atris: Alizarin Tetris

USE_GMAKE=	yes
USE_SDL=	sdl ttf

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=""

MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

post-patch:
# Fix path to ${DATADIR}
	${REINPLACE_CMD} -e 's|\(GAME_INSTALLDIR=\).*|\1"${DATADIR}"|' \
			${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

# Fix SDL include statement
.for f in *.c *.h
	@${FIND} ${WRKSRC} -type f -name "${f}" -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e \
		's|\(#include.*\)SDL/\(SDL.*\)|\1\2|'
.endfor

.if !defined(NOPORTDOCS)
post-install:
# Install documentation (optional)
	@${MKDIR} ${DOCSDIR}
	@${RM} -f ${WRKSRC}/Docs/Makefile*
	@${CP} -R ${WRKSRC}/Docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
