# Created by: alexis

PORTNAME=	nsd
DISTVERSION=	4.3.9
CATEGORIES=	dns
MASTER_SITES=	https://www.nlnetlabs.nl/downloads/nsd/

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Authoritative only non-recursive name server

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe ssl

LIB_DEPENDS=	libevent.so:devel/libevent

CPE_VENDOR=	nlnetlabs
USE_RC_SUBR=	nsd

NSDUSER?=	nsd
NSDGROUP?=	nsd
NSDLSDIR=	/var
NSDDBDIR=	/var/db/nsd
NSDRUNDIR=	/var/run/nsd
NSDMAX_IPS?=	512

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${NSDLSDIR} \
		--with-configdir=${ETCDIR} \
		--with-dbfile=${NSDDBDIR}/nsd.db \
		--with-libevent=${LOCALBASE} \
		--with-pidfile=${NSDRUNDIR}/nsd.pid \
		--with-ssl=${OPENSSLBASE} \
		--with-user=${NSDUSER}

PLIST_SUB=	NSDDBDIR=${NSDDBDIR} \
		NSDGROUP=${NSDGROUP} \
		NSDRUNDIR=${NSDRUNDIR} \
		NSDUSER=${NSDUSER}

USERS=		${NSDUSER}
GROUPS=		${NSDGROUP}

PORTDOCS=	CREDITS ChangeLog LICENSE NSD-4-features NSD-DATABASE \
		NSD-DIFFFILE NSD-FOR-BIND-USERS README README.icc RELNOTES \
		REQUIREMENTS TESTPLAN TODO UPGRADING coding-style \
		differences.tex

OPTIONS_DEFINE=		BIND8_STATS CHECKING DNSTAP DOCS IPV6 LARGEFILE \
			MINRESPSIZE MMAP MUNIN_PLUGIN NSEC3 PACKED RADIXTREE \
			ROOT_SERVER RRL ZONE_STATS
OPTIONS_DEFAULT=	BIND8_STATS LARGEFILE MINRESPSIZE NSEC3 RADIXTREE RRL \
			ZONE_STATS
OPTIONS_SUB=		yes

MUNIN_PLUGIN_IMPLIES=	BIND8_STATS

ROOT_SERVER_DESC=	Configure as a root server
LARGEFILE_DESC=		Largefile support
BIND8_STATS_DESC=	BIND8-like NSTATS & XSTATS
CHECKING_DESC=		Internal run-time checks
NSEC3_DESC=		NSEC3 support
MINRESPSIZE_DESC=	Minimial response sizing
MMAP_DESC=		Use mmap instead of malloc (experimental)
RRL_DESC=		Response Rate Limiting
ZONE_STATS_DESC=	Separate statistics for each zone
MUNIN_PLUGIN_DESC=	Install Munin plugin (requires BIND8_STATS)
RADIXTREE_DESC=		Enabled: more (15%) memory use but less CPU cycles
PACKED_DESC=		Enable packed structures for reduced memory use
DNSTAP_DESC=		Enable dnstap logging support

ROOT_SERVER_CONFIGURE_ENABLE=	root-server
LARGEFILE_CONFIGURE_ENABLE=	largefile
BIND8_STATS_CONFIGURE_ENABLE=	bind8-stats
CHECKING_CONFIGURE_ENABLE=	checking
NSEC3_CONFIGURE_ENABLE=		nsec3
MINRESPSIZE_CONFIGURE_ENABLE=	minimal-responses
MMAP_CONFIGURE_ENABLE=		mmap
RRL_CONFIGURE_ENABLE=		ratelimit
ZONE_STATS_CONFIGURE_ENABLE=	zone-stats
IPV6_CONFIGURE_ENABLE=		ipv6
RADIXTREE_CONFIGURE_ENABLE=	radix-tree
PACKED_CONFIGURE_ENABLE=	packed
DNSTAP_CONFIGURE_ENABLE=	dnstap
DNSTAP_LIB_DEPENDS=		libfstrm.so:devel/fstrm \
				libprotobuf-c.so:devel/protobuf-c

post-build-MUNIN_PLUGIN-on:
	${REINPLACE_CMD} \
		-e 's|/usr/local|${LOCALBASE}|g' \
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

post-install-MUNIN_PLUGIN-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/munin/plugins
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/nsd_munin_ \
		${STAGEDIR}${PREFIX}/share/munin/plugins

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
