# Created by: Shaun Amott <shaun@inerd.com>
# $FreeBSD$

PORTNAME=	ratbox-services
PORTVERSION=	1.2.3
PORTREVISION=	2
CATEGORIES=	irc
MASTER_SITES=	http://services.ratbox.org/download/		\
		http://services.ratbox.org/download/old/
EXTRACT_SUFX=	.tgz

MAINTAINER=	moggie@elasticmind.net
COMMENT=	A highly configurable services package for use with ircd-ratbox

USE_RC_SUBR=	ratbox-services

USERS=		ircservices
GROUPS=		${USERS}

LOGDIR?=	/var/log
RUNDIR?=	/var/run
DBDIR?=		/var/db/${PORTNAME}
PERL?=		${LOCALBASE}/bin/perl
USES=		pkgconfig perl5
SUB_FILES=	pkg-message pkg-install
PLIST_SUB=	LOGDIR=${LOGDIR} RUNDIR=${RUNDIR} DBDIR=${DBDIR} PERL=${PERL}
SUB_LIST=	LOGDIR=${LOGDIR} RUNDIR=${RUNDIR} DBDIR=${DBDIR} PERL=${PERL}

USE_PERL5=	build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LIB_DEPENDS+=	pcre.3:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=--prefix=${PREFIX}		\
		--sysconfdir=${PREFIX}/etc/	\
		--with-logdir=${LOGDIR}		\
		--with-rundir=${RUNDIR}		\
		--without-sqlitebuild		\
		--enable-pcre=${PREFIX}

PORTDOCS=	operguide.txt userintro.txt whats-new-1.2.txt
MAKE_JOBS_UNSAFE=yes

#-- Options ------------------------------------------------------------

OPTIONS_DEFINE=	NICKSERV CHANSERV USERSERV OPERSERV ALIS JUPESERV OPERBOT GLOBALMSG \
		BANSERV WATCHSERV MEMOSERV
OPTIONS_DEFAULT=	NICKSERV CHANSERV USERSERV OPERSERV ALIS JUPESERV OPERBOT GLOBALMSG \
			BANSERV WATCHSERV MEMOSERV SQLITE
OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE
NICKSERV_DESC=	nickname registration service
CHANSERV_DESC=	channel registration service
USERSERV_DESC=	user service
OPERSERV_DESC=	oper service
ALIS_DESC=	advanced listing service
JUPESERV_DESC=	jupe service
OPERBOT_DESC=	operbot service
GLOBALMSG_DESC=	global messaging service
BANSERV_DESC=	ban service
WATCHSERV_DESC=	command watching service
MEMOSERV_DESC=	memo services

#----------------------------------------------------------------------

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MNICKSERV}
CONFIGURE_ARGS+=	--disable-nickserv
.endif

.if ! ${PORT_OPTIONS:MCHANSERV}
CONFIGURE_ARGS+=	--disable-chanserv
.endif

.if ! ${PORT_OPTIONS:MUSERSERV}
CONFIGURE_ARGS+=	--disable-userserv
.endif

.if ! ${PORT_OPTIONS:MOPERSERV}
CONFIGURE_ARGS+=	--disable-operserv
.endif

.if ! ${PORT_OPTIONS:MALIS}
CONFIGURE_ARGS+=	--disable-alis
.endif

.if ! ${PORT_OPTIONS:MJUPESERV}
CONFIGURE_ARGS+=	--disable-jupeserv
.endif

.if ! ${PORT_OPTIONS:MOPERBOT}
CONFIGURE_ARGS+=	--disable-operbot
.endif

.if ! ${PORT_OPTIONS:MGLOBALMSG}
CONFIGURE_ARGS+=	--disable-global
.endif

.if ! ${PORT_OPTIONS:MBANSERV}
CONFIGURE_ARGS+=	--disable-banserv
.endif

.if ! ${PORT_OPTIONS:MWATCHSERV}
CONFIGURE_ARGS+=	--disable-watchserv
.endif

.if ! ${PORT_OPTIONS:MMEMOSERV}
CONFIGURE_ARGS+=	--disable-memoserv
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=		3
CONFIGURE_ARGS+=	--enable-sqlite3=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--enable-mysql=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--enable-pgsql=${LOCALBASE}
.endif

#-- User Configuration -------------------------------------------------

.if defined(NICKLEN)
CONFIGURE_ARGS+=	--with-nicklen=${NICKLEN}
.endif

.if defined(TOPICLEN)
CONFIGURE_ARGS+=	--with-topiclen=${TOPICLEN}
.endif

.if defined(USERREGLEN)
CONFIGURE_ARGS+=	--with-userreglen=${USERREGLEN}
.endif

#-----------------------------------------------------------------------

pre-configure:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "This port has additional options:"
	@${ECHO_MSG} "    NICKLEN     [default 9, max 50]    - Max nick length on server"
	@${ECHO_MSG} "    TOPICLEN    [default 160, max 390] - Max topic length"
	@${ECHO_MSG} "    USERREGLEN  [default 10]           - Max registered username"
	@${ECHO_MSG} "                                         length on services"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "THESE SHOULD BE CONSISTENT WITH YOUR IRCD-RATBOX SERVER/NETWORK!"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Press CTRL+C now if you wish to set them."
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e "s#-O[02]##g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -E -e "s|(LIBS=.*)-lsqlite3(.*)|\1\`pkg-config --static --libs sqlite3\`\2|" \
		-e "s|(.*DB_LIBS=.*)-lsqlite3(.*)|\1\`pkg-config --static --libs sqlite3\`\2|" \
		${WRKSRC}/configure

	@${REINPLACE_CMD} -e "s#%%DBDIR%%#${DBDIR}#g" ${WRKSRC}/include/config.h
	@${REINPLACE_CMD} -e "s#%%PREFIX%%#${PREFIX}#g"		\
			${WRKSRC}/tools/generate-schema.pl	\
			${WRKSRC}/tools/dbupgrade.pl

pre-su-install:
	${MKDIR} ${DATADIR}/help

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL.mysql ${DOCSDIR}/INSTALL.mysql
	${INSTALL_DATA} ${WRKSRC}/INSTALL.pgsql ${DOCSDIR}/INSTALL.pgsql
	${INSTALL_DATA} ${WRKSRC}/INSTALL.sqlite ${DOCSDIR}/INSTALL.sqlite
	${INSTALL_DATA} ${WRKSRC}/UPGRADING ${DOCSDIR}/UPGRADING
	${INSTALL_DATA} ${WRKSRC}/DBMOVE ${DOCSDIR}/DBMOVE
.endif

	${MKDIR} ${DATADIR}
		(cd ${WRKSRC}/tools/ &&	\
		${COPYTREE_SHARE} \* ${DATADIR} "! -name dbupgrade.pl.bak	\
						! -name dbupgrade.pl.orig	\
						! -name generate-schema.pl.bak	\
						! -name generate-schema.pl.orig")

	${INSTALL_PROGRAM} ${WRKSRC}/src/ratbox-services ${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/doc/example.conf ${PREFIX}/etc/ratbox-services.conf.sample

	@if [ ! -f ${PREFIX}/etc/ratbox-services.conf ]; then \
		${ECHO} "Installing default configuration file."; \
		${CP} -p ${PREFIX}/etc/ratbox-services.conf.sample ${PREFIX}/etc/ratbox-services.conf ; \
	fi

	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

#-----------------------------------------------------------------------

.include <bsd.port.mk>
