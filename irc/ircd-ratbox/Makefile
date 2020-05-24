# Created by: Shaun Amott <shaun@inerd.com>
# $FreeBSD$

PORTNAME=	ircd-ratbox
PORTVERSION=	3.0.10
PORTREVISION=	7
CATEGORIES=	irc
MASTER_SITES=	http://www.ratbox.org/download/				\
		http://www.ratbox.org/download/old/

MAINTAINER=	moggie@elasticmind.net
COMMENT=	Advanced, stable IRC daemon, used widely on EFnet

LICENSE=	GPLv2

CONFLICTS=	ircd-ratbox-devel-[0-9]* charybdis-[0-9]*

USES=		cpe libtool sqlite tar:bzip2
CPE_VENDOR=	ratbox
USE_RC_SUBR=	ircd-ratbox
USE_LDCONFIG=	${PREFIX}/lib/ircd-ratbox

MAKE_JOBS_UNSAFE=	yes

USERS=		ircd
GROUPS=		${USERS}

LOGDIR?=	/var/log/${PORTNAME}
RUNDIR?=	/var/run/${PORTNAME}
DBDIR?=		/var/db/${PORTNAME}
SUB_FILES=	pkg-message
PLIST_SUB=	LOGDIR=${LOGDIR} RUNDIR=${RUNDIR} DBDIR=${DBDIR}
SUB_LIST=	LOGDIR=${LOGDIR} RUNDIR=${RUNDIR} DBDIR=${DBDIR}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-confdir=${PREFIX}/etc/${PORTNAME}		\
		--with-logdir=/var/log/${PORTNAME}			\
		--with-moduledir=${PREFIX}/lib/${PORTNAME}/modules	\
		--libexecdir=${PREFIX}/libexec				\
		--with-helpdir=${DATADIR}/help				\
		--libdir=${PREFIX}/lib/${PORTNAME}			\
		--with-sqlite3=${LOCALBASE}				\
		--disable-backups
INSTALL_TARGET=	install-strip

PORTDOCS=	[^i]*.txt README.* technical/[^i]*.txt Tao-of-IRC.*

#-- Options ------------------------------------------------------------

OPTIONS_DEFINE=		OPENSSL IPV6 ZIPLINKS SHARED_MODS ASSERT SMALL_NET	\
			SERVICES SHORTCUTS DOCS
ZIPLINKS_DESC=		Support compressed server links
SHARED_MODS_DESC=	Support shared modules
ASSERT_DESC=		Enable debugging code
SMALL_NET_DESC=		Tune server internals for small networks
SERVICES_DESC=		Enable ratbox-services compatibility code
SHORTCUTS_DESC=		Build with ircd-shortcut commands

OPTIONS_DEFAULT=	OPENSSL ZIPLINKS SHARED_MODS
OPTIONS_EXCLUDE=	NLS EXAMPLES

OPTIONS_SUB=		yes

ASSERT_CONFIGURE_ENABLE=	assert
IPV6_CONFIGURE_ENABLE=		ipv6
OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_ON=	--enable-openssl=${OPENSSLBASE}
OPENSSL_CONFIGURE_OFF=	--disable-openssl
SERVICES_CONFIGURE_ENABLE=	services
SHARED_MODS_CONFIGURE_ON=	--disable-static
SHARED_MODS_CONFIGURE_OFF=	--enable-static
SHORTCUTS_USES=		perl5
SHORTCUTS_USE=		perl5=build
SMALL_NET_CONFIGURE_ENABLE=	small-net
ZIPLINKS_CONFIGURE_ENABLE=	zlib

#-- User Configuration -------------------------------------------------

.if !empty(NICKLEN)
CONFIGURE_ARGS+=	--with-nicklen=${NICKLEN}
.endif

#-----------------------------------------------------------------------
.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
USE_GCC=	yes
.endif

post-patch:
.if !defined(WITH_DEBUG)
	${REINPLACE_CMD} 's|@INSTALL@|@INSTALL@ -s|' ${WRKSRC}/install-mod.sh.in
.endif

pre-configure:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "This port has additional options:"
	@${ECHO_MSG} "    NICKLEN     [default 9, max 50]    - Max nick length on server"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "    SERVER_NAME [default 'services.ircd-ratbox.org'] - Name of services"
	@${ECHO_MSG} "    USER_SERV   [default 'USERSERV'] - Name of user registration service"
	@${ECHO_MSG} "    CHAN_SERV   [default 'CHANSERV'] - Name of channel registration serv'"
	@${ECHO_MSG} "    NICK_SERV   [default 'NICKSERV'] - Name of nickname registration serv'"
	@${ECHO_MSG} "    ALIS_SERV   [default 'ALIS'] - Name of channel list service"
	@${ECHO_MSG} "    OPER_BOT    [default 'OPERBOT'] - Name of operbot service"
	@${ECHO_MSG} "    OPER_SERV   [default 'OPERSERV'] - Name of oper command service"
	@${ECHO_MSG} "    JUPE_SERV   [default 'JUPESERV'] - Name of jupe service"
	@${ECHO_MSG} "    GLOBAL_SERV [default 'GLOBAL'] - Name of global announce service"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Press CTRL+C now if you wish to set them."
	@${ECHO_MSG} ""

pre-build:
	@${REINPLACE_CMD} -e "s#-O2##" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s#%%PREFIX%%#${PREFIX}#g"		\
			${WRKSRC}/doc/example.conf		\
			${WRKSRC}/doc/example.efnet.conf
	@${REINPLACE_CMD} -e "s#%%LOGDIR%%#${LOGDIR}#g"		\
			${WRKSRC}/doc/example.conf		\
			${WRKSRC}/doc/example.efnet.conf
	@${REINPLACE_CMD} -e "s#%%DBDIR%%#${DBDIR}#g"		\
			${WRKSRC}/doc/example.conf		\
			${WRKSRC}/doc/example.efnet.conf
	@${REINPLACE_CMD} -e "s#%%RUNDIR%%#${RUNDIR}#g" ${WRKSRC}/include/config.h
	@${REINPLACE_CMD} -e "s#%%DBDIR%%#${DBDIR}#g" ${WRKSRC}/include/config.h
#-- ircd-shortcut.pl ratbox-services commands --------------------------------------
	@${REINPLACE_CMD} -e "s#ALIS#${ALIS_SERV:UALIS}#" \
		-e "s#CHANSERV#${CHAN_SERV:UCHANSERV}#" -e "s#GLOBAL#${GLOBAL_SERV:UGLOBAL}#" \
		-e "s#JUPESERV#${JUPE_SERV:UJUPESERV}#" -e "s#NICKSERV#${NICK_SERV:UNICKSERV}#" \
		-e "s#OPERBOT#${OPER_BOT:UOPERBOT}#" -e "s#USERSERV#${USER_SERV:UUSERSERV}#" \
		-e "s#services.ircd-ratbox.org#${SERVER_NAME:Uservices.ircd-ratbox.org}#" \
		-e "s#%%WRKSRC%%#${WRKSRC}#g" ${WRKSRC}/contrib/ircd-shortcut.pl

# ----- Execute ircd-shortcut perl script to generate the .c file. -----

.if ${PORT_OPTIONS:MSHORTCUTS}
	@${ECHO_MSG} "Executing ircd-shortcut.pl for ircd-shortcuts generation."
	${PERL} ${WRKSRC}/contrib/ircd-shortcut.pl
.endif

post-build:
	@cd ${INSTALL_WRKSRC}/contrib && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS}

# ----- Need to build the m_rsshortcut.so module for ircd-shortcut.pl ----
.if ${PORT_OPTIONS:MSHORTCUTS}
	@${ECHO_MSG} "Building m_rsshortcut.la for ircd-shortcuts."
	@cd ${INSTALL_WRKSRC}/contrib && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} m_rsshortcut.la
.endif

pre-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/help
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/modules

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${RUNDIR}
	${MKDIR} ${STAGEDIR}${DBDIR}
	${MKDIR} ${STAGEDIR}${LOGDIR}

	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	cd ${INSTALL_WRKSRC}/contrib && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}
	${INSTALL_DATA} ${WRKSRC}/doc/ircd.motd ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/ircd.motd.sample
	${INSTALL_DATA} ${WRKSRC}/doc/example.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/ircd.conf.sample
	${INSTALL_DATA} ${WRKSRC}/doc/example.efnet.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/ircd-efnet.conf.sample
	${INSTALL_DATA} ${WRKSRC}/doc/genssl.sh ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/genssl.sh
.if !defined(WITH_DEBUG)
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ircd-ratbox/libcore.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ircd-ratbox/libratbox.so
.endif

# ----- We need to install the shortcut.pl module ----
.if ${PORT_OPTIONS:MSHORTCUTS}
	@${ECHO_MSG} "Executing install-mod.sh for ircd-shortcuts module installation."
	${SH} ${WRKSRC}/install-mod.sh ${WRKSRC}/contrib/m_rsshortcut.la \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}/modules/contrib
.endif

.include <bsd.port.mk>
