# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	atris
PORTVERSION=	1.0.7
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://www.cs.virginia.edu/~weimer/atris/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Atris: Alizarin Tetris

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
USE_SDL=	sdl ttf

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=""

MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

OPTIONS_DEFINE=	DOCS

post-patch:
# Fix path to ${DATADIR}
	${REINPLACE_CMD} -e 's|\(GAME_INSTALLDIR=\).*|\1"${DATADIR}"|' \
			${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
# Fix install target to use gmake
	${REINPLACE_CMD} -e '/^install:/,/^$$/s/make/$$(MAKE)/' \
		-e '/install_gamedata/ s|target=|&$$(DESTDIR)|' \
		${WRKSRC}/Makefile.in

# Fix SDL include statement
.for f in *.c *.h
	@${FIND} ${WRKSRC} -type f -name "${f}" -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e \
		's|\(#include.*\)SDL/\(SDL.*\)|\1\2|'
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${RM} ${WRKSRC}/Docs/Makefile*
	${CP} -R ${WRKSRC}/Docs/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
