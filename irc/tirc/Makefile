# New ports collection makefile for:        tirc IRC-Client
# Version required:	1.2
# Date created:		14 August 1999
# Whom:			Dominik Rothert <dr@domix.de>
#
# $FreeBSD$
#

DISTNAME=	tirc-1.2
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.mayn.de/pub/unix/software/Network/Irc/tirc/

MAINTAINER=	dr@domix.de

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--with-ansi-colours"
MAKE_FLAGS=	CONF_ARGS="--prefix=${PREFIX}"
MAN1=		tirc.1

post-patch:
	@${PERL} -pi -e 's:__PREFIX__:${PREFIX}:g' ${WRKSRC}/*.c
	@${PERL} -pi -e 's:__PREFIX__:${PREFIX}:g' ${WRKSRC}/*.1

post-install:
	strip ${PREFIX}/bin/tirc
	${MKDIR} ${PREFIX}/share/tirc
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/dot.tircrc ${PREFIX}/share/tirc/tircrc

.include <bsd.port.mk>
