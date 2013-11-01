# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	digger
PORTVERSION=	20020314
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.digger.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FreeBSD graphics console (VGL) version of the famous Digger game

ONLY_FOR_ARCHS=	i386	# Alphas don't have libvgl yet...

MAKEFILE=	Makefile.fbsd

OPTIONS_DEFINE=	SOUND

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSOUND}
USE_SDL=	yes
MAKE_ENV=	SOUND=yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|Software|Software\\n\\|g' ${WRKSRC}/alpha.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/digger ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}/var/games/digger
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/digger.txt ${STAGEDIR}${DOCSDIR}
.if ${PORT_OPTIONS:MSOUND}
	@${ECHO_MSG}
	@${ECHO_MSG} "Use \"digger /A\" command to run Digger with sound enabled."
	@${ECHO_MSG}
.endif

.include <bsd.port.mk>
