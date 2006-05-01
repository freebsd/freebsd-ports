# New ports collection makefile for:	ratbox-services
# Date Created:				2006-01-27
# Whom:					Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$

PORTNAME=	ratbox-services
PORTVERSION=	1.0.3
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.ircd-ratbox.org/pub/ircd-ratbox/${PORTNAME}/		\
		ftp://ftp.demon.co.uk/pub/mirrors/ircd-ratbox/${PORTNAME}/	\
		http://services.ircd-ratbox.org/download/			\
		ftp://ftp.parodius.com/pub/ircd-ratbox/${PORTNAME}/		\
		http://mirror.inerd.com/FreeBSD/distfiles/${PORTNAME}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	shaun@inerd.com
COMMENT=	A highly configurable services package for use with ircd-ratbox

USE_RC_SUBR=	ratbox-services.sh

LOGDIR?=	/var/log
RUNDIR?=	/var/run
DBDIR?=		/var/db/${PORTNAME}
SUB_FILES=	pkg-message pkg-install
PLIST_SUB=	LOGDIR=${LOGDIR} RUNDIR=${RUNDIR} DBDIR=${DBDIR}
SUB_LIST=	LOGDIR=${LOGDIR} RUNDIR=${RUNDIR} DBDIR=${DBDIR}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/etc/	\
		--with-logdir=${LOGDIR}		\
		--with-rundir=${RUNDIR}		\
		--with-helpdir=${DATADIR}/help	\
		--with-sqlite=${LOCALBASE}	\
		--without-sqlitebuild

USE_SQLITE=	2

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
		BANSERV		"Enable ban service"				on

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

#-- User Configuration -------------------------------------------------

.if defined(NICKLEN)
CONFIGURE_ARGS+=	--with-nicklen=${NICKLEN}
.endif

.if defined(TOPICLEN)
CONFIGURE_ARGS+=	--with-topiclen=${TOPICLEN}
.endif

#-----------------------------------------------------------------------

pre-configure:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "This port has additional options:"
	@${ECHO_MSG} "    NICKLEN     [default 9, max 50]    - Max nick length on server"
	@${ECHO_MSG} "    TOPICLEN    [default 160, max 390] - Max topic length"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "THESE SHOULD BE CONSISTENT WITH YOUR IRCD-RATBOX SERVER/NETWORK!"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Press CTRL+C now if you wish to set them."
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e "s#-O[02]##g" ${WRKSRC}/configure

	@${REINPLACE_CMD} -e "s#%%DBDIR%%#${DBDIR}#g" ${WRKSRC}/include/config.h

pre-su-install:
	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	${MKDIR}  ${DATADIR}/help

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/src/ratbox-services ${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${WRKSRC}/tools/ircd-shortcut.pl ${PREFIX}/bin/ircd-shortcut
	${INSTALL_DATA} ${WRKSRC}/doc/example.conf ${PREFIX}/etc/ratbox-services.conf.sample
	${INSTALL_DATA} ${WRKSRC}/doc/schema.txt ${DATADIR}/schema.sql

	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

#-----------------------------------------------------------------------

.include <bsd.port.post.mk>
