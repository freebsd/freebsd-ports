PORTNAME=	unreal
DISTVERSION=	6.1.1.1
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	https://www.unrealircd.org/downloads/
DISTNAME=	${PORTNAME}ircd-${PORTVERSION}

MAINTAINER=	tanawts@gmail.com
COMMENT=	Unreal - the next generation ircd
WWW=		https://www.unrealircd.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcares.so:dns/c-ares \
		libpcre2-8.so:devel/pcre2 \
		libargon2.so:security/libargon2 \
		libsodium.so:security/libsodium \
		libjansson.so:devel/jansson \
		libmaxminddb.so:net/libmaxminddb
RUN_DEPENDS=	${LOCALBASE}/bin/geoipupdate:net/geoipupdate

USES=		pkgconfig cpe gmake localbase ssl
MODULESDIR=	${PREFIX}/lib/${PORTNAME}
MODULESSUBDIR=	chanmodes extbans rpc usermodes
CONFIGDIR=	${PREFIX}/etc/${PORTNAME}
RUNDIR=		/var/run/ircd
LOGDIR=		/var/log/ircd
CACHEDIR=	/var/cache/ircd
_TMPDIR=	/tmp

EXTRACT_AFTER_ARGS=	--exclude extras/*.tar.gz

HAS_CONFIGURE=	yes
USE_RC_SUBR=	unrealircd

USERS=		ircd
GROUPS=		ircd
CPE_VENDOR=	unrealircd
CPE_PRODUCT=	unrealircd

SUB_LIST+=	RUNDIR=${RUNDIR}
SUB_LIST+=	USERS=${USERS}
SUB_LIST+=	GROUPS=${GROUPS}

CONFIGURE_ARGS=	--with-nick-history=2000 \
		--with-bindir=${LOCALBASE}/bin \
		--with-scriptdir=${DATADIR} \
		--with-confdir=${CONFIGDIR} \
		--with-builddir=${WRKSRC} \
		--with-modulesdir=${MODULESDIR} \
		--with-logdir=${LOGDIR} \
		--with-cachedir=${CACHEDIR} \
		--with-tmpdir=${_TMPDIR} \
		--with-datadir=${DATADIR}/data \
		--with-docdir=${DATADIR}/doc \
		--with-pidfile=${RUNDIR}/ircd.pid \
		--with-controlfile=${RUNDIR}/ircd.ctl \
		--with-permissions=0600 \
		--with-system-cares \
		--enable-dynamic-linking \
		--enable-libmaxminddb=yes \
		--enable-ssl

OPTIONS_DEFINE=	DOCS

PORTDOCS=	${DOCS:T}
DOCS=		Donation Authors coding-guidelines \
		tao.of.irc translations.txt \
		technical/005.txt technical/base64.txt \
		technical/serverprotocol.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ircd ${STAGEDIR}${PREFIX}/libexec/ircd
	${MKDIR} ${STAGEDIR}${CACHEDIR}
	${MKDIR} ${STAGEDIR}${CONFIGDIR}
	${MKDIR} ${STAGEDIR}${CONFIGDIR}/aliases
	${MKDIR} ${STAGEDIR}${CONFIGDIR}/examples
	${MKDIR} ${STAGEDIR}${CONFIGDIR}/help
	${MKDIR} ${STAGEDIR}${CONFIGDIR}/tls
	${MKDIR} ${STAGEDIR}${LOGDIR}
	${MKDIR} ${STAGEDIR}${MODULESDIR}
	${MKDIR} ${STAGEDIR}${MODULESDIR}/chanmodes
	${MKDIR} ${STAGEDIR}${MODULESDIR}/extbans
	${MKDIR} ${STAGEDIR}${MODULESDIR}/rpc
	${MKDIR} ${STAGEDIR}${MODULESDIR}/usermodes
	${MKDIR} ${STAGEDIR}${RUNDIR}
	${TOUCH} ${STAGEDIR}${CONFIGDIR}/ircd.motd.sample
	${TOUCH} ${STAGEDIR}${CONFIGDIR}/ircd.rules.sample
	(cd ${WRKSRC}/doc/conf && ${COPYTREE_SHARE} . ${STAGEDIR}${CONFIGDIR})
	${INSTALL_DATA} ${WRKSRC}/doc/conf/examples/example.conf ${STAGEDIR}${CONFIGDIR}/unrealircd.conf.sample
	${INSTALL_LIB} ${WRKSRC}/src/modules/*.so ${STAGEDIR}${MODULESDIR}
.for subdir in ${MODULESSUBDIR}
	${INSTALL_LIB} ${WRKSRC}/src/modules/${subdir}/*.so ${STAGEDIR}${MODULESDIR}/${subdir}/
.endfor

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
