# New ports collection makefile for:	ircd-ru
# Date Created:				2003.07.11
# Whom:					Khamushkin Ilya <ilya@ircd.ru>
#
# $FreeBSD$
#

PORTNAME=	ircd-ru
PORTVERSION=	1.0.7
CATEGORIES=	russian irc
MASTER_SITES=	http://www.ircd.ru/pub/ircd-RU/
DISTNAME=	ircd-RU-${PORTVERSION}-release

MAINTAINER=	ilya@ircd.ru
COMMENT=	An irc daemon with translation schemes and other useful features

USE_BZIP2=	yes
USE_GMAKE=      yes
GNU_CONFIGURE=	yes

PLIST_SUB=	VARDIR=/var

# irc.wenet.ru specific options
.if defined(WITH_WENET)
CONFIGURE_ARGS+=--enable-wenet
CFLAGS+=	 -g
.endif

# enable hub support
.if defined(WITH_HUB)
CONFIGURE_ARGS+=	--enable-hub
.endif

# enable RC4 crypt (server<>server connection)
.if defined(WITH_ENCRYPTION)
CONFIGURE_ARGS+=	--enable-encryption
.endif

# log to file instead of syslog
.if defined(WITH_SYSLOGFILE)
CONFIGURE_ARGS+=	--enable-syslogfile
.endif

# enable dronemodule support
.if defined(WITH_DRONEMODULE)
CONFIGURE_ARGS+=	--enable-dronemodule
.endif

# enable DNSBL support
.if defined(WITH_DNSBL)
CONFIGURE_ARGS+=	--enable-dnsbl
.endif

# enable select I/O
.if defined(WITH_SELECT)
CONFIGURE_ARGS+=	--enable-select
.endif

pre-build:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "NOTE:"
	@${ECHO_MSG} " Edit ${WRKSRC}/include/config.h for specific settings "
	@${ECHO_MSG} ""

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${INSTALL_SCRIPT} -m 555 ${FILESDIR}/ircd.sh ${LOCALBASE}/etc/rc.d
	@${CHOWN} -R ircd:ircd ${LOCALBASE}/etc/ircd-ru
	@${CHOWN} -R ircd:ircd ${LOCALBASE}/share/ircd-ru
	@${CHOWN} -R ircd:ircd ${LOCALBASE}/share/doc/ircd-ru
	@${CHOWN} -R ircd:ircd /var/log/ircd-ru
	@${CHOWN} -R ircd:ircd /var/run/ircd-ru
	@cat ${PKGMESSAGE}

.include <bsd.port.mk>
