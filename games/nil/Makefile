# New ports collection makefile for:	nil
# Date created:				28 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nil
PORTVERSION=	000928
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	${PORTNAME} sobomax

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer

WRKSRC=		${WRKDIR}/${PORTNAME}/${PORTNAME}

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

pre-patch:
	@find ${WRKSRC} \( -name "*.[ch]" -or -name "*.cpp" \) | \
		xargs ${PERL} -pi -e 's|"SDL/|"|g ; s|<SDL/|<|g'
	@find ${WRKSRC}/.. -type d -name CVS | xargs ${RM} -rf

post-configure:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/nil/configuration.cpp

post-install:
	@${MKDIR} ${PREFIX}/share/nil
	@cd ${WRKSRC}/..; tar cf - gfx | \
		(cd ${PREFIX}/share/nil ; ${TAR} --unlink -xf - )
	@${INSTALL_MAN} ${WRKSRC}/../docs/NiL-HOWTO.txt ${PREFIX}/share/nil/README
	@${ECHO_MSG} ""
	@${ECHO_MSG} "See ${PREFIX}/share/nil/README for usage instructions."
	@${ECHO_MSG} ""

.include <bsd.port.mk>
