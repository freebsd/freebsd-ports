# Created by: Shaun Amott <shaun@inerd.com>
# $FreeBSD$

PORTNAME=	ircd-ratbox
PORTVERSION=	3.0.7
PORTREVISION=	3
CATEGORIES=	irc ipv6
MASTER_SITES=	http://www.ratbox.org/download/				\
		http://www.ratbox.org/download/old/
PKGNAMESUFFIX=	-devel

MAINTAINER=	moggie@elasticmind.net
COMMENT=	Advanced, stable IRC daemon, used widely on EFnet ('testing' release)

LICENSE=	GPLv2

CONFLICTS=	ircd-ratbox-[0-9]* charybdis-[0-9]*

BROKEN_aarch64=	Fails to link: missing sbrk

USES=		libtool perl5 sqlite tar:bzip2
USE_RC_SUBR=	ircd-ratbox
USE_PERL5=	build
USE_LDCONFIG=	${PREFIX}/lib/ircd-ratbox

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

OPTIONS_DEFINE=	OPENSSL IPV6 ZIPLINKS SHARED_MODULES ASSERT SMALL_NET SERVICES DOCS
OPTIONS_DEFAULT=	OPENSSL ZIPLINKS SHARED_MODULES
ZIPLINKS_DESC=		ziplinks support
SHARED_MODULES_DESC=	shared modules support
ASSERT_DESC=		Enable debugging code
SMALL_NET_DESC=		Tune server for small networks
SERVICES_DESC=		ratbox-services compatibility code

OPENSSL_USES=			ssl
OPENSSL_CONFIGURE_ENABLE=	openssl
OPENSSL_LDFLAGS=		-L${OPENSSLLIB}
OPENSSL_CFLAGS=			-I${OPENSSLINC}
IPV6_CONFIGURE_ENABLE=		ipv6
ZIPLINKS_CONFIGURE_ENABLE=	zlib
SHARED_MODULES_CONFIGURE_ENABLE=shared-modules
ASSERT_CONFIGURE_ENABLE=	assert
SMALL_NET_CONFIGURE_ENABLE=	small-net
SERVICES_CONFIGURE_ENABLE=	services

#-- User Configuration -------------------------------------------------

.if defined(NICKLEN)
CONFIGURE_ARGS+=	--with-nicklen=${NICKLEN}
.endif

#-----------------------------------------------------------------------

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
				${WRKSRC}/doc/example.conf	\
				${WRKSRC}/doc/example.efnet.conf
	@${REINPLACE_CMD} -e "s#%%DBDIR%%#${DBDIR}#g"		\
				${WRKSRC}/doc/example.conf	\
				${WRKSRC}/doc/example.efnet.conf
	@${REINPLACE_CMD} -e "s#%%RUNDIR%%#${RUNDIR}#g" ${WRKSRC}/include/config.h
	@${REINPLACE_CMD} -e "s#%%DBDIR%%#${DBDIR}#g" ${WRKSRC}/include/config.h
	@${REINPLACE_CMD} -e "s#%%WRKSRC%%#${WRKSRC}#g" ${WRKSRC}/contrib/ircd-shortcut.pl

#-- ircd-shortcut.pl ratbox-services commands --------------------------------------

.if defined(SERVER_NAME)
	@${REINPLACE_CMD} -e "s#services.ircd-ratbox.org#${SERVER_NAME}#"       \
	${WRKSRC}/contrib/ircd-shortcut.pl
.endif
.if defined(USER_SERV)
	@${REINPLACE_CMD} -e "s#USERSERV#${USER_SERV}#" \
	${WRKSRC}/contrib/ircd-shortcut.pl
.endif
.if defined(CHAN_SERV)
	@${REINPLACE_CMD} -e "s#CHANSERV#${CHAN_SERV}#" \
	${WRKSRC}/contrib/ircd-shortcut.pl
.endif
.if defined(NICK_SERV)
	@${REINPLACE_CMD} -e "s#NICKSERV#${NICK_SERV}#" \
	${WRKSRC}/contrib/ircd-shortcut.pl
.endif
.if defined(ALIS_SERV)
	@${REINPLACE_CMD} -e "s#ALIS#${ALIS_SERV}#"     \
	${WRKSRC}/contrib/ircd-shortcut.pl
.endif
.if defined(OPER_BOT)
	@${REINPLACE_CMD} -e "s#OPERBOT#${OPER_BOT}#"   \
	${WRKSRC}/contrib/ircd-shortcut.pl
.endif
.if defined(OPER_SERV)
	@${REINPLACE_CMD} -e "s#OPERSERV#${OPER_SERV}#" \
	${WRKSRC}/contrib/ircd-shortcut.pl
.endif
.if defined(JUPE_SERV)
	@${REINPLACE_CMD} -e "s#JUPESERV#${JUPE_SERV}#" \
	${WRKSRC}/contrib/ircd-shortcut.pl
.endif
.if defined(GLOBAL_SERV)
	@${REINPLACE_CMD} -e "s#GLOBAL#${GLOBAL_SERV}#" \
	${WRKSRC}/contrib/ircd-shortcut.pl
.endif

#------ Execute ircd-shortcut perl script to generate the .c file. -----
	@${ECHO_MSG} "Executing ircd-shortcut.pl for ircd-shortcuts generation."
	${PERL} ${WRKSRC}/contrib/ircd-shortcut.pl

post-build:
	@cd ${INSTALL_WRKSRC}/contrib && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS}

# ----- Need to build the m_rsshortcut.so module for ircd-shortcut.pl ----
	@${ECHO_MSG} "Building m_rsshortcut.la for ircd-shortcuts."
	@cd ${INSTALL_WRKSRC}/contrib && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} m_rsshortcut.la

pre-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/help
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/modules

post-install:
	${MKDIR} ${STAGEDIR}${RUNDIR}
	${MKDIR} ${STAGEDIR}${DBDIR}
	${MKDIR} ${STAGEDIR}${LOGDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	@cd ${INSTALL_WRKSRC}/contrib && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}
	${INSTALL_DATA} ${WRKSRC}/doc/ircd.motd ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/ircd.motd.sample
	${INSTALL_DATA} ${WRKSRC}/doc/example.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/ircd.conf.sample
	${INSTALL_DATA} ${WRKSRC}/doc/example.efnet.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/ircd-efnet.conf.sample
	${INSTALL_DATA} ${WRKSRC}/doc/genssl.sh ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/genssl.sh

# ----- We need to install the shortcut.pl module ----
	@${ECHO_MSG} "Executing install-mod.sh for ircd-shortcuts module installation."
	${SH} ${WRKSRC}/install-mod.sh ${WRKSRC}/contrib/m_rsshortcut.la \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}/modules/contrib

.include <bsd.port.mk>
