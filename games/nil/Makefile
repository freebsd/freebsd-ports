# New ports collection makefile for:	nil
# Date created:				28 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nil
PORTVERSION=	000928
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sobomax

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multiplayer game that can be described as Quake in 2D or Worms done right

WRKSRC=		${WRKDIR}/${PORTNAME}/${PORTNAME}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_SDL=	mixer sdl

pre-patch:
	@${FIND} ${WRKSRC} \( -name "*.[ch]" -or -name "*.cpp" \) | \
		${XARGS} ${REINPLACE_CMD} -e 's|"SDL/|"|g ; s|<SDL/|<|g'
	@${FIND} ${WRKSRC}/.. -type d -name CVS | ${XARGS} ${RM} -rf
	@${REINPLACE_CMD} -e 's|iostream.h|iostream|' ${WRKSRC}/nil/systemheaders.h

post-configure:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/nil/configuration.cpp

post-install:
	@${MKDIR} ${PREFIX}/share/nil
	@cd ${WRKSRC}/..; tar cf - gfx | \
		(cd ${PREFIX}/share/nil ; ${TAR} --unlink -xf - )
	@${INSTALL_MAN} ${WRKSRC}/../docs/NiL-HOWTO.txt ${PREFIX}/share/nil/README
	@${ECHO_MSG} ""
	@${ECHO_MSG} "See ${PREFIX}/share/nil/README for usage instructions."
	@${ECHO_MSG} ""

.include <bsd.port.mk>
