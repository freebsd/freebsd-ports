# New ports collection makefile for:	powermanga
# Date created:			26 Jan 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		powermanga
PORTVERSION=		0.78
CATEGORIES=		games
MASTER_SITES=		http://www.tlk.fr/lesjeux/
DISTNAME=		${PORTNAME}

MAINTAINER=		jylefort@brutele.be
COMMENT=		An arcade 2D shoot-em-up

WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_X_PREFIX=		yes
USE_SDL=		sdl mixer
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes

MAN6=			powermanga.6

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/powermanga.6

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/AUTHORS \
		${WRKSRC}/CHANGES \
		${DOCSDIR}
.endif

.include <bsd.port.mk>
