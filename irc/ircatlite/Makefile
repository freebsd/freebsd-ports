# New ports collection makefile for:	IRcatLite-r20000308
# Date Created:		May 14 2000
# Whom:			Yoshikazu GOTO <goto@snowy.to>
#
# $FreeBSD$
#

PORTNAME=	ircatlite
PORTVERSION=	2000.03.08
CATEGORIES=	irc
MASTER_SITES=	http://www.pp.iij4u.or.jp/~tagami/gtk/
DISTNAME=	IRcatLite-r20000308

MAINTAINER=	goto@snowy.to

USE_GTK=	yes
GNU_CONFIGURE=	yes

USE_X_PREFIX=	yes

DOCS=		LICENSE INSTALL INSTALL.jp README README.jp

WRKSRC=		${WRKDIR}/IRcatLite

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ircat ${PREFIX}/bin/ircat
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/IRcatLite
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/IRcatLite
.endfor
.endif

.include <bsd.port.mk>
