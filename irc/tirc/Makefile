# New ports collection makefile for:        tirc IRC-Client
# Date created:		14 August 1999
# Whom:			Dominik Rothert <dr@domix.de>
#
# $FreeBSD$
#

PORTNAME=	tirc
PORTVERSION=	1.2
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.mayn.de/pub/unix/network/irc/tirc/

MAINTAINER=	dr@astorit.com

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--with-ansi-colours"
MAKE_FLAGS=	CONF_ARGS="--prefix=${PREFIX}"
MAN1=		tirc.1

post-patch:
	@${PERL} -pi -e 's:__PREFIX__:${PREFIX}:g' ${WRKSRC}/*.c ${WRKSRC}/*.1

post-install:
	strip ${PREFIX}/bin/tirc
	${MKDIR} ${PREFIX}/share/tirc
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/dot.tircrc ${PREFIX}/share/tirc/tircrc

.include <bsd.port.mk>
