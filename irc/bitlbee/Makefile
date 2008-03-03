# New ports collection makefile for:   	bitlbee
# Date created:                        	10 June 2003
# Whom:                                 Peter van Dijk <peter@dataloss.nl>
#
# $FreeBSD$
#

PORTNAME=	bitlbee
PORTVERSION=	1.0.4
PORTREVISION=	2
CATEGORIES=	irc
MASTER_SITES=	http://get.bitlbee.org/src/

PATCH_SITES=	http://get.bitlbee.org/patches/

MAINTAINER=	brix@FreeBSD.org
COMMENT=	An IRC to other chat networks gateway

SUB_FILES=	pkg-message
MAN5=		bitlbee.conf.5
MAN8=		bitlbee.8
PORTDOCS=	AUTHORS CHANGES CREDITS FAQ README
PORTEXAMPLES=	bitlbee.conf motd.txt

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20
USE_GETOPT_LONG=yes
USE_RC_SUBR=	bitlbee
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS=	MSN "Enable MSN protocol support" On \
		LDAP "Enable LDAP authentication support" Off \
		RECODE "Enable oscar_recode_charset" Off \
		DEBUG "Create debuggable binary" Off \
		OPENSSL "Use openssl rather than gnutls" Off \
		IPV6 "Compile IPV6 support" On

CONFIGURE_ARGS=	--config=/var/db/bitlbee

.include <bsd.port.pre.mk>

.if defined(WITH_LDAP)
PATCHFILES+=	${PORTNAME}-1.0-ldap.diff
.endif

.if !defined(WITHOUT_MSN)
CONFIGURE_ARGS+=--msn=1
.else
CONFIGURE_ARGS+=--msn=0 --ssl=bogus
.endif

.if defined(WITH_OPENSSL)
CONFIGURE_ARGS+=--ssl=openssl
.else
CONFIGURE_ARGS+=--ssl=gnutls
LIB_DEPENDS+=	gnutls.26:${PORTSDIR}/security/gnutls
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--ldap=${LOCALBASE}
.endif

.if defined(WITH_RECODE)
EXTRA_PATCHES+=	${FILESDIR}/oscar-recode-patch
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--debug=1
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=--ipv6=0
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e "s:/etc/bitlbee/motd.txt:${PREFIX}/etc/bitlbee/motd.txt:" \
		-e "s:/var/lib/bitlbee:/var/db/bitlbee:" \
		${WRKSRC}/bitlbee.conf
	@${REINPLACE_CMD} \
		-e "s:/var/lib/bitlbee:/var/db/bitlbee:" \
		${WRKSRC}/doc/bitlbee.8

pre-install:
	${MKDIR} ${PREFIX}/etc/bitlbee
	${MKDIR} -m 0700 /var/db/bitlbee
	${CHOWN} nobody:nobody /var/db/bitlbee

post-install:
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
