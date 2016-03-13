# Created by: alexis
# $FreeBSD$

PORTNAME=	nsd
PORTVERSION=	3.2.21
CATEGORIES=	dns ipv6
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/nsd/	\
		ftp://ftp.rhnet.is/pub/nsd/
PKGNAMESUFFIX=	3

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Authoritative only non-recursive name server

LICENSE=	BSD3CLAUSE

CONFLICTS=	nsd-[0-2]* nsd-4*

DEPRECATED=		NSD 3 is EOL, please upgrade to NSD 4 in dns/nsd
EXPIRATION_DATE=	2016-05-20

USE_RC_SUBR=	nsd

NSDUSER?=	bind
NSDGROUP?=	bind
NSDLSDIR=	/var
NSDDBDIR=	/var/db/nsd
NSDRUNDIR=	/var/run/nsd
NSDMAX_IPS?=	512

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-user=${NSDUSER} \
		--with-configdir=${PREFIX}/etc/nsd \
		--localstatedir=${NSDLSDIR} \
		--with-dbfile=${NSDDBDIR}/nsd.db \
		--with-pidfile=${NSDRUNDIR}/nsd.pid

PLIST_SUB=	NSDUSER=${NSDUSER} \
		NSDGROUP=${NSDGROUP} \
		NSDDBDIR=${NSDDBDIR} \
		NSDRUNDIR=${NSDRUNDIR}

USE_OPENSSL=	yes

PORTDOCS=	CREDITS ChangeLog LICENSE NSD-DATABASE NSD-DIFFFILE \
		NSD-FOR-BIND-USERS README README.icc RELNOTES \
		REQUIREMENTS TESTPLAN TODO UPGRADING coding-style \
		differences.tex

OPTIONS_DEFINE=	ROOT_SERVER LARGEFILE IPV6 BIND8_STATS ZONE_STATS CHECKING \
		MINRESPSIZE NSEC3 NSEC3PREHASH MMAP MAXIPS DOCS RRL
OPTIONS_DEFAULT=	LARGEFILE IPV6 NSEC3 NSEC3PREHASH MINRESPSIZE

ROOT_SERVER_DESC=	Configure as a root server
LARGEFILE_DESC=		Largefile support
BIND8_STATS_DESC=	BIND8-like NSTATS & XSTATS
ZONE_STATS_DESC=	Per-zone BIND8 stats
CHECKING_DESC=		Internal run-time checks
NSEC3_DESC=		NSEC3 support
NSEC3PREHASH_DESC=	Full NSEC3 pre-hashing
MINRESPSIZE_DESC=	Minimial response sizing
MMAP_DESC=		Use mmap instead of malloc (experimental)
MAXIPS_DESC=		Raise max-ips from 8 to ${NSDMAX_IPS}
RRL_DESC=		Response Rate Limiting

ROOT_SERVER_CONFIGURE_ENABLE=	root-server
LARGEFILE_CONFIGURE_ENABLE=	largefile
IPV6_CONFIGURE_ENABLE=		ipv6
BIND8_STATS_CONFIGURE_ON=	--enable-bind8-stats
CHECKING_CONFIGURE_ENABLE=	checking
NSEC3_CONFIGURE_ENABLE=		nsec3
MINRESPSIZE_CONFIGURE_ENABLE=	minimal-responses
NSEC3PREHASH_CONFIGURE_ENABLE=	full-prehash
MMAP_CONFIGURE_ENABLE=		mmap
MAXIPS_CONFIGURE_ON=		--with-max-ips=${NSDMAX_IPS}
RRL_CONFIGURE_ENABLE=		ratelimit
ZONE_STATS_CONFIGURE_ENABLE=	zone-stats
ZONE_STATS_IMPLIES=		BIND8_STATS

post-install:
	${INSTALL_DATA} ${WRKSRC}/nsd.conf.sample \
		${STAGEDIR}${PREFIX}/etc/nsd/nsd.conf.sample
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/nsd \
		${STAGEDIR}${PREFIX}/sbin/nsd-checkconf \
		${STAGEDIR}${PREFIX}/sbin/nsd-notify \
		${STAGEDIR}${PREFIX}/sbin/nsd-patch \
		${STAGEDIR}${PREFIX}/sbin/nsd-xfer \
		${STAGEDIR}${PREFIX}/sbin/zonec

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
