# Created by: Alfred Perlstein <alfred@FreeBSD.org>
# $FreeBSD$

PORTNAME=	insub
PORTVERSION=	16.0
CATEGORIES=	irc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Some scripts for expressing how you feel on IRC and the web

RUN_DEPENDS=	cowsay:games/cowsay \
		figlet:misc/figlet

USE_GITHUB=	yes
GH_ACCOUNT=	cjones

USES=		perl5 python:2.5+
USE_PERL5=	run

OPTIONS_DEFINE=	COWS
OPTIONS_DEFAULT=COWS
COWS_DESC=	Install a collection of cowsay(1) cows
OPTIONS_SUB=	yes

NO_BUILD=	yes
DATADIR=	${PREFIX}/share/cows

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' \
		${WRKSRC}/${PORTNAME}.py ${WRKSRC}/irssi/${PORTNAME}.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/irssi/scripts
	${INSTALL_DATA} ${WRKSRC}/irssi/${PORTNAME}.pl \
		${STAGEDIR}${PREFIX}/share/irssi/scripts
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/old/cows-extra && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
