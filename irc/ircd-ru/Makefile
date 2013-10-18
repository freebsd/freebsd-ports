# Created by: Khamushkin Ilya <ilya@ircd.ru>
# $FreeBSD$

PORTNAME=	ircd-ru
PORTVERSION=	1.0.7
PORTREVISION=	6
CATEGORIES=	irc russian
MASTER_SITES=	http://link.wenet.su/
DISTNAME=	ircd-RU-${PORTVERSION}-03-rc-20090810

MAINTAINER=	rum1cro@yandex.ru
COMMENT=	An irc daemon with translation schemes and other useful features

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
SUB_FILES=	pkg-message
USE_RC_SUBR=	ircd
WRKSRC=		${WRKDIR}/ircd-RU-${PORTVERSION}-03-rc

USERS=		ircd
GROUPS=		${USERS}

VARDIR=		/var
PLIST_SUB=	VARDIR=${VARDIR}

OPTIONS_DEFINE=	WENET HUB ENCRYPTION SYSLOGFILE DRONEMODULE AUTHMODULE DNSBL SELECT DOCS
WENET_DESC=		irc.wenet.ru specific options
HUB_DESC=		hub support
ENCRYPTION_DESC=	RC4 crypt (server to server connection)
SYSLOGFILE_DESC=	log to file instead of syslog
DRONEMODULE_DESC=	dronemodule support
AUTHMODULE_DESC=	authmodule support
DNSBL_DESC=		DNSBL support
SELECT_DESC=		enable select I/O

NO_STAGE=	yes
.include <bsd.port.options.mk>

# irc.wenet.ru specific options
.if ${PORT_OPTIONS:MWENET}
CONFIGURE_ARGS+=--enable-wenet XFLAGS=-g
.endif

# enable hub support
.if ${PORT_OPTIONS:MHUB}
CONFIGURE_ARGS+=--enable-hub
.endif

# enable RC4 crypt (server to server connection)
.if ${PORT_OPTIONS:MENCRYPTION}
CONFIGURE_ARGS+=--enable-encryption
LIB_DEPENDS+=	gmp.10:${PORTSDIR}/math/gmp
.endif

# log to file instead of syslog
.if ${PORT_OPTIONS:MSYSLOGFILE}
CONFIGURE_ARGS+=--enable-syslogfile
.endif

# enable dronemodule support
.if ${PORT_OPTIONS:MDRONEMODULE}
CONFIGURE_ARGS+=--enable-dronemodule
.endif

# enable authmodule support
.if ${PORT_OPTIONS:MAUTHMODULE}
CONFIGURE_ARGS+=--enable-authmodule
.endif

# enable DNSBL support
.if ${PORT_OPTIONS:MDNSBL}
CONFIGURE_ARGS+=--enable-dnsbl
.endif

# enable select I/O
.if ${PORT_OPTIONS:MSELECT}
CONFIGURE_ARGS+=--enable-select
.endif

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -Ee '/(dir_HPATH)|opers.txt/d' ${WRKSRC}/tools/install_ircd.in
.endif

pre-build:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "NOTE:"
	@${ECHO_MSG} " Edit ${WRKSRC}/include/config.h for specific settings "
	@${ECHO_MSG} ""

post-install:
	@${CHOWN} -R ircd:ircd ${VARDIR}/log/ircd-ru
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
