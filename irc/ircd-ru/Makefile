# Created by: Khamushkin Ilya <ilya@ircd.ru>
# $FreeBSD$

PORTNAME=	ircd-ru
PORTVERSION=	1.0.7
PORTREVISION=	8
CATEGORIES=	irc russian
MASTER_SITES=	http://m1cro.tk/ports/distfiles/
DISTNAME=	ircd-RU-${PORTVERSION}-03-rc-20090810

MAINTAINER=	rum1cro@yandex.ru
COMMENT=	IRC daemon with translation schemes and other useful features

LICENSE=	GPLv1

USES=		tar:bzip2
GNU_CONFIGURE=	yes
USE_RC_SUBR=	ircd
WRKSRC=		${WRKDIR}/ircd-RU-${PORTVERSION}-03-rc

USERS=		ircd
GROUPS=		${USERS}
SUB_LIST=	USERS=${USERS} GROUPS=${GROUPS}
SUB_FILES=	pkg-install

OPTIONS_DEFINE=	WENET HUB ENCRYPTION SYSLOGFILE DRONEMODULE AUTHMODULE \
				DNSBL SELECT DOCS
WENET_DESC=		irc.wenet.ru specific options
HUB_DESC=		hub support
ENCRYPTION_DESC=	RC4 crypt (server to server connection)
SYSLOGFILE_DESC=	log to file instead of syslog
DRONEMODULE_DESC=	dronemodule support
AUTHMODULE_DESC=	authmodule support
DNSBL_DESC=		DNSBL support
SELECT_DESC=		enable select I/O

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
LIB_DEPENDS+=	libgmp.so:math/gmp
.endif

# log to file instead of syslog
.if ${PORT_OPTIONS:MSYSLOGFILE}
CONFIGURE_ARGS+=--enable-syslogfile
PLIST_SUB+=SYSLOGFILE=""
.else
PLIST_SUB+=SYSLOGFILE="@comment "
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
	@${REINPLACE_CMD} -Ee '/(dir_HPATH)|opers.txt/d' \
		${STAGEDIR}${WRKSRC}/tools/install_ircd.in
.endif
	#FIXME rene DESTDIR support is broken upstream
	@${REINPLACE_CMD} -e 's|-d $$dir_LPATH|-d ${STAGEDIR}$$dir_LPATH|g' \
		-e 's|-d $$dir_FNAME_|-d ${STAGEDIR}$$dir_FNAME_|g' \
		-e 's|-d $$dir_PPATH|-d ${STAGEDIR}$$dir_PPATH|g' \
		-e 's|-d $$dir_EPATH|-d ${STAGEDIR}$$dir_EPATH|g' \
		-e 's|-d $$dir_MCPATH|-d ${STAGEDIR}$$dir_MCPATH|g' \
		-e 's|f $$FNAME_|f ${STAGEDIR}$$FNAME_|g' \
		-e 's|h $$FNAME_|h ${STAGEDIR}$$FNAME_|g' \
		-e 's|STAGE|${STAGEDIR}|g' \
		${WRKSRC}/tools/install_ircd.in

pre-build:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "NOTE:"
	@${ECHO_MSG} " Edit ${WRKSRC}/include/config.h for specific settings "
	@${ECHO_MSG} ""

.include <bsd.port.mk>
