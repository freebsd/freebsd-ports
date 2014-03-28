# Created by: Alfred Perlstein <alfred@FreeBSD.org>
# $FreeBSD$

PORTNAME=		insub
PORTVERSION=	16.0
CATEGORIES=		irc
MASTER_SITES=	http://github.com/cjones/${PORTNAME}/archive/${DISTNAME}.tar.gz?dummy=/

MAINTAINER=		adamw@FreeBSD.org
COMMENT=		Some scripts for expressing how you feel on IRC and the web

RUN_DEPENDS=	cowsay:${PORTSDIR}/games/cowsay \
				figlet:${PORTSDIR}/misc/figlet

USES=		perl5
USE_PERL5=	run
USE_PYTHON=	2.5+

OPTIONS_DEFINE=	COWS
OPTIONS_DEFAULT=COWS
COWS_DESC=		Install a collection of cowsay(1) cows
OPTIONS_SUB=	yes

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTNAME}
DATADIR=	${PREFIX}/share/cows

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' \
		${WRKSRC}/${PORTNAME}.py ${WRKSRC}/irssi/${PORTNAME}.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/irssi/scripts
	${INSTALL_DATA} ${WRKSRC}/irssi/${PORTNAME}.pl \
		${STAGEDIR}${PREFIX}/share/irssi/scripts
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/old/cows-extra && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
