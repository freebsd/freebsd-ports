# Created by: Alfred Perlstein <alfred@FreeBSD.org>
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
USE_PERL5=	run

USE_BZIP2=	yes

NO_BUILD=	yes

SCRIPT=	${PORTNAME}.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${SCRIPT} ${STAGEDIR}${PREFIX}/bin/${SCRIPT:R}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/irssi/scripts/
	${INSTALL_DATA} ${WRKSRC}/${SCRIPT} \
		${STAGEDIR}${PREFIX}/share/irssi/scripts/${SCRIPT}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/cows/
	cd ${WRKSRC} && \
		${FIND} cows | ${CPIO} -pdmu ${STAGEDIR}${PREFIX}/share/

.include <bsd.port.mk>
