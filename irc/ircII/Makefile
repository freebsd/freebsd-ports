# Created by: torstenb
# $FreeBSD$

PORTNAME=	ircii
PORTVERSION=	20131230
PORTREVISION=	1
CATEGORIES=	irc ipv6
MASTER_SITES=	http://ircii.warped.com/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Small and high extensible IRC client

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes
DATADIR=	${PREFIX}/share/irc
USES=		tar:bzip2

OPTIONS_DEFINE=	IRCBUG EMACS_KEYS
IRCBUG_DESC=	Install ircII bug-reporting script
EMACS_KEYS_DESC=Use emacs meta keys
OPTIONS_SUB=	yes

EMACS_KEYS_CONFIGURE_WITH=	emacs-meta-keys

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/irc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ircflush ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ircbug ${STAGEDIR}${PREFIX}/bin

	${INSTALL_PROGRAM} ${WRKSRC}/ircio ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/wserv ${STAGEDIR}${PREFIX}/libexec

	${INSTALL_MAN} ${WRKSRC}/doc/ircII.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/ircbug.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${LN} -sf ircII.1 ${STAGEDIR}${MANPREFIX}/man/man1/irc.1

	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "help script" ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
