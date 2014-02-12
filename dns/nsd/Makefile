# Created by: alexis
# $FreeBSD$

PORTNAME=	nsd
PORTVERSION=	4.0.1
PORTREVISION=	1
CATEGORIES=	dns ipv6
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/nsd/	\
		ftp://ftp.rhnet.is/pub/nsd/

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	An authoritative only non-recursive name server

LICENSE=	BSD3CLAUSE

CONFLICTS=	nsd-[0-3]* nsd3-[0-9]*

USE_RC_SUBR=	nsd

NSDUSER?=	bind
NSDGROUP?=	bind
NSDLSDIR=	/var
NSDDBDIR=	/var/db/nsd
NSDRUNDIR=	/var/run/nsd
NSDMAX_IPS?=	512

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libevent=${LOCALBASE} \
		--with-user=${NSDUSER} \
		--with-configdir=${PREFIX}/etc/nsd \
		--localstatedir=${NSDLSDIR} \
		--with-dbfile=${NSDDBDIR}/nsd.db \
		--with-pidfile=${NSDRUNDIR}/nsd.pid

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST+=	NSDUSER=${NSDUSER} \
		NSDGROUP=${NSDGROUP} \
		NSDDBDIR=${NSDDBDIR} \
		NSDRUNDIR=${NSDRUNDIR}

USE_OPENSSL=	yes

MAN5=		nsd.conf.5
MAN8=		nsd.8 nsd-checkconf.8 nsd-control.8

PORTDOCS=	CREDITS ChangeLog LICENSE NSD-DATABASE NSD-DIFFFILE \
		NSD-4-features NSD-FOR-BIND-USERS README README.icc RELNOTES \
		REQUIREMENTS TESTPLAN TODO UPGRADING coding-style \
		differences.tex

OPTIONS_DEFINE=		ROOT_SERVER LARGEFILE IPV6 BIND8_STATS CHECKING \
		MINRESPSIZE NSEC3 NSEC3PREHASH MMAP MAXIPS DOCS RRL EUI_RRTYPES
OPTIONS_DEFAULT=	LARGEFILE IPV6 NSEC3 NSEC3PREHASH MINRESPSIZE RRL \
		 EUI_RRTYPES

ROOT_SERVER_DESC=	Configure as a root server
LARGEFILE_DESC=		Largefile support
BIND8_STATS_DESC=	BIND8-like NSTATS & XSTATS
CHECKING_DESC=		Internal run-time checks
NSEC3_DESC=		NSEC3 support
NSEC3PREHASH_DESC=	Full NSEC3 pre-hashing
MINRESPSIZE_DESC=	Minimial response sizing
MMAP_DESC=		Use mmap instead of malloc (experimental)
MAXIPS_DESC=		Raise max-ips from 8 to ${NSDMAX_IPS}
RRL_DESC=		Response Rate Limiting
EUI_RRTYPES_DESC=	EUI48 and EUI64 RRtypes support

.include <bsd.port.options.mk>

LIB_DEPENDS+=	event-1:${PORTSDIR}/devel/libevent

.if ${PORT_OPTIONS:MROOT_SERVER}
CONFIGURE_ARGS+=	--enable-root-server
.endif

.if empty(PORT_OPTIONS:MLARGEFILE)
CONFIGURE_ARGS+=	--disable-largefile
.endif

.if empty(PORT_OPTIONS:MIPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MBIND8_STATS}
CONFIGURE_ARGS+=	--enable-bind8-stats
.endif

.if ${PORT_OPTIONS:MCHECKING}
CONFIGURE_ARGS+=	--enable-checking
.endif

.if empty(PORT_OPTIONS:MNSEC3)
CONFIGURE_ARGS+=	--disable-nsec3
.endif

.if empty(PORT_OPTIONS:MMINRESPSIZE)
CONFIGURE_ARGS+=	--disable-minimal-responses
.endif

.if empty(PORT_OPTIONS:MNSEC3PREHASH)
CONFIGURE_ARGS+=	--disable-full-prehash
.endif

.if ${PORT_OPTIONS:MMMAP}
CONFIGURE_ARGS+=	--enable-mmap
.endif

.if ${PORT_OPTIONS:MMAXIPS}
CONFIGURE_ARGS+=	--with-max-ips=${NSDMAX_IPS}
.endif

.if ${PORT_OPTIONS:MRRL}
CONFIGURE_ARGS+=	--enable-ratelimit
.endif

.if ${PORT_OPTIONS:MEUI_RRTYPES}
CONFIGURE_ARGS+=	--enable-draft-rrtypes
.endif

pre-patch:
.if defined(NSD_OPTIONS)
	@${ECHO_MSG}
	@${ECHO_MSG}
	@${ECHO_MSG}
	@${ECHO_MSG} "***** ALERT *****"
	@${ECHO_MSG} "NSD_OPTIONS is no longer supported,"
	@${ECHO_MSG} "${PORTNAME} uses OPTIONS, consider running"
	@${ECHO_MSG} "# make config"
	@${ECHO_MSG}
	@${ECHO_MSG}
	@${ECHO_MSG}
	@sleep 10
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/nsd.conf.sample \
		${STAGEDIR}${PREFIX}/etc/nsd/nsd.conf.sample
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}/${f}
.endfor
.endif
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
