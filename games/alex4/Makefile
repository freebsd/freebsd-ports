# Created by: Nikolai Lifanov <lifanov@mail.lifanov.com>

PORTNAME=	alex4
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/allegator/Alex4/source%20and%20data/ \
		SF/lifanov-ports-distfiles/games/${PORTNAME}/:icons
DISTFILES=	alex4src_data.zip ${PORTNAME}.png:icons
EXTRACT_ONLY=	alex4src_data.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Classic platformer with Alex the Allegator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	${LOCALBASE}/lib/libaldmb.a:audio/dumb-allegro
LIB_DEPENDS=	liballeg.so:devel/allegro

DESKTOP_ENTRIES="Alex the Allegator 4" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ActionGame;" ""

WRKSRC=		 ${WRKDIR}/alex4src/src

MAKE_JOBS_UNSAFE=yes

USES=	dos2unix gmake zip

# Upstream seems dead. Don't expect a proper fix.
CFLAGS+=	-fcommon

post-patch:
	@${REINPLACE_CMD} \
		-e 's,%%STAGEDIR%%,${STAGEDIR},g' \
		-e 's,%%DATADIR%%,${DATADIR},g' \
			${WRKSRC}/Makefile

pre-install:
	${STRIP_CMD} ${WRKSRC}/alex4
	${INSTALL_DATA} ${_DISTDIR}${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
