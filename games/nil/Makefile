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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multiplayer game that can be described as Quake in 2D or Worms done right

LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer

WRKSRC=		${WRKDIR}/${PORTNAME}/${PORTNAME}

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile (bad C++ code)"
.endif

pre-patch:
	@${FIND} ${WRKSRC} \( -name "*.[ch]" -or -name "*.cpp" \) | \
		${XARGS} ${PERL} -pi -e 's|"SDL/|"|g ; s|<SDL/|<|g'
	@${FIND} ${WRKSRC}/.. -type d -name CVS | ${XARGS} ${RM} -rf

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

.include <bsd.port.post.mk>
