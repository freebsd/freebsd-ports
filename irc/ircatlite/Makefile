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

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-gtk-config=gtk12-config

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
MAKE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

DOCS=		LICENSE INSTALL INSTALL.jp README README.jp

WRKSRC=		${WRKDIR}/IRcatLite

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ircat ${PREFIX}/bin/ircat
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/IRcatLite
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/IRcatLite
.endfor
.endif

.include <bsd.port.post.mk>
