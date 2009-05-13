# New ports collection makefile for:	ircd-ru
# Date Created:				2003.07.11
# Whom:					Khamushkin Ilya <ilya@ircd.ru>
#
# $FreeBSD$
#

PORTNAME=	ircd-ru
PORTVERSION=	1.0.7
PORTREVISION=	4
CATEGORIES=	irc russian
MASTER_SITES=	http://muhnet.org.ru/ \
		ftp://repoman.wenet.ru/pub/ircd-RU/
DISTNAME=	ircd-RU-${PORTVERSION}-03-rc

MAINTAINER=	bu7cher@yandex.ru
COMMENT=	An irc daemon with translation schemes and other useful features

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
SUB_FILES=	pkg-message
USE_RC_SUBR=	ircd

VARDIR=		/var
PLIST_SUB=	VARDIR=${VARDIR}

OPTIONS=	WENET "irc.wenet.ru specific options" off \
		HUB "hub support" off \
		ENCRYPTION "enable RC4 crypt (server to server connection)" off \
		SYSLOGFILE "log to file instead of syslog" off \
		DRONEMODULE "enable dronemodule support" off \
		AUTHMODULE "enable authmodule support" off \
		DNSBL "enable DNSBL support" off \
		SELECT "enable select I/O" off

.include <bsd.port.pre.mk>

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
LIB_DEPENDS+=	gmp.8:${PORTSDIR}/math/libgmp4
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

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -Ee '/(dir_HPATH)|opers.txt/d' ${WRKSRC}/tools/install_ircd.in
.endif

pre-build:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "NOTE:"
	@${ECHO_MSG} " Edit ${WRKSRC}/include/config.h for specific settings "
	@${ECHO_MSG} ""

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${CHOWN} -R ircd:ircd ${VARDIR}/log/ircd-ru
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
