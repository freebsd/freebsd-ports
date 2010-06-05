# New ports collection makefile for:	nsd2
# Date created:				16 October 2006
# Whom:					oli@isnic.is
#
# $FreeBSD$
#

PORTNAME=	nsd
PORTVERSION=	2.3.7
PORTREVISION=	2
CATEGORIES=	dns ipv6
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/nsd/	\
		ftp://ftp.rhnet.is/pub/nsd/

MAINTAINER=	jaap@bartok.nlnetlabs.nl
COMMENT=	An authoritative only non-recursive name server

CONFLICTS=	nsd-[3-9]*

USE_RC_SUBR=	nsd.sh
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-user=${NSDUSER} \
		--with-configdir=${NSDDIR} \
		--with-pidfile=/var/run/nsd.pid \
		--with-dbfile=${NSDDBFILE} \
		--with-libwrap

OPTIONS=	ROOT_SERVER	"Configure NSD as a root server" Off \
		IPV6		"Enable IPv6 support" On \
		DNSSEC		"Enable DNSSEC" On \
		AXFR		"Enable AXFR" On \
		BIND8_STATS	"Enable BIND8 like NSTATS & XSTATS" Off \
		NSID		"Enable NSID support" Off \
		PLUGINS		"Enable plugin support" Off \
		CHECKING	"Enable internal runtime checks" Off \
		TSIG		"Enable TSIG support" On \
		MMAP		"Load database using mmap(2)" Off

MAN8=		nsd.8 nsdc.8 zonec.8 nsd-notify.8 nsd-xfer.8

PORTDOCS=	CREDITS LICENSE NSD-DATABASE README README.icc \
		RELNOTES REQUIREMENTS TODO

NSDUSER?=	bind
NSDDIR?=	${PREFIX}/etc/nsd
NSDDBFILE?=	/var/db/nsd.database

SUB_LIST=	NSDUSER="${NSDUSER}" \
		NSDDIR="${NSDDIR}" \
		NSDDBFILE="${NSDDBFILE}"

LATEST_LINK=	nsd2

.include <bsd.port.pre.mk>

.if defined(WITH_ROOT_SERVER)
CONFIGURE_ARGS+=	--enable-root-server
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(WITHOUT_DNSSEC)
CONFIGURE_ARGS+=	--disable-dnssec
.endif

.if defined(WITHOUT_AXFR)
CONFIGURE_ARGS+=	--disable-axfr
.endif

.if defined(WITH_BIND8_STATS)
CONFIGURE_ARGS+=	--enable-bind8-stats
.endif

.if defined(WITH_NSID)
CONFIGURE_ARGS+=	--enable-nsid
.endif

.if defined(WITH_PLUGINS)
CONFIGURE_ARGS+=	--enable-plugins
.endif

.if defined(WITH_CHECKING)
CONFIGURE_ARGS+=	--enable-checking
.endif

.if defined(WITHOUT_TSIG)
CONFIGURE_ARGS+=	--disable-tsig
.endif

.if defined(WITH_MMAP)
CONFIGURE_ARGS+=	--enable-mmap
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/nsd.zones.sample ${NSDDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/nsd.sh ${PREFIX}/etc/rc.d
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/${f}
.endfor
.endif
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
