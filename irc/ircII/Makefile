# Created by: torstenb
# $FreeBSD$

PORTNAME=		ircii
PORTVERSION=	20131230
PORTREVISION=	1
CATEGORIES=		irc ipv6
MASTER_SITES=	http://ircii.warped.com/

MAINTAINER=		adamw@FreeBSD.org
COMMENT=		Small and high extensible IRC client

LICENSE=		BSD3CLAUSE

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	IRCLIB=${PREFIX}/share/irc
DATADIR=		${PREFIX}/share/irc
USES=			tar:bzip2

OPTIONS_DEFINE=	IRCBUG
IRCBUG_DESC=	Install ircII bug-reporting script

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} irc ircflush ${STAGEDIR}${PREFIX}/bin)
	${INSTALL_SCRIPT} ${WRKSRC}/ircbug ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ircio wserv ${STAGEDIR}${PREFIX}/libexec)
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} ircII.1 ircbug.1 ${STAGEDIR}${MANPREFIX}/man/man1)
	${LN} -s ircII.1 ${STAGEDIR}${MANPREFIX}/man/man1/irc.1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "help script" ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
