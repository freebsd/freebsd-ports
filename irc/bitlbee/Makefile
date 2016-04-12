# $FreeBSD$

PORTNAME=	bitlbee
PORTVERSION=	3.4.2
CATEGORIES=	irc
MASTER_SITES=	http://get.bitlbee.org/src/ \
		LOCAL/brix

MAINTAINER=	garga@FreeBSD.org
COMMENT=	IRC to other chat networks gateway

LICENSE=	GPLv2

BUILD_DEPENDS=	xmlto:textproc/xmlto \
		xsltproc:textproc/libxslt

SUB_FILES=	pkg-message
PORTDOCS=	AUTHORS CHANGES CREDITS FAQ README
PORTEXAMPLES=	bitlbee.conf motd.txt

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig python:build
USE_RC_SUBR=	bitlbee
USE_GNOME=	glib20
OPTIONS_SUB=	yes

OPTIONS_DEFINE=		DEBUG DOCS EXAMPLES OTR

OPTIONS_SINGLE=		EVENTS SSL
OPTIONS_SINGLE_EVENTS=	GLIB LIBEVENT
OPTIONS_SINGLE_SSL=	OPENSSL GNUTLS NSS

OPTIONS_MULTI=		PROTO
OPTIONS_MULTI_PROTO=	JABBER LIBPURPLE MSN OSCAR SKYPE TWITTER YAHOO

OTR_DESC=		Off-the-Record Messaging support
LIBPURPLE_DESC=		Use libpurple for protocol support
MSN_DESC=		Microsoft Messenger support
OSCAR_DESC=		OSCAR (ICQ, AIM) support
SKYPE_DESC=		Skype support
TWITTER_DESC=		Twitter support
YAHOO_DESC=		Yahoo! Messenger support
GLIB_DESC=		Use glib as event handler
LIBEVENT_DESC=		Use libevent as event handler

OPTIONS_DEFAULT=	GLIB GNUTLS JABBER OSCAR OTR TWITTER YAHOO

CONFIGURE_ARGS=		--config=/var/db/bitlbee \
			--pcdir=${PREFIX}/libdata/pkgconfig

DEBUG_CONFIGURE_ON=	--debug=1
GNUTLS_CONFIGURE_ON=	--ssl=gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls \
			libgcrypt.so:security/libgcrypt
JABBER_CONFIGURE_OFF=	--jabber=0
LIBEVENT_CONFIGURE_ON=	--events=libevent --libevent=${LOCALBASE}
LIBEVENT_LIB_DEPENDS=	libevent.so:devel/libevent2
LIBPURPLE_CONFIGURE_ON=	--purple=1
LIBPURPLE_LIB_DEPENDS=	libpurple.so:net-im/libpurple
MSN_CONFIGURE_OFF=	--msn=0
NSS_CONFIGURE_ON=	--ssl=nss
NSS_LIB_DEPENDS=	libnss3.so:security/nss
OPENSSL_CONFIGURE_ON=	--ssl=openssl
OSCAR_CONFIGURE_OFF=	--oscar=0
OTR_CONFIGURE_ON=	--otr=1
OTR_LIB_DEPENDS=	libotr.so.5:security/libotr
SKYPE_CONFIGURE_ON=	--skype=1
SKYPE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Skype4Py>0:net-im/py-skype4py
SKYPE_USES=		python
TWITTER_CONFIGURE_OFF=	--twitter=0
YAHOO_CONFIGURE_OFF=	--yahoo=0

USERS=		bitlbee
GROUPS=		bitlbee

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^install:/ s/$$/ install-dev/' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|^\(EFLAGS=.*\)|\1 ${LDFLAGS}|" \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s:/etc/bitlbee/motd.txt:${ETCDIR}/motd.txt:" \
		-e "s:/var/lib/bitlbee:/var/db/bitlbee:" \
		${WRKSRC}/bitlbee.conf
	@${REINPLACE_CMD} -e "s:/var/lib/bitlbee:/var/db/bitlbee:" \
		${WRKSRC}/doc/bitlbee.8

post-install:
.if ${PORT_OPTIONS:MSKYPE}
	${MV} ${STAGEDIR}${PREFIX}/etc/skyped/skyped.conf \
		${STAGEDIR}${PREFIX}/etc/skyped/skyped.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/skyped/skyped.cnf \
		${STAGEDIR}${PREFIX}/etc/skyped/skyped.cnf.sample
.endif
	${MKDIR} ${STAGEDIR}${ETCDIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/doc/@} ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S@^@${WRKSRC}/@} ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
