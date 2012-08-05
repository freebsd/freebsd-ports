# Ports collection makefile for:	Unreal-IRCd
# Date created:				15 April 2004
# Whom:					Gerrit Beine (<tux@pinguru.net>)
#
# $FreeBSD$
#

PORTNAME=	Unreal
PORTVERSION=	3.2.9
CATEGORIES=	irc ipv6
MASTER_SITES=	http://www.unrealircd.com/downloads/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	tanawts@gmail.com
COMMENT=	Unreal - the next generation ircd

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	cares.2:${PORTSDIR}/dns/c-ares

WRKSRC=		${WRKDIR}/${DISTNAME:R}

MODULESDIR=	${PREFIX}/lib/${PORTNAME}
CONFIGDIR=	${PREFIX}/etc/${PORTNAME}
RUNDIR=		/var/run/ircd
LOGDIR=		/var/log/ircd

HAS_CONFIGURE=	yes
USE_RC_SUBR=	unrealircd

USERS=		ircd
GROUPS=		ircd

SUB_LIST+=	RUNDIR=${RUNDIR}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	${CPPFLAGS}
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
		PREFIXAQ "Enable prefixes for chanadmin and chanowner" off \
		REMOTE "Enable remote includes" off

.include <bsd.port.pre.mk>

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
# we can't use USE_OPENSSL=yes after including bsd.port.pre.mk
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
.endif

.if defined(WITH_REMOTE)
LIB_DEPENDS+=	curl.6:${PORTSDIR}/ftp/curl
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
PLIST_FILES+=	etc/Unreal/m_sqlmod.conf lib/Unreal/m_sqlmod.so \
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
		-e "s,%%USERS%%,${USERS}," \
		-e "s,%%GROUPS%%,${GROUPS}," \
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
	@${REINPLACE_CMD} -e "/Your system does not support IPv6/ s|as_fn_error|echo|" ${WRKSRC}/configure
do-install:
	${INSTALL} -m 0700 ${WRKSRC}/src/ircd ${PREFIX}/libexec/ircd
	${MKDIR} ${MODULESDIR}
	${MKDIR} ${CONFIGDIR} || true
	${MKDIR} ${CONFIGDIR}/aliases || true
	${MKDIR} ${EXAMPLESDIR}/aliases
	${MKDIR} ${DATADIR}/networks
	${MKDIR} ${RUNDIR}/tmp
	${MKDIR} ${LOGDIR}
	${TOUCH} ${CONFIGDIR}/ircd.motd
	${TOUCH} ${CONFIGDIR}/ircd.rules
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/badwords.*.conf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/help.conf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/spamfilter.conf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example.conf ${EXAMPLESDIR}/unrealircd.conf
	${INSTALL_DATA} ${WRKSRC}/aliases/*.conf ${EXAMPLESDIR}/aliases
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
	@[ -f ${CONFIGDIR}/aliases/aliases.conf ] || ${INSTALL_DATA} ${EXAMPLESDIR}/aliases/aliases.conf ${CONFIGDIR}/aliases
	@[ -f ${CONFIGDIR}/aliases/anope.conf ] || ${INSTALL_DATA} ${EXAMPLESDIR}/aliases/anope.conf ${CONFIGDIR}/aliases
	@[ -f ${CONFIGDIR}/aliases/auspice.conf ] || ${INSTALL_DATA} ${EXAMPLESDIR}/aliases/auspice.conf ${CONFIGDIR}/aliases
	@[ -f ${CONFIGDIR}/aliases/cygnus.conf ] || ${INSTALL_DATA} ${EXAMPLESDIR}/aliases/cygnus.conf ${CONFIGDIR}/aliases
	@[ -f ${CONFIGDIR}/aliases/epona.conf ] || ${INSTALL_DATA} ${EXAMPLESDIR}/aliases/epona.conf ${CONFIGDIR}/aliases
	@[ -f ${CONFIGDIR}/aliases/generic.conf ] || ${INSTALL_DATA} ${EXAMPLESDIR}/aliases/generic.conf ${CONFIGDIR}/aliases
	@[ -f ${CONFIGDIR}/aliases/genericstats.conf ] || ${INSTALL_DATA} ${EXAMPLESDIR}/aliases/genericstats.conf ${CONFIGDIR}/aliases
	@[ -f ${CONFIGDIR}/aliases/ircservices.conf ] || ${INSTALL_DATA} ${EXAMPLESDIR}/aliases/ircservices.conf ${CONFIGDIR}/aliases
	@[ -f ${CONFIGDIR}/aliases/operstats.conf ] || ${INSTALL_DATA} ${EXAMPLESDIR}/aliases/operstats.conf ${CONFIGDIR}/aliases
	@[ -f ${CONFIGDIR}/badwords.channel.conf ] || ${INSTALL_DATA} ${EXAMPLESDIR}/badwords.channel.conf ${CONFIGDIR}
	@[ -f ${CONFIGDIR}/badworks.message.conf ] || ${INSTALL_DATA} ${EXAMPLESDIR}/badwords.message.conf ${CONFIGDIR}
	@[ -f ${CONFIGDIR}/badwords.quit.conf ] || ${INSTALL_DATA} ${EXAMPLESDIR}/badwords.quit.conf ${CONFIGDIR}
	@[ -f ${CONFIGDIR}/help.conf ] || ${INSTALL_DATA} ${EXAMPLESDIR}/help.conf ${CONFIGDIR}
	@[ -f ${CONFIGDIR}/spamfilter.conf ] || ${INSTALL_DATA} ${EXAMPLESDIR}/spamfilter.conf ${CONFIGDIR}
	@[ -f ${CONFIGDIR}/unrealircd.conf ] || ${INSTALL_DATA} ${EXAMPLESDIR}/unrealircd.conf ${CONFIGDIR}
.if defined(WITH_SQLMOD)
	@${CP} ${WRKSRC}/SQLMod/sample.conf ${CONFIGDIR}/m_sqlmod.conf
	@${CP} ${WRKSRC}/SQLMod/Changes ${DOCSDIR}/Changes.sqlmod
	@${CP} ${WRKSRC}/SQLMod/README ${DOCSDIR}/README.sqlmod
	@${CP} ${WRKSRC}/SQLMod/LICENSE ${DOCSDIR}/LICENSE.sqlmod
.endif

.include <bsd.port.post.mk>
