# New ports collection makefile for:	Digger
# Date created:				14 April 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	digger
PORTVERSION=	20020314
CATEGORIES=	games
MASTER_SITES=	http://www.digger.org/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FreeBSD graphics console (VGL) version of the famous Digger game

ONLY_FOR_ARCHS=	i386	# Alphas don't have libvgl yet...

MAKEFILE=	Makefile.fbsd

.if defined(WITH_SOUND)
USE_SDL=	yes
MAKE_ENV=	SOUND=yes
.endif

pre-everything::
.if !defined(WITH_SOUND)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Please use \"make -DWITH_SOUND\" if you want to build the game with sound support."
	@${ECHO_MSG} ""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|Software|Software\\n\\|g' ${WRKSRC}/alpha.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/digger ${PREFIX}/bin
	@${MKDIR} /var/games/digger
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/digger.txt ${DOCSDIR}
.endif
.if defined(WITH_SOUND)
	@${ECHO_MSG}
	@${ECHO_MSG} "Use \"digger /A\" command to run Digger with sound enabled."
	@${ECHO_MSG}
.endif

.include <bsd.port.mk>
