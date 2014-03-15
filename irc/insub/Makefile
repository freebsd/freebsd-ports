# Created by: Alfred Perlstein <alfred@FreeBSD.org>
# $FreeBSD$

PORTNAME=		insub
PORTVERSION=	15.1
CATEGORIES=		irc
MASTER_SITES=	http://cloud.github.com/downloads/cjones/insub/

MAINTAINER=		adamw@FreeBSD.org
COMMENT=		Some scripts for expressing how you feel on IRC and the web

RUN_DEPENDS=	cowsay:${PORTSDIR}/games/cowsay \
				figlet:${PORTSDIR}/misc/figlet

USES=		perl5 tar:bzip2
USE_PERL5=	run

NO_BUILD=	yes
SCRIPT=		${PORTNAME}.pl
DATADIR=	${PREFIX}/share/cows

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${SCRIPT} ${STAGEDIR}${PREFIX}/bin/${SCRIPT:R}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/irssi/scripts/
	${INSTALL_DATA} ${WRKSRC}/${SCRIPT} \
		${STAGEDIR}${PREFIX}/share/irssi/scripts/${SCRIPT}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/cows && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
