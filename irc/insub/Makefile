# New ports collection makefile for:	insub
# Date created:			27 Dec 2003
# Whom:				Alfred Perlstein <alfred@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	insub
PORTVERSION=	9.8
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://gruntle.org/projects/irssi/insub/

MAINTAINER=	alfred@FreeBSD.org
COMMENT=	Some scripts for expressing how you feel on irc and the web

NO_BUILD=	YES

USE_BZIP2=	YES

SCRIPT=		${PORTNAME}.pl

BUILD_DEPENDS+=	cowsay:${PORTSDIR}/games/cowsay
RUN_DEPENDS+=	figlet:${PORTSDIR}/misc/figlet
RUN_DEPENDS+=	${SITE_PERL}/Term/ANSIColor.pm:${PORTSDIR}/devel/p5-Term-ANSIColor

.include <bsd.port.pre.mk>

post-install:
	@${ECHO}
	@${ECHO} "    insub has been installed in irssi's global script store."
	@${ECHO} "    To run, you should type '/script load insub' from within"
	@${ECHO} "    the irssi client."
	@${ECHO}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${SCRIPT} ${LOCALBASE}/bin/${SCRIPT:R}
	${MKDIR} ${LOCALBASE}/share/irssi/scripts/
	${INSTALL_DATA} ${WRKSRC}/${SCRIPT} \
		${LOCALBASE}/share/irssi/scripts/${SCRIPT}
	for i in ${WRKSRC}/cows/* ; do \
		case `basename $$i` in \
			*) ${INSTALL_DATA} $$i ${LOCALBASE}/share/cows; \
		esac \
	done

.include <bsd.port.post.mk>
