# New ports collection makefile for:	irc-transport
# Date created:				12 December 2000
# Whom:					Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
				

PORTNAME=	irc-transport
PORTVERSION=	0.1b-1.40
CATEGORIES=	irc
MASTER_SITES=	http://download.jabber.org/dists/1.4/final/
DISTFILES=	${PORTNAME}-${PORTVERSION}.linux${EXTRACT_SUFX}

MAINTAINER=	leeym@cae.ce.ntu.edu.tw

BUILD_DEPENDS=	${NONEXISTENT}:${JABBER_PORT}:configure
RUN_DEPENDS=	jabberd:${JABBER_PORT}

.include <bsd.port.pre.mk>

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-jabberd=${JABBER_WRKSRC}
JABBER_PORT=	${PORTSDIR}/net/jabber
JABBER_WRKSRC!=	cd ${JABBER_PORT} && ${MAKE} -V WRKSRC

do-install:
	@${MKDIR} ${PREFIX}/lib/jabber/${PORTNAME}
	@${INSTALL_PROGRAM} ${WRKSRC}/src/irc_transport.so ${PREFIX}/lib/jabber/${PORTNAME}
	@${ECHO} ""
	@${ECHO} "============================================================================="
	@${ECHO} "Please read ${WRKSRC}/README first"
	@${ECHO} "and add \"./${PORTNAME}/irc_transport.so\" ${PREFIX}/etc/jabber.xml"
	@${ECHO} "then restart jabberd to enable ${PORTNAME}"
	@${ECHO} "============================================================================="
	@${ECHO} ""

.include <bsd.port.post.mk>
