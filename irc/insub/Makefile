# New ports collection makefile for:	insub
# Date created:			27 Dec 2003
# Whom:				Alfred Perlstein <alfred@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	insub
PORTVERSION=	7.0
PORTREVISION?=	0
CATEGORIES?=	irc
MASTER_SITES=	http://gruntle.org/projects/irssi/insub/

MAINTAINER?=	alfred@FreeBSD.org
COMMENT?=	Some scripts for expressing how you really feel on irc

NO_BUILD=	YES

SCRIPT=		${PORTNAME}.pl

BUILD_DEPENDS+=	irssi:${PORTSDIR}/irc/irssi+perl
RUN_DEPENDS+=	figlet:${PORTSDIR}/misc/figlet
BUILD_DEPENDS+=	cowsay:${PORTSDIR}/games/cowsay

.include <bsd.port.pre.mk>

post-install:
	@${ECHO}
	@${ECHO} "    insub has been installed in irssi's global script store."
	@${ECHO} "    To run, you should type '/script load insub' from within"
	@${ECHO} "    the irssi client."
	@${ECHO}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${SCRIPT} ${LOCALBASE}/bin/${SCRIPT:R}
	${INSTALL_DATA} ${WRKSRC}/${SCRIPT} \
		${LOCALBASE}/share/irssi/scripts/${SCRIPT}
	for i in ${WRKSRC}/cows/* ; do \
		${INSTALL_DATA} $$i ${LOCALBASE}/share/cows; \
	done


.include <bsd.port.post.mk>
