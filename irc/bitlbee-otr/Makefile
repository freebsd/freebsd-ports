# New ports collection makefile for:   	bitlbee
# Date created:                        	8 August 2008
# Whom:                                 Ashish Shukla <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	bitlbee-otr
PORTVERSION=	1.2.8
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://fbsd.zlonet.ru/distfiles/ \
		http://wahjava.users.sourceforge.net/

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	An IRC to other chat networks gateway with support for OTR

SUB_FILES=	pkg-message
MAN5=		bitlbee.conf.5
MAN8=		bitlbee.8
PORTDOCS=	AUTHORS CHANGES CREDITS FAQ README
PORTEXAMPLES=	bitlbee.conf motd.txt
CONFLICTS=	bitlbee-[0-9]*

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20
USE_RC_SUBR=	bitlbee
PKGMESSAGE=	${WRKDIR}/pkg-message

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS=	MSN "Enable MSN protocol support" On \
		DEBUG "Create debuggable binary" Off \
		OPENSSL "Use openssl rather than gnutls" Off \
		IPV6 "Compile IPV6 support" On \
		XMPP "Enable XMPP protocol support" On \
		OSCAR "Enable OSCAR (ICQ,AIM) protocol support" On \
		YAHOO "Enable Yahoo protocol support" On \
		TWITTER "Enable Twitter protocol support" On

CONFIGURE_ARGS=	--config=/var/db/bitlbee --strip=0

BITLBEEUSER?=	bitlbee
BITLBEEGROUP?=	bitlbee
BITLBEEDIR?=	/nonexistent

BITLBEEUID=	914
BITLBEEGID=	${BITLBEEUID}

PLIST_SUB=	BITLBEEUSER=${BITLBEEUSER} \
		BITLBEEGROUP=${BITLBEEGROUP}

SUB_LIST+=	BITLBEEUSER=${BITLBEEUSER} \
		BITLBEEGROUP=${BITLBEEGROUP} \
		BITLBEEDIR=${BITLBEEDIR} \
		BITLBEEUID=${BITLBEEUID} \
		BITLBEEGID=${BITLBEEGID}

SUB_FILES+=	pkg-install pkg-deinstall

.include <bsd.port.options.mk>

.if !defined(WITHOUT_MSN)
CONFIGURE_ARGS+=--msn=1
.else
CONFIGURE_ARGS+=--msn=0 --ssl=bogus
.endif

.if !defined(WITHOUT_XMPP)
CONFIGURE_ARGS+=--jabber=1
.else
CONFIGURE_ARGS+=--jabber=0
.endif

.if !defined(WITHOUT_OSCAR)
CONFIGURE_ARGS+=--oscar=1
.else
CONFIGURE_ARGS+=--oscar=0
.endif

.if !defined(WITHOUT_YAHOO)
CONFIGURE_ARGS+=--yahoo=1
.else
CONFIGURE_ARGS+=--yahoo=0
.endif

.if defined(WITH_OPENSSL)
CONFIGURE_ARGS+=--ssl=openssl
.else
CONFIGURE_ARGS+=--ssl=gnutls
LIB_DEPENDS+=	gnutls.40:${PORTSDIR}/security/gnutls
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--debug=1
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=--ipv6=0
.endif

.if !defined(WITHOUT_TWITTER)
CONFIGURE_ARGS+=--twitter=1
.else
CONFIGURE_ARGS+=--twitter=0
.endif

LIB_DEPENDS+=	otr.4:${PORTSDIR}/security/libotr
CONFIGURE_ARGS+=--otr=1

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
	@${REINPLACE_CMD} -e "s:-iquote:-I:g" ${WRKSRC}/configure
.endif

pre-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${MKDIR} ${PREFIX}/etc/bitlbee
	${MKDIR} -m 0700 /var/db/bitlbee
	${CHOWN} -R ${BITLBEEUSER}:${BITLBEEGROUP} /var/db/bitlbee
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/doc/@} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S@^@${WRKSRC}/@} ${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
