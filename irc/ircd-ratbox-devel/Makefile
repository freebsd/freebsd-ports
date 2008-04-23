# New ports collection makefile for:	ircd-ratbox
# Date Created:				2006-01-27
# Whom:					Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$
#
# ex: ts=8

PORTNAME=	ircd-ratbox
#PORTVERSION=	3.0.0
DISTVERSION=	3.0.0beta2
CATEGORIES=	irc ipv6
MASTER_SITES=	ftp://ftp.ircd-ratbox.org/pub/ircd-ratbox/testing/	\
		ftp://ftp.demon.co.uk/pub/mirrors/ircd-ratbox/testing/	\
		http://www.ircd-ratbox.org/download/testing/		\
		ftp://ftp.parodius.com/pub/ircd-ratbox/testing/old/	\
		http://www.ircd-ratbox.org/download/testing/old/
PKGNAMESUFFIX=	-devel

MAINTAINER=	moggie@elasticmind.net
COMMENT=	Advanced, stable IRC daemon, used widely on EFnet ('testing' release)

CONFLICTS=	ircd-ratbox-[0-9]*

USE_BZIP2=	yes
#MAN8=		ircd.8
USE_RC_SUBR=	ircd-ratbox.sh
USE_SQLITE=	3

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
		--with-helpdir=${DATADIR}/help				\
		--libdir=${PREFIX}/lib/${PORTNAME}			\
		--with-sqlite3-path=${LOCALBASE}

PORTDOCS=	[^i]*.txt README.* technical/[^i]*.txt Tao-of-IRC.*

#-- Options ------------------------------------------------------------

OPTIONS=	OPENSSL		"Enable openssl support"			on  \
		IPV6		"Enable IPv6 support"				on  \
		ZIPLINKS	"Enable ziplinks support"			on  \
		SHARED_MODULES	"Enable shared modules support"			on  \
		ASSERT		"Enable debugging code"				off \
		SMALL_NET	"Tune server for small networks"		off \
		SERVICES	"Enable ratbox-services compatibility code"	off \
		SSLONLY		"Enable SSL only chan' support (chanmode +S)"	off

#----------------------------------------------------------------------

.include <bsd.port.pre.mk>

.if defined(WITH_OPENSSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--enable-openssl
.else
CONFIGURE_ARGS+=	--disable-openssl
.endif

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
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
.endif

.if defined(WITH_SSLONLY)
CONFIGURE_ARGS+=	--enable-sslonly-channels
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
	@${ECHO_MSG} "Press CTRL+C now if you wish to set them."
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e "s#-O2##" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s#%%PREFIX%%#${PREFIX}#g"		  \
			  ${WRKSRC}/doc/example.conf		  \
			  ${WRKSRC}/doc/example.efnet.conf
	@${REINPLACE_CMD} -e "s#%%LOGDIR%%#${LOGDIR}#g"		\
				${WRKSRC}/doc/example.conf	\
				${WRKSRC}/doc/example.efnet.conf
	@${REINPLACE_CMD} -e "s#%%RUNDIR%%#${RUNDIR}#g" ${WRKSRC}/include/config.h
	@${REINPLACE_CMD} -e "s#%%DBDIR%%#${DBDIR}#g" ${WRKSRC}/include/config.h

pre-su-install:
	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	${MKDIR}  ${PREFIX}/etc/${PORTNAME}
	${MKDIR}  ${DATADIR}/help
	${MKDIR}  ${PREFIX}/lib/${PORTNAME}/modules

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/doc/ircd.motd ${PREFIX}/etc/${PORTNAME}/ircd.motd.sample
	${INSTALL_DATA} ${WRKSRC}/doc/example.conf ${PREFIX}/etc/${PORTNAME}/ircd.conf.sample
	${INSTALL_DATA} ${WRKSRC}/doc/example.efnet.conf ${PREFIX}/etc/${PORTNAME}/ircd-efnet.conf.sample

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
