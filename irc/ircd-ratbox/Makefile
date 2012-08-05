# New ports collection makefile for:	ircd-ratbox
# Date Created:				2006-01-27
# Whom:					Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$
#
# ex: ts=8

PORTNAME=	ircd-ratbox
PORTVERSION=	3.0.7
CATEGORIES=	irc ipv6
MASTER_SITES=	http://www.ratbox.org/download/				\
		http://www.ratbox.org/download/old/

MAINTAINER=	moggie@elasticmind.net
COMMENT=	Advanced, stable IRC daemon, used widely on EFnet

LICENSE=	GPLv2

CONFLICTS=	ircd-ratbox-devel-[0-9]* charybdis-[0-9]*

USE_BZIP2=	yes
#MAN8=		ircd.8
USE_RC_SUBR=	ircd-ratbox
USE_SQLITE=	3
USE_LDCONFIG=	${PREFIX}/lib/ircd-ratbox

USERS=		ircd
GROUPS=		${USERS}

LOGDIR?=	/var/log/${PORTNAME}
RUNDIR?=	/var/run/${PORTNAME}
DBDIR?=		/var/db/${PORTNAME}
SUB_FILES=	pkg-message pkg-install
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

PORTDOCS=	[^i]*.txt README.* technical/[^i]*.txt Tao-of-IRC.*

#-- Options ------------------------------------------------------------

OPTIONS=	OPENSSL		"Enable openssl support"			on  \
		IPV6		"Enable IPv6 support"				on  \
		ZIPLINKS	"Enable ziplinks support"			on  \
		SHARED_MODULES	"Enable shared modules support"			on  \
		ASSERT		"Enable debugging code"				off \
		SMALL_NET	"Tune server for small networks"		off \
		SERVICES	"Enable ratbox-services compatibility code"	off \
		SHORTCUTS	"Build with ircd-shortcut commands"		off

#----------------------------------------------------------------------

.include <bsd.port.pre.mk>

.if defined(WITH_OPENSSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--enable-openssl
.else
CONFIGURE_ARGS+=	--disable-openssl
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(WITHOUT_ZIPLINKS)
CONFIGURE_ARGS+=	--disable-zlib
.endif

.if defined(WITHOUT_SHARED_MODULES)
CONFIGURE_ARGS+=	--disable-shared-modules
.endif

.if defined(WITH_ASSERT)
CONFIGURE_ARGS+=	--enable-assert
.else
CONFIGURE_ARGS+=	--disable-assert
.endif

.if defined(WITH_SMALL_NET)
CONFIGURE_ARGS+=	--enable-small-net
.endif

.if defined(WITH_SERVICES)
CONFIGURE_ARGS+=	--enable-services
PLIST_SUB+=		SERVICES=""
.else
PLIST_SUB+=		SERVICES="@comment "
.endif

.if defined(WITH_SHORTCUTS)
USE_PERL5_BUILD=	yes
PLIST_SUB+=		SHORTCUTS=""
.else
PLIST_SUB+=		SHORTCUTS="@comment "
.endif

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
			${WRKSRC}/doc/example.conf		\
			${WRKSRC}/doc/example.efnet.conf
	@${REINPLACE_CMD} -e "s#%%DBDIR%%#${DBDIR}#g"		\
			${WRKSRC}/doc/example.conf		\
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

# ----- Execute ircd-shortcut perl script to generate the .c file. -----
.if defined(WITH_SHORTCUTS)
	@${ECHO_MSG} "Executing ircd-shortcut.pl for ircd-shortcuts generation."
	${PERL} ${WRKSRC}/contrib/ircd-shortcut.pl
.endif

post-build:
	@cd ${INSTALL_WRKSRC}/contrib && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS}

# ----- Need to build the m_rsshortcut.so module for ircd-shortcut.pl ----
.if defined(WITH_SHORTCUTS)
	@${ECHO_MSG} "Building m_rsshortcut.la for ircd-shortcuts."
	@cd ${INSTALL_WRKSRC}/contrib && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} m_rsshortcut.la
.endif

pre-su-install:
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${MKDIR} ${DATADIR}/help
	${MKDIR} ${PREFIX}/lib/${PORTNAME}/modules

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@cd ${INSTALL_WRKSRC}/contrib && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install
	${INSTALL_DATA} ${WRKSRC}/doc/ircd.motd ${PREFIX}/etc/${PORTNAME}/ircd.motd.sample
	${INSTALL_DATA} ${WRKSRC}/doc/example.conf ${PREFIX}/etc/${PORTNAME}/ircd.conf.sample
	${INSTALL_DATA} ${WRKSRC}/doc/example.efnet.conf ${PREFIX}/etc/${PORTNAME}/ircd-efnet.conf.sample
	${INSTALL_DATA} ${WRKSRC}/doc/genssl.sh ${PREFIX}/etc/${PORTNAME}/genssl.sh

# ----- We need to install the shortcut.pl module ----
.if defined(WITH_SHORTCUTS)
	@${ECHO_MSG} "Executing install-mod.sh for ircd-shortcuts module installation."
	${SH} ${WRKSRC}/install-mod.sh ${WRKSRC}/contrib/m_rsshortcut.la \
		${PREFIX}/lib/${PORTNAME}/modules/contrib
.endif

	@if [ ! -f ${PREFIX}/etc/${PORTNAME}/ircd.conf ]; then \
		${ECHO} "Installing default configuration file."; \
		${CP} -p ${PREFIX}/etc/${PORTNAME}/ircd.conf.sample ${PREFIX}/etc/${PORTNAME}/ircd.conf ; \
	fi

	@if [ ! -f ${PREFIX}/etc/${PORTNAME}/ircd.motd ]; then \
		${ECHO} "Installing default motd file."; \
		${CP} -p ${PREFIX}/etc/${PORTNAME}/ircd.motd.sample ${PREFIX}/etc/${PORTNAME}/ircd.motd ; \
	fi

	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

#-----------------------------------------------------------------------

.include <bsd.port.post.mk>
