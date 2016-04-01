# Created by: Gerrit Beine (<tux@pinguru.net>)
# $FreeBSD$

PORTNAME=	Unreal
PORTVERSION=	3.2.10.5
PORTREVISION=	1
CATEGORIES=	irc ipv6
MASTER_SITES=	http://www.unrealircd.com/downloads/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Unreal - the next generation ircd

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcares.so:dns/c-ares

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}

MODULESDIR=	${PREFIX}/lib/${PORTNAME}
CONFIGDIR=	${PREFIX}/etc/${PORTNAME}
RUNDIR=		/var/run/ircd
LOGDIR=		/var/log/ircd

HAS_CONFIGURE=	yes
USE_RC_SUBR=	unrealircd

USERS=		ircd
GROUPS=		ircd
CPE_VENDOR=	unrealircd
CPE_PRODUCT=	unrealircd

USES=		pkgconfig cpe

SUB_LIST+=	RUNDIR=${RUNDIR}
SUB_LIST+=	USERS=${USERS}
SUB_LIST+=	GROUPS=${GROUPS}

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
		--with-system-cares \
		--enable-dynamic-linking

OPTIONS_DEFINE=	HUB NOSPOOF ZIPLINKS SSL IPV6 PREFIXAQ REMOTE DOCS
OPTIONS_DEFAULT=	HUB SSL
HUB_DESC=	Configure as a hub (otherwise configure as a leaf)
NOSPOOF_DESC=	Enable anti-spoof protection
ZIPLINKS_DESC=	Enable ziplinks support
PREFIXAQ_DESC=	Enable prefixes for chanadmin and chanowner
REMOTE_DESC=	Enable remote includes

PORTDOCS=	*
DOCS=		Donation doc/Authors doc/coding-guidelines \
		doc/example.conf doc/tao.of.irc \
		doc/translations.txt doc/unreal32docs.html \
		doc/technical/005.txt doc/technical/base64.txt \
		doc/technical/protoctl.txt doc/technical/token.txt \
		doc/technical/vl.txt

HUB_CONFIGURE_ENABLE=	hub
NOSPOOF_CONFIGURE_ENABLE=	nospoof
ZIPLINKS_CONFIGURE_ENABLE=	ziplinks
IPV6_CONFIGURE_ENABLE=	inet6
SSL_CONFIGURE_ENABLE=	ssl
SSL_USE=	OPENSSL=yes
REMOTE_LIB_DEPENDS=	libcurl.so:ftp/curl
REMOTE_CONFIGURE_ENABLE=	--enable-libcurl=${LOCALBASE}
PREFIXAQ_CONFIGURE_ENABLE=	prefixaq

SQLMOD=		${PORTNAME}/SQLMod.tar.gz

.if exists(${DISTDIR}/${SQLMOD})
USE_MYSQL=	yes
WITH_SQLMOD=	yes
MAKE_ARGS=	all custommodule MODULEFILE=m_sqlmod
PLIST_SUB+=	SQLMOD=""
.else
PLIST_SUB+=	SQLMOD="@comment "
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
	@${REINPLACE_CMD} -e "s,%%RUNDIR%%,${RUNDIR}," ${WRKSRC}/src/ircd.c
	@${REINPLACE_CMD} -e "s,%%RUNDIR%%,${RUNDIR}," ${WRKSRC}/src/modules.c
	@${REINPLACE_CMD} -e "s,%%RUNDIR%%,${RUNDIR}," ${WRKSRC}/src/s_conf.c
	@${REINPLACE_CMD} -e "s,%%RUNDIR%%,${RUNDIR}," ${WRKSRC}/src/url.c
.if defined(WITH_SQLMOD)
	@${PATCH} -d ${WRKSRC} < ${WRKSRC}/SQLMod/patch
.endif
	@${REINPLACE_CMD} -e "/Your system does not support IPv6/ s|as_fn_error|echo|" ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ircd ${STAGEDIR}${PREFIX}/libexec/ircd
	${MKDIR} ${STAGEDIR}${MODULESDIR}
	${MKDIR} ${STAGEDIR}${CONFIGDIR} || true
	${MKDIR} ${STAGEDIR}${CONFIGDIR}/aliases || true
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/aliases
	${MKDIR} ${STAGEDIR}${RUNDIR}/tmp
	${MKDIR} ${STAGEDIR}${LOGDIR}
	${TOUCH} ${STAGEDIR}${CONFIGDIR}/ircd.motd
	${TOUCH} ${STAGEDIR}${CONFIGDIR}/ircd.rules
	${INSTALL_DATA} ${WRKSRC}/badwords.*.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/help.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/spamfilter.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example.conf ${STAGEDIR}${EXAMPLESDIR}/unrealircd.conf
	${INSTALL_DATA} ${WRKSRC}/aliases/*.conf ${STAGEDIR}${EXAMPLESDIR}/aliases
	${INSTALL} ${WRKSRC}/src/modules/*.so ${STAGEDIR}${MODULESDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

post-install:
.if defined(WITH_SQLMOD)
	@${CP} ${WRKSRC}/SQLMod/sample.conf ${STAGEDIR}${CONFIGDIR}/m_sqlmod.conf
	@${CP} ${WRKSRC}/SQLMod/Changes ${STAGEDIR}${DOCSDIR}/Changes.sqlmod
	@${CP} ${WRKSRC}/SQLMod/README ${STAGEDIR}${DOCSDIR}/README.sqlmod
	@${CP} ${WRKSRC}/SQLMod/LICENSE ${STAGEDIR}${DOCSDIR}/LICENSE.sqlmod
.endif

.include <bsd.port.mk>
