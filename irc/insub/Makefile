# New ports collection makefile for:	insub
# Date created:			27 Dec 2003
# Whom:				Alfred Perlstein <alfred@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	insub
PORTVERSION=	13.0
CATEGORIES=	irc
MASTER_SITES=	http://gruntle.org/projects/irssi/insub/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Some scripts for expressing how you feel on IRC and the web

NO_BUILD=	YES

USE_BZIP2=	YES
USE_PERL5=	5.6+

SCRIPT=	${PORTNAME}.pl

RUN_DEPENDS=	cowsay:${PORTSDIR}/games/cowsay \
		figlet:${PORTSDIR}/misc/figlet

post-install:
	@${ECHO}
	@${ECHO} "    To use insub in irssi, type '/script load insub'"
	@${ECHO} "    from within the irssi client."
	@${ECHO}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${SCRIPT} ${PREFIX}/bin/${SCRIPT:R}
	${MKDIR} ${PREFIX}/share/irssi/scripts/
	${INSTALL_DATA} ${WRKSRC}/${SCRIPT} \
		${PREFIX}/share/irssi/scripts/${SCRIPT}
	${MKDIR} ${PREFIX}/share/cows/
	cd ${WRKSRC} && \
		${FIND} cows | ${CPIO} -pdmvu ${PREFIX}/share/

.include <bsd.port.mk>
