# Created by: alexis
# $FreeBSD$

PORTNAME=	nsd
PORTVERSION=	4.0.3
CATEGORIES=	dns ipv6
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/nsd/	\
		ftp://ftp.rhnet.is/pub/nsd/

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Authoritative only non-recursive name server

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

PLIST_SUB=	NSDUSER=${NSDUSER} \
		NSDGROUP=${NSDGROUP} \
		NSDDBDIR=${NSDDBDIR} \
		NSDRUNDIR=${NSDRUNDIR}

USE_OPENSSL=	yes

PORTDOCS=	CREDITS ChangeLog LICENSE NSD-DATABASE NSD-DIFFFILE \
		NSD-4-features NSD-FOR-BIND-USERS README README.icc RELNOTES \
		REQUIREMENTS TESTPLAN TODO UPGRADING coding-style \
		differences.tex

OPTIONS_DEFINE=		ROOT_SERVER LARGEFILE IPV6 BIND8_STATS CHECKING \
		MINRESPSIZE NSEC3 NSEC3PREHASH MMAP MAXIPS DOCS RRL EUI_RRTYPES \
		RECVMMSG
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
RECVMMSG_DESC=		Enable use of recvmmsg and sendmmsg

LIB_DEPENDS+=	libevent-1.4.so:${PORTSDIR}/devel/libevent

ROOT_SERVER_CONFIGURE_ENABLE=	root-server
LARGEFILE_CONFIGURE_ENABLE=	largefile
IPV6_CONFIGURE_ENABLE=		ipv6
BIND8_STATS_CONFIGURE_ENABLE=	bind8-stats
CHECKING_CONFIGURE_ENABLE=	checking
NSEC3_CONFIGURE_ENABLE=		nsec3
MINRESPSIZE_CONFIGURE_ENABLE=	minimal-responses
NSEC3PREHASH_CONFIGURE_ENABLE=	full-prehash
MMAP_CONFIGURE_ENABLE=		mmap
MAXIPS_CONFIGURE_ON=		--with-max-ips=${NSDMAX_IPS}
RRL_CONFIGURE_ENABLE=		ratelimit
EUI_RRTYPES_CONFIGURE_ENABLE=	draft-rrtypes
RECVMMSG_CONFIGURE_ENABLE=	enable-recvmmsg

post-install:
	${INSTALL_DATA} ${WRKSRC}/nsd.conf.sample \
		${STAGEDIR}${PREFIX}/etc/nsd/nsd.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
