# New ports collection makefile for:   	bitlbee
# Date created:                        	10 June 2003
# Whom:                                 Peter van Dijk <peter@dataloss.nl>
#
# $FreeBSD$
#

PORTNAME=	bitlbee
PORTVERSION=	1.2.8
CATEGORIES=	irc
MASTER_SITES=	http://get.bitlbee.org/src/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brix

MAINTAINER=	brix@FreeBSD.org
COMMENT=	An IRC to other chat networks gateway

LICENSE=	GPLv2
SUB_FILES=	pkg-message
MAN5=		bitlbee.conf.5
MAN8=		bitlbee.8
PORTDOCS=	AUTHORS CHANGES CREDITS FAQ README
PORTEXAMPLES=	bitlbee.conf motd.txt

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20
USE_RC_SUBR=	bitlbee
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS=	DEBUG "Enable debug support" Off \
		IPV6 "Enable IPv6 support" On \
		OPENSSL "Use OpenSSL rather than GnuTLS" Off \
		MSN "Enable MSN protocol support" On \
		JABBER "Enable Jabber (XMPP) protocol support" On \
		OSCAR "Enable OSCAR (ICQ, AIM) protocol support" On \
		YAHOO "Enable Yahoo! protocol support" On \
		TWITTER "Enable Twitter protocol support" On

CONFIGURE_ARGS=	--config=/var/db/bitlbee --strip=0

USERS=		bitlbee
GROUPS=		bitlbee

CONFLICTS=	bitlbee-otr-[0-9]*

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--debug=1
.else
CONFIGURE_ARGS+=--debug=0
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=--ipv6=1
.else
CONFIGURE_ARGS+=--ipv6=0
.endif

.if defined(WITH_OPENSSL)
CONFIGURE_ARGS+=--ssl=openssl
.else
CONFIGURE_ARGS+=--ssl=gnutls
LIB_DEPENDS+=	gnutls.40:${PORTSDIR}/security/gnutls
.endif

.if defined(WITH_MSN)
CONFIGURE_ARGS+=--msn=1
.else
CONFIGURE_ARGS+=--msn=0
.endif

.if defined(WITH_JABBER)
CONFIGURE_ARGS+=--jabber=1
.else
CONFIGURE_ARGS+=--jabber=0
.endif

.if defined(WITH_OSCAR)
CONFIGURE_ARGS+=--oscar=1
.else
CONFIGURE_ARGS+=--oscar=0
.endif

.if defined(WITH_YAHOO)
CONFIGURE_ARGS+=--yahoo=1
.else
CONFIGURE_ARGS+=--yahoo=0
.endif

.if defined(WITH_TWITTER)
CONFIGURE_ARGS+=--twitter=1
.else
CONFIGURE_ARGS+=--twitter=0
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e "s|^EFLAGS=|EFLAGS=${LDFLAGS}|" \
		${WRKSRC}/configure

	@${REINPLACE_CMD} \
		-e "s:/etc/bitlbee/motd.txt:${PREFIX}/etc/bitlbee/motd.txt:" \
		-e "s:/var/lib/bitlbee:/var/db/bitlbee:" \
		${WRKSRC}/bitlbee.conf
	@${REINPLACE_CMD} \
		-e "s:/var/lib/bitlbee:/var/db/bitlbee:" \
		${WRKSRC}/doc/bitlbee.8
.if ${OSVERSION} < 700042
	@${REINPLACE_CMD} \
		-e "s:-iquote:-I:g" \
		${WRKSRC}/configure
.endif

post-install:
	${MKDIR} ${PREFIX}/etc/bitlbee
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/doc/@} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S@^@${WRKSRC}/@} ${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
