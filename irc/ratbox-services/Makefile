# New ports collection makefile for:	ratbox-services
# Date Created:				2006-01-27
# Whom:					Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$

PORTNAME=	ratbox-services
PORTVERSION=	1.1.2
PORTREVISION=	2
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.ircd-ratbox.org/pub/ircd-ratbox/${PORTNAME}/	\
		ftp://ftp.demon.co.uk/pub/mirrors/ircd-ratbox/${PORTNAME}/ \
		http://services.ircd-ratbox.org/download/		\
		ftp://ftp.parodius.com/pub/ircd-ratbox/${PORTNAME}/	\
		http://services.ircd-ratbox.org/download/old/
EXTRACT_SUFX=	.tgz

PATCH_SITES=	http://www.elasticmind.net/freebsd/ports/distfiles/	\
		http://jsreedinc.com/freebsd/ports/patches/		\
		http://www.atarininja.org/~wxs/distfiles/
PATCHFILES=	patch-autoconf_configure.in.gz patch-configure.gz	\
		patch-include_setup.h.in.gz

MAINTAINER=	moggie@elasticmind.net
COMMENT=	A highly configurable services package for use with ircd-ratbox

USE_RC_SUBR=	ratbox-services.sh

LOGDIR?=	/var/log
RUNDIR?=	/var/run
DBDIR?=		/var/db/${PORTNAME}
PERL?=		${LOCALBASE}/bin/perl
USE_GNOME=	pkgconfig
SUB_FILES=	pkg-message pkg-install
PLIST_SUB=	LOGDIR=${LOGDIR} RUNDIR=${RUNDIR} DBDIR=${DBDIR} PERL=${PERL}
SUB_LIST=	LOGDIR=${LOGDIR} RUNDIR=${RUNDIR} DBDIR=${DBDIR} PERL=${PERL}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX}		\
		--sysconfdir=${PREFIX}/etc/	\
		--with-logdir=${LOGDIR}		\
		--with-rundir=${RUNDIR}		\
		--with-helpdir=${DATADIR}/help	\
		--without-sqlitebuild

PORTDOCS=	operguide.txt

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
		SQLITE		"Enable sqlite3 support (default)"		on \
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

.if !defined(WITH_SQLITE) && !defined(WITH_PGSQL)
IGNORE=			requires either an sqlite or pgsql backend
.endif

.if defined(WITH_SQLITE)
USE_SQLITE=		3
CONFIGURE_ARGS+=	--enable-sqlite3=${LOCALBASE}
.endif

# This ratbox-services version has known problems when integrating
# with MySQL and should be avoided until it is fixed in version 1.1.3
#.if defined(WITH_MYSQL)
#USE_MYSQL=		yes
#CONFIGURE_ARGS+=	--enable-mysql=${LOCALBASE}
#.endif

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
	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	${MKDIR} ${DATADIR}/help

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/src/ratbox-services ${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/doc/example.conf ${PREFIX}/etc/ratbox-services.conf.sample
	${MKDIR} ${DATADIR}
		(cd ${WRKSRC}/tools/ &&	\
		${COPYTREE_SHARE} \* ${DATADIR} "! -name dbupgrade.pl.bak	\
						! -name dbupgrade.pl.orig	\
						! -name generate-schema.pl.bak	\
						! -name generate-schema.pl.orig")
	${INSTALL_DATA} ${WRKSRC}/INSTALL.mysql ${DOCSDIR}/INSTALL.mysql
	${INSTALL_DATA} ${WRKSRC}/INSTALL.pgsql ${DOCSDIR}/INSTALL.pgsql
	${INSTALL_DATA} ${WRKSRC}/INSTALL.sqlite ${DOCSDIR}/INSTALL.sqlite
	${INSTALL_DATA} ${WRKSRC}/UPGRADING ${DOCSDIR}/UPGRADING
	${INSTALL_DATA} ${WRKSRC}/DBMOVE ${DOCSDIR}/DBMOVE

	@if [ ! -f ${PREFIX}/etc/ratbox-services.conf ]; then \
		${ECHO} "Installing default configuration file."; \
		${CP} -p ${PREFIX}/etc/ratbox-services.conf.sample ${PREFIX}/etc/ratbox-services.conf ; \
	fi

	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

#-----------------------------------------------------------------------

.include <bsd.port.post.mk>
