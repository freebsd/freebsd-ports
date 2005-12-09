# New ports collection makefile for:   	bitlbee
# Date created:                        	10 June 2003
# Whom:                                 Peter van Dijk <peter@dataloss.nl>
#
# $FreeBSD$
#

PORTNAME=	bitlbee
PORTVERSION=	1.0
CATEGORIES=	irc
MASTER_SITES=	http://get.bitlbee.org/src/:bitlbee \
		http://www.bitlbee.be/andy/:msn6
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:bitlbee
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	http://get.bitlbee.org/patches/

MAINTAINER=	peter@dataloss.nl
COMMENT=	An IRC to other chat networks gateway

.if defined(WITH_MSN) && defined(WITH_MSN6_FEATURES)
# don't use DISTNAME as old patch applies fine to new release
DISTFILES+=	${PORTNAME}-0.92-msn6.akke.patch:msn6
.endif

.if defined(WITH_LDAP)
PATCHFILES+=	${DISTNAME}-ldap.diff
.endif

MAN5=		bitlbee.conf.5
MAN8=		bitlbee.8

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20
USE_GETOPT_LONG=yes
PKGMESSAGE=	${WRKDIR}/pkg-message

CONFIGURE_ARGS=	--mandir=${PREFIX}/man --config=${PREFIX}/etc/bitlbee

.if defined(WITH_MSN)
LIB_DEPENDS+=	gnutls.12:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=--msn=1
.else
CONFIGURE_ARGS+=--msn=0 --ssl=bogus
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--ldap=${LOCALBASE}
.endif

pre-configure:
.if !defined(WITH_MSN)
	@${ECHO_CMD} "Type \"make -DWITH_MSN\" if you want to enable MSN and Jabber/SSL support."
.else
	@${ECHO_CMD} "MSN and Jabber/SSL support will be enabled."

. if !defined(WITH_MSN6_FEATURES)
	@${ECHO_CMD} "Type \"make -DWITH_MSN6_FEATURES\" if you want to enable MSN 6 features, like buddy icons"
. else
	@${ECHO_CMD} "MSN 6 features will be enabled."
. endif
.endif

.if !defined(WITH_LDAP)
	@${ECHO_CMD} "Type \"make -DWITH_LDAP\" if you want to enable LDAP authentication."
.else
	@${ECHO_CMD} "LDAP authentication will be enabled."
.endif

post-patch:
.if defined(WITH_MSN) && defined(WITH_MSN6_FEATURES)
	@${PATCH} ${PATCH_ARGS} -p1 < ${DISTDIR}/${PORTNAME}-0.92-msn6.akke.patch
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
