# New ports collection makefile for:   irssi-xmpp
# Date created:                11 September 2007
# Whom:                        Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	irssi-xmpp
PORTVERSION=	0.13
CATEGORIES=	irc
MASTER_SITES=	http://cybione.org/src/irssi-xmpp/

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Irssi-xmpp is an irssi plugin to connect to the Jabber network

BUILD_DEPENDS=	irssi:${PORTSDIR}/irc/irssi
RUN_DEPENDS=	irssi:${PORTSDIR}/irc/irssi
LIB_DEPENDS=	loudmouth:${PORTSDIR}/net-im/loudmouth

USE_GMAKE=	yes
USE_LDCONFIG=	yes
MAKE_ENV=	IRSSI_INCLUDE="${LOCALBASE}/include/irssi/"

PLIST_FILES=	lib/irssi/modules/libfe_xmpp.so \
		lib/irssi/modules/libxmpp_core.so
PORTDOCS=	README

IGNORE=		Does not work with irc/irssi-0.8.12

do-install:
.for data in core fe-common
	${MKDIR} ${PREFIX}/lib/irssi/modules
	${INSTALL_PROGRAM} ${WRKSRC}/src/${data}/*.so \
		${PREFIX}/lib/irssi/modules
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
