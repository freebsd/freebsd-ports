# New ports collection makefile for:   	bitlbee
# Date created:                        	10 June 2003
# Whom:                                 Peter van Dijk <peter@dataloss.nl>
#
# $FreeBSD$
#

PORTNAME=	bitlbee
PORTVERSION=	0.82
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://get.bitlbee.org/src/

MAINTAINER=	peter@dataloss.nl
COMMENT=	An IRC to other chat networks gateway

MAN8=		bitlbee.8

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --prefix=${PREFIX} --mandir=${PREFIX}/man --config=${PREFIX}/etc/bitlbee
USE_GMAKE=	yes
USE_GNOME=	glib20
PKGMESSAGE=	${WRKDIR}/pkg-message

.if defined(WITH_MSN)
LIB_DEPENDS=	soup-2.0.0:${PORTSDIR}/devel/libsoup
pre-configure:
	@${ECHO_CMD} "MSN support will be enabled."
.else
pre-configure:
	@${ECHO_CMD} "Type \"make -DWITH_MSN\" if you want enable MSN support."
.endif

post-build:
	@${CAT} pkg-message | ${SED} -e 's|%%PREFIX%%|${PREFIX}|' > ${PKGMESSAGE}

pre-install:
	@mkdir -p -m 700 ${PREFIX}/etc/bitlbee

post-install:
	@cp ${WRKSRC}/bitlbee.conf ${PREFIX}/etc/bitlbee/bitlbee.conf.orig
	@cp ${WRKSRC}/motd.txt ${PREFIX}/etc/bitlbee/motd.txt.orig
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
