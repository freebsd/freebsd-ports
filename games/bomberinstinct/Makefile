# New ports collection makefile for:	bomberinstinct
# Date created:				28 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bomberinstinct
PORTVERSION=	0.8.21
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://harpe.dptmaths.ens-cachan.fr/U/gesbert/dl/
DISTNAME=	BomberInstinct-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer

WRKSRC=		${WRKDIR}/BomberInstinct

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_GMAKE=	yes
MAKE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

pre-patch:
	@find ${WRKSRC} -name "*.[ch]" | xargs ${PERL} -pi -e 's|<SDL/|<|g'

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bi ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/Nived/nived ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/Spred/spred ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/BomberInstinct
	@${INSTALL_DATA} ${WRKSRC}/bi.cfg ${PREFIX}/share/BomberInstinct
	@cd ${WRKSRC}; tar cf - Decors Sprites Niveaux Bruitages | \
		(cd ${PREFIX}/share/BomberInstinct; ${TAR} --unlink -xf - )

.include <bsd.port.mk>
