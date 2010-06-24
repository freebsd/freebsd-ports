# New ports collection makefile for:   irssi-xmpp
# Date created:                11 September 2007
# Whom:                        Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	irssi-xmpp
PORTVERSION=	0.51
CATEGORIES=	irc
MASTER_SITES=	http://cybione.org/~irssi-xmpp/files/

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Irssi-xmpp is an irssi plugin to connect to the Jabber network

BUILD_DEPENDS=	irssi:${PORTSDIR}/irc/irssi
RUN_DEPENDS=	irssi:${PORTSDIR}/irc/irssi
LIB_DEPENDS=	loudmouth:${PORTSDIR}/net-im/loudmouth

USE_LDCONFIG=	yes

PLIST_FILES=	lib/irssi/modules/libfe_xmpp.so \
		lib/irssi/modules/libtext_xmpp.so \
		lib/irssi/modules/libxmpp_core.so
PORTDOCS=	README \
		FAQ \
		GENERAL \
		INTERNAL \
		MUC \
		STARTUP \
		XEP

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

post-configure:
	@${REINPLACE_CMD} "/ggdb/d" ${WRKSRC}/config.mk

do-install:
.for data in core fe-common fe-text
	${MKDIR} ${PREFIX}/lib/irssi/modules
	${INSTALL_PROGRAM} ${WRKSRC}/src/${data}/*.so \
		${PREFIX}/lib/irssi/modules
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/GENERAL ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/INTERNAL ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/MUC ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/STARTUP ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/XEP ${DOCSDIR}
.endif

.include <bsd.port.mk>
