# New ports collection makefile for:	ircd-ru
# Date Created:				2003.07.11
# Whom:					Khamushkin Ilya <ilya@ircd.ru>
#
# $FreeBSD$
#

PORTNAME=	ircd-ru
PORTVERSION=	1.0.7
PORTREVISION=	1
CATEGORIES=	irc russian
MASTER_SITES=	ftp://ftp.ircd.ru/pub/ircd-RU/ ftp://ftp.ircd.ru/pub/ircd-RU/old/
DISTNAME=	ircd-RU-${PORTVERSION}-02-stable

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An irc daemon with translation schemes and other useful features

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

PLIST_SUB=	VARDIR=/var

# irc.wenet.ru specific options
.if defined(WITH_WENET)
CONFIGURE_ARGS+=--enable-wenet XFLAGS=-g
.endif

# enable hub support
.if defined(WITH_HUB)
CONFIGURE_ARGS+=--enable-hub
.endif

# enable RC4 crypt (server to server connection)
.if defined(WITH_ENCRYPTION)
CONFIGURE_ARGS+=--enable-encryption
LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4
.endif

# log to file instead of syslog
.if defined(WITH_SYSLOGFILE)
CONFIGURE_ARGS+=--enable-syslogfile
.endif

# enable dronemodule support
.if defined(WITH_DRONEMODULE)
CONFIGURE_ARGS+=--enable-dronemodule
.endif

# enable authmodule support
.if defined(WITH_AUTHMODULE)
CONFIGURE_ARGS+=--enable-authmodule
.endif

# enable DNSBL support
.if defined(WITH_DNSBL)
CONFIGURE_ARGS+=--enable-dnsbl
.endif

# enable select I/O
.if defined(WITH_SELECT)
CONFIGURE_ARGS+=--enable-select
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile with gcc 3.4.2"
.endif

.if ${ARCH} == "amd64"
BROKEN=		"Does not compile on amd64"
.endif

pre-build:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "NOTE:"
	@${ECHO_MSG} " Edit ${WRKSRC}/include/config.h for specific settings "
	@${ECHO_MSG} ""

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${INSTALL_SCRIPT} -m 555 ${FILESDIR}/ircd.sh.sample ${LOCALBASE}/etc/rc.d
	@${CHOWN} -R ircd:ircd ${LOCALBASE}/etc/ircd-ru
	@${CHOWN} -R ircd:ircd ${LOCALBASE}/share/ircd-ru
	@${CHOWN} -R ircd:ircd ${LOCALBASE}/share/doc/ircd-ru
	@${CHOWN} -R ircd:ircd /var/log/ircd-ru
	@${CHOWN} -R ircd:ircd /var/run/ircd-ru
	@cat ${PKGMESSAGE}

.include <bsd.port.post.mk>
