# Created by: Alfred Perlstein <alfred@freebsd.org>
# $FreeBSD$

PORTNAME=	insub
PORTVERSION=	15.1
CATEGORIES=	irc
MASTER_SITES=	http://cloud.github.com/downloads/cjones/insub/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Some scripts for expressing how you feel on IRC and the web

RUN_DEPENDS=	cowsay:${PORTSDIR}/games/cowsay \
		figlet:${PORTSDIR}/misc/figlet

USES=	perl5

NO_BUILD=	YES

USE_BZIP2=	YES
USE_PERL5=	run

SCRIPT=	${PORTNAME}.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${SCRIPT} ${PREFIX}/bin/${SCRIPT:R}
	${MKDIR} ${PREFIX}/share/irssi/scripts/
	${INSTALL_DATA} ${WRKSRC}/${SCRIPT} \
		${PREFIX}/share/irssi/scripts/${SCRIPT}
	${MKDIR} ${PREFIX}/share/cows/
	cd ${WRKSRC} && \
		${FIND} cows | ${CPIO} -pdmu ${PREFIX}/share/

.include <bsd.port.mk>
