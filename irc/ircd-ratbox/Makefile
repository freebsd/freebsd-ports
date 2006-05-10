# New ports collection makefile for:	ircd-ratbox
# Date Created:				2006-01-27
# Whom:					Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$
#
# ex: ts=8

PORTNAME=	ircd-ratbox
PORTVERSION=	2.1.8
CATEGORIES=	irc ipv6
MASTER_SITES=	ftp://ftp.ircd-ratbox.org/pub/ircd-ratbox/	\
		ftp://ftp.demon.co.uk/pub/mirrors/ircd-ratbox/	\
		http://www.ircd-ratbox.org/download/		\
		ftp://ftp.parodius.com/pub/ircd-ratbox/
EXTRACT_SUFX=	.tgz

MAINTAINER=	shaun@inerd.com
COMMENT=	An advanced, stable IRC daemon, used on many EFnet servers

MAN8=		ircd.8
USE_RC_SUBR=	ircd-ratbox.sh

LOGDIR=		/var/log/${PORTNAME}
RUNDIR=		/var/run/${PORTNAME}
SUB_FILES=	pkg-message pkg-install
PLIST_SUB=	LOGDIR=${LOGDIR} RUNDIR=${RUNDIR}
SUB_LIST=	LOGDIR=${LOGDIR} RUNDIR=${RUNDIR}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-confdir=${PREFIX}/etc/${PORTNAME}	   \
		--with-logdir=/var/log/${PORTNAME}		   \
		--with-moduledir=${PREFIX}/lib/${PORTNAME}/modules \
		--with-helpdir=${DATADIR}/help

PORTDOCS=	[^i]*.txt README.* technical/[^i]*.txt Tao-of-IRC.*

#-- Options ------------------------------------------------------------

OPTIONS=	KQUEUE		"Use superior kqueue(2) instead of poll(2)"	on  \
		OPENSSL		"Enable openssl support"			on  \
		IPV6		"Enable IPv6 support"				off \
		ZIPLINKS	"Enable ziplinks support"			on  \
		SHARED_MODULES	"Enable shared modules support"			on  \
		ASSERT		"Enable debugging code"				off \
		SMALL_NET	"Tune server for small networks"		off \
		SERVICES	"Enable ratbox-services compatibility code"	off

#----------------------------------------------------------------------

.include <bsd.port.pre.mk>

.if defined(WITH_KQUEUE)
CONFIGURE_ARGS+=	--enable-kqueue
.else
CONFIGURE_ARGS+=	--enable-poll
.endif

.if defined(WITH_OPENSSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--enable-openssl
.else
CONFIGURE_ARGS+=	--disable-openssl
.endif

.if defined(WITH_IPV6)
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

#-- User Configuration -------------------------------------------------

.if defined(NICKLEN)
CONFIGURE_ARGS+=	--with-nicklen=${NICKLEN}
.endif

.if defined(TOPICLEN)
CONFIGURE_ARGS+=	--with-topiclen=${TOPICLEN}
.endif

.if defined(MAXCLIENTS)
CONFIGURE_ARGS+=	--with-maxclients=${MAXCLIENTS}
.endif

#-----------------------------------------------------------------------

pre-configure:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "This port has additional options:"
	@${ECHO_MSG} "    NICKLEN     [default 9, max 50]    - Max nick length on server"
	@${ECHO_MSG} "    TOPICLEN    [default 120, max 390] - Max topic length"
	@${ECHO_MSG} "    MAXCLIENTS  [default 3000]         - Max clients server can handle"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Press CTRL+C now if you wish to set them."
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e "s#-O2##" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s#%%PREFIX%%#${PREFIX}#g"		  \
			  ${WRKSRC}/doc/example.conf		  \
			  ${WRKSRC}/doc/example.efnet.conf
	@${REINPLACE_CMD} -e "s#%%RUNDIR%%#${RUNDIR}#g" ${WRKSRC}/include/config.h

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

	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

#-----------------------------------------------------------------------

.include <bsd.port.post.mk>
