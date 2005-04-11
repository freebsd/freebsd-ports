# Ports collection makefile for:	Unreal-IRCd
# Date created:				15 April 2004
# Whom:					Gerrit Beine (<tux@pinguru.net>)
#
# $FreeBSD$
#

PORTNAME=	Unreal
PORTVERSION=	3.2.3
CATEGORIES=	irc
MASTER_SITES=	http://unreal.atlanti-ka.org/ \
		http://unreal.stfu-n00b.net/ \
		http://unrealircd.funny-chat.net/ \
		http://unrealircd.fyrebird.net/ \
		http://unrealircd.chaosteam.hu/ \
		http://64.84.10.70/download/ \
		http://www.gower.net/unrealircd/ \
		http://www.ilmarinen.us/unreal/ \
		http://unrealircd.alert-net.com/ \
		http://www1.dnwt.net/unreal/
#		http://www.tiefighter.org/~unreal/downloads/ \  # file missing
#		http://mirror.nimsay-networks.com/unrealircd/ \ # file missing
#		http://unrealircd.za.net/ \                     # file missing
#		ftp://unrealircd.za.net/pub/UnrealIRCd/ \    # connect refused
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	tux@pinguru.net
COMMENT=	Unreal - the next generation ircd

WRKSRC=		${WRKDIR}/${PORTNAME}3.2

MODULESDIR=	${PREFIX}/lib/${PORTNAME}
CONFIGDIR=	${PREFIX}/etc/${PORTNAME}
RUNDIR=		/var/run/ircd
LOGDIR=		/var/log/ircd

HAS_CONFIGURE=	yes
USE_RC_SUBR=	unrealircd.sh
USE_REINPLACE=	yes

SUB_LIST+=	RUNDIR=${RUNDIR}

CONFIGURE_ARGS=	--with-listen=5 \
		--with-dpath=${CONFIGDIR} \
		--with-spath=${PREFIX}/libexec/ircd \
		--with-nick-history=2000 \
		--with-sendq=3000000 \
		--with-bufferpool=18 \
		--with-permissions=0600 \
		--with-fd-setsize=1024 \
		--enable-dynamic-linking

OPTIONS=	HUB "Configure as a hub (otherwise configure as a leaf)" on \
		NOSPOOF "Enable anti-spoof protection" off \
		ZIPLINKS "Enable ziplinks support" off \
		SSL "Support SSL connecions" off \
		IPV6 "Enable ipv6 support" off \
		PREFIXAQ "Enable prefixes for chanadmin and chanowner" off
#		REMOTE "Enable remote includes" off \ # this does not work at the moment

PORT_DBDIR?=	/var/db/ports
LATEST_LINK=	${PORTNAME}
OPTIONSFILE?=	${PORT_DBDIR}/${LATEST_LINK}/options

.if exists(${OPTIONSFILE})
.include "${OPTIONSFILE}"
.endif

.if !defined(NOPORTDOCS)
DOCS=		Donation doc/Authors doc/coding-guidelines \
		doc/example.conf doc/tao.of.irc \
		doc/translations.txt doc/unreal32docs.html \
		doc/technical/005.txt doc/technical/base64.txt \
		doc/technical/protoctl.txt doc/technical/token.txt \
		doc/technical/vl.txt
.endif

.if defined(WITH_HUB)
CONFIGURE_ARGS+=	--enable-hub
.endif

.if defined(WITH_NOSPOOF)
CONFIGURE_ARGS+=	--enable-nospoof
.endif

.if defined(WITH_ZIPLINKS)
CONFIGURE_ARGS+=	--enable-ziplinks
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-inet6
.endif

.if defined(WITH_SSL)
CONFIGURE_ARGS+=	--enable-ssl
USE_OPENSSL=	yes
.endif

.if defined(WITH_REMOTE)
LIB_DEPENDS+=	curl.3:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--enable-libcurl=${LOCALBASE}
.endif

.if defined(WITH_PREFIXAQ)
CONFIGURE_ARGS+=	--enable-prefixaq
.endif

SQLMOD=		${PORTNAME}/SQLMod.tar.gz

.if exists(${DISTDIR}/${SQLMOD})
USE_MYSQL=	yes
WITH_SQLMOD=	yes
MAKE_ARGS=	all custommodule MODULEFILE=m_sqlmod
PLIST_FILES+=	etc/Unreal/m_sqlmod.conf lib/Unreal/m_sqlmod.so
		Unreal/doc/Changes.sqlmod Unreal/doc/README.sqlmod \
		Unreal/doc/LICENSE.sqlmod
.endif

post-extract:
.if defined(WITH_SQLMOD)
	@${TAR} xfz ${DISTDIR}/${SQLMOD} -C ${WRKSRC}
	@${MV} ${WRKSRC}/SQLMod* ${WRKSRC}/SQLMod
	@${CP} -r ${WRKSRC}/SQLMod/m_sqlmod.c ${WRKSRC}/src/modules
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX}," \
		-e "s,%%RUNDIR%%,${RUNDIR}," \
		-e "s,%%LOGDIR%%,${LOGDIR}," ${WRKSRC}/include/config.h
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX}," \
		-e "s,%%LOGDIR%%,${LOGDIR}," ${WRKSRC}/doc/example.conf
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX}," ${WRKSRC}/networks/makenet
	@${REINPLACE_CMD} -e "s,%%RUNDIR%%,${RUNDIR}," ${WRKSRC}/src/ircd.c
	@${REINPLACE_CMD} -e "s,%%RUNDIR%%,${RUNDIR}," ${WRKSRC}/src/modules.c
	@${REINPLACE_CMD} -e "s,%%RUNDIR%%,${RUNDIR}," ${WRKSRC}/src/s_conf.c
	@${REINPLACE_CMD} -e "s,%%RUNDIR%%,${RUNDIR}," ${WRKSRC}/src/url.c
.if defined(WITH_SQLMOD)
	@${PATCH} -d ${WRKSRC} < ${WRKSRC}/SQLMod/patch
.endif

do-install:
	${INSTALL} -m 0700 ${WRKSRC}/src/ircd ${PREFIX}/libexec/ircd
	${MKDIR} ${MODULESDIR}
	${MKDIR} ${CONFIGDIR}
	${MKDIR} ${CONFIGDIR}/aliases
	${MKDIR} ${DATADIR}/networks
	${MKDIR} ${RUNDIR}/tmp
	${MKDIR} ${LOGDIR}
	${TOUCH} ${CONFIGDIR}/ircd.motd
	${TOUCH} ${CONFIGDIR}/ircd.rules
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/badwords.*.conf ${CONFIGDIR}
	${INSTALL_DATA} ${WRKSRC}/help.conf ${CONFIGDIR}
	${INSTALL_DATA} ${WRKSRC}/spamfilter.conf ${CONFIGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example.conf ${CONFIGDIR}/unrealircd.conf
	${INSTALL_DATA} ${WRKSRC}/aliases/*.conf ${CONFIGDIR}/aliases
	${INSTALL_DATA} ${WRKSRC}/networks/*.network ${DATADIR}/networks
	${INSTALL_DATA} ${WRKSRC}/networks/networks.ndx ${DATADIR}/networks
	${INSTALL_SCRIPT} ${WRKSRC}/networks/makenet ${DATADIR}/networks
	${INSTALL} ${WRKSRC}/src/modules/*.so ${MODULESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

post-install:
.if defined(WITH_SQLMOD)
	@${CP} ${WRKSRC}/SQLMod/sample.conf ${CONFIGDIR}/m_sqlmod.conf
	@${CP} ${WRKSRC}/SQLMod/Changes ${DOCSDIR}/Changes.sqlmod
	@${CP} ${WRKSRC}/SQLMod/README ${DOCSDIR}/README.sqlmod
	@${CP} ${WRKSRC}/SQLMod/LICENSE ${DOCSDIR}/LICENSE.sqlmod
.endif

.include <bsd.port.mk>
