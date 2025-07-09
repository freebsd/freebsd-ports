PORTNAME=	nsd
DISTVERSION=	4.12.0
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	https://www.nlnetlabs.nl/downloads/nsd/

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Authoritative only non-recursive name server
WWW=		https://www.nlnetlabs.nl/projects/nsd/about/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:devel/libevent

USES=		cpe ssl pkgconfig

CPE_VENDOR=	nlnetlabs
USE_RC_SUBR=	nsd

NSDUSER?=	nsd
NSDGROUP?=	nsd
NSDLSDIR=	/var
NSDRUNDIR=	/var/run/nsd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${NSDLSDIR} \
		--with-configdir=${ETCDIR} \
		--with-libevent=${LOCALBASE} \
		--with-pidfile=${NSDRUNDIR}/nsd.pid \
		--with-ssl=${OPENSSLBASE} \
		--with-user=${NSDUSER}

USERS=		${NSDUSER}
GROUPS=		${NSDGROUP}

PLIST_SUB=	NSDGROUP=${NSDGROUP} \
		NSDRUNDIR=${NSDRUNDIR} \
		NSDUSER=${NSDUSER}

PORTDOCS=	CREDITS ChangeLog LICENSE NSD-4-features NSD-DATABASE \
		NSD-DIFFFILE NSD-FOR-BIND-USERS README README.icc RELNOTES \
		REQUIREMENTS TESTPLAN TODO UPGRADING coding-style \
		differences.tex

OPTIONS_DEFINE=		BIND8_STATS CHECKING DNSTAP DOCS IPV6 LARGEFILE \
			MINRESPSIZE MMAP MUNIN_PLUGIN NSEC3 PACKED RADIXTREE \
			RRL ZONE_STATS
OPTIONS_DEFAULT=	BIND8_STATS LARGEFILE MINRESPSIZE NSEC3 RADIXTREE RRL \
			ZONE_STATS
OPTIONS_SUB=		yes

BIND8_STATS_DESC=	BIND8-like NSTATS & XSTATS
CHECKING_DESC=		Internal run-time checks
DNSTAP_DESC=		Enable dnstap logging support
LARGEFILE_DESC=		Largefile support
MINRESPSIZE_DESC=	Minimial response sizing
MMAP_DESC=		Use mmap instead of malloc (experimental)
MUNIN_PLUGIN_DESC=	Install Munin plugin (requires BIND8_STATS)
NSEC3_DESC=		NSEC3 support
PACKED_DESC=		Enable packed structures for reduced memory use
RADIXTREE_DESC=		Enabled: more (15%) memory use but less CPU cycles
RRL_DESC=		Response Rate Limiting
ZONE_STATS_DESC=	Separate statistics for each zone

BIND8_STATS_CONFIGURE_ENABLE=	bind8-stats
CHECKING_CONFIGURE_ENABLE=	checking
DNSTAP_LIB_DEPENDS=		libfstrm.so:devel/fstrm \
				libprotobuf-c.so:devel/protobuf-c
DNSTAP_CONFIGURE_ENABLE=	dnstap
IPV6_CONFIGURE_ENABLE=		ipv6
LARGEFILE_CONFIGURE_ENABLE=	largefile
MINRESPSIZE_CONFIGURE_ENABLE=	minimal-responses
MMAP_CONFIGURE_ENABLE=		mmap
MUNIN_PLUGIN_IMPLIES=		BIND8_STATS
NSEC3_CONFIGURE_ENABLE=		nsec3
PACKED_CONFIGURE_ENABLE=	packed
RADIXTREE_CONFIGURE_ENABLE=	radix-tree
RRL_CONFIGURE_ENABLE=		ratelimit
ZONE_STATS_CONFIGURE_ENABLE=	zone-stats

post-build-MUNIN_PLUGIN-on:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		-e 's|/usr/local/etc/nsd.conf|${ETCDIR}/nsd.conf|g' \
		-e 's|/usr/local/var/munin/plugin-state|/var/munin/plugin-state/root|g' \
		-e '90s|/var/munin/plugin-state/root|$${MUNIN_PLUGSTATE}|' \
		${WRKSRC}/contrib/nsd_munin_

post-install:
	${INSTALL_DATA} ${WRKSRC}/nsd.conf.sample \
		${STAGEDIR}${PREFIX}/etc/nsd/nsd.conf.sample
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/nsd \
		${STAGEDIR}${PREFIX}/sbin/nsd-checkconf \
		${STAGEDIR}${PREFIX}/sbin/nsd-checkzone \
		${STAGEDIR}${PREFIX}/sbin/nsd-control

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} \
		${STAGEDIR}${DOCSDIR}

post-install-MUNIN_PLUGIN-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/munin/plugins
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/nsd_munin_ \
		${STAGEDIR}${PREFIX}/share/munin/plugins

.include <bsd.port.mk>
