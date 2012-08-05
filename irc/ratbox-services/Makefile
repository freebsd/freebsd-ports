# New ports collection makefile for:	ratbox-services
# Date Created:				2006-01-27
# Whom:					Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$

PORTNAME=	ratbox-services
PORTVERSION=	1.2.3
PORTREVISION=	1
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
USE_GNOME=	pkgconfig
SUB_FILES=	pkg-message pkg-install
PLIST_SUB=	LOGDIR=${LOGDIR} RUNDIR=${RUNDIR} DBDIR=${DBDIR} PERL=${PERL}
SUB_LIST=	LOGDIR=${LOGDIR} RUNDIR=${RUNDIR} DBDIR=${DBDIR} PERL=${PERL}

USE_PERL5_BUILD=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LIB_DEPENDS+=	pcre.1:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=--prefix=${PREFIX}		\
		--sysconfdir=${PREFIX}/etc/	\
		--with-logdir=${LOGDIR}		\
		--with-rundir=${RUNDIR}		\
		--without-sqlitebuild		\
		--enable-pcre=${PREFIX}

PORTDOCS=	operguide.txt userintro.txt whats-new-1.2.txt
MAKE_JOBS_UNSAFE=yes

#-- Options ------------------------------------------------------------

OPTIONS=	NICKSERV	"Enable nickname registration service"		on \
		CHANSERV	"Enable channel registration service"		on \
		USERSERV	"Enable user service"				on \
		OPERSERV	"Enable oper service"				on \
		ALIS		"Enable advanced listing service"		on \
		JUPESERV	"Enable jupe service"				on \
		OPERBOT		"Enable operbot service"			on \
		GLOBALMSG	"Enable global messaging service"		on \
		BANSERV		"Enable ban service"				on \
		WATCHSERV	"Enable command watching service"		on \
		MEMOSERV	"Enable memo services"				on \
		SQLITE		"Enable sqlite3 support (default)"		on \
		MYSQL		"Enable mysql support"				off \
		PGSQL		"Enable pgsql backend support"			off

#----------------------------------------------------------------------

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NICKSERV)
CONFIGURE_ARGS+=	--disable-nickserv
.endif

.if defined(WITHOUT_CHANSERV)
CONFIGURE_ARGS+=	--disable-chanserv
.endif

.if defined(WITHOUT_USERSERV)
CONFIGURE_ARGS+=	--disable-userserv
.endif

.if defined(WITHOUT_OPERSERV)
CONFIGURE_ARGS+=	--disable-operserv
.endif

.if defined(WITHOUT_ALIS)
CONFIGURE_ARGS+=	--disable-alis
.endif

.if defined(WITHOUT_JUPESERV)
CONFIGURE_ARGS+=	--disable-jupeserv
.endif

.if defined(WITHOUT_OPERBOT)
CONFIGURE_ARGS+=	--disable-operbot
.endif

.if defined(WITHOUT_GLOBALMSG)
CONFIGURE_ARGS+=	--disable-global
.endif

.if defined(WITHOUT_BANSERV)
CONFIGURE_ARGS+=	--disable-banserv
.endif

.if defined(WITHOUT_WATCHSERV)
CONFIGURE_ARGS+=	--disable-watchserv
.endif

.if defined(WITHOUT_MEMOSERV)
CONFIGURE_ARGS+=	--disable-memoserv
.endif

.if !defined(WITH_SQLITE) && !defined(WITH_MYSQL) && !defined(WITH_PGSQL)
IGNORE=			requires either an sqlite, mysql or pgsql backend
.endif

.if defined(WITH_SQLITE)
USE_SQLITE=		3
CONFIGURE_ARGS+=	--enable-sqlite3=${LOCALBASE}
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--enable-mysql=${LOCALBASE}
.endif

.if defined(WITH_PGSQL)
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
.if !defined(NOPORTDOCS)
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

.include <bsd.port.post.mk>
