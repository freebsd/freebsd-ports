# New ports collection makefile for:   	bitlbee
# Date created:                        	10 June 2003
# Whom:                                 Peter van Dijk <peter@dataloss.nl>
#
# $FreeBSD$
#

PORTNAME=	bitlbee
PORTVERSION=	0.92
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://get.bitlbee.org/src/

MAINTAINER=	peter@dataloss.nl
COMMENT=	An IRC to other chat networks gateway

MAN5=		bitlbee.conf.5
MAN8=		bitlbee.8

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${PREFIX}/man --config=${PREFIX}/etc/bitlbee
USE_GMAKE=	yes
USE_GNOME=	glib20
USE_GETOPT_LONG=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

.if defined(WITH_MSN)
LIB_DEPENDS+=	gnutls.12:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--msn=1
pre-configure:
	@${ECHO_CMD} "MSN and Jabber/SSL support will be enabled."
.else
CONFIGURE_ARGS+=	--msn=0 --ssl=bogus
pre-configure:
	@${ECHO_CMD} "Type \"make -DWITH_MSN\" if you want to enable MSN and Jabber/SSL support."
.endif

.if defined(WITH_FLOOD)
CONFIGURE_ARGS+=	--flood=1
.else
	@${ECHO_CMD} "Type \"make -DWITH_FLOOD\" if you want to enable flood protection."
.endif

post-build:
	@${CAT} pkg-message | ${SED} -e 's|%%PREFIX%%|${PREFIX}|' > ${PKGMESSAGE}

pre-install:
	@${MKDIR} -m 700 ${PREFIX}/etc/bitlbee

post-install:
	@${CP} ${WRKSRC}/bitlbee.conf ${PREFIX}/etc/bitlbee/bitlbee.conf.orig
	@${CP} ${WRKSRC}/motd.txt ${PREFIX}/etc/bitlbee/motd.txt.orig
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
