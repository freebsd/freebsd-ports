# New ports collection makefile for:	nsd
# Date created:				08 August 2002
# Whom:					alexis
#
# $FreeBSD$
#

PORTNAME=	nsd
PORTVERSION=	2.1.2
CATEGORIES=	dns ipv6
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/nsd/	\
		ftp://ftp.rhnet.is/pub/nsd/

MAINTAINER=	oli@isnic.is
COMMENT=	An authoritative only non-recursive high performance name server

USE_RC_SUBR=	yes

NSDUSER?=	bind
NSDDIR?=	${PREFIX}/etc/nsd
NSDDBFILE?=	/var/db/nsd.database
NSDXFER?=	/usr/libexec/named-xfer

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-user=${NSDUSER} \
		--with-configdir=${NSDDIR} \
		--with-pidfile=/var/run/nsd.pid \
		--with-dbfile=${NSDDBFILE} \
		--with-namedxfer=${NSDXFER} \
		--with-libwrap

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(WITHOUT_AXFR)
CONFIGURE_ARGS+=	--disable-axfr
.endif

.if defined(WITH_PLUGINS)
CONFIGURE_ARGS+=	--enable-plugins
.endif

.if defined(WITH_BIND8_STATS)
CONFIGURE_ARGS+=	--enable-bind8-stats
.endif

.if defined(WITH_DNSSEC)
CONFIGURE_ARGS+=	--enable-dnssec
.endif

.if defined(WITH_ROOT_SERVER)
CONFIGURE_ARGS+=	--enable-root-server
.endif

.if defined(WITH_MMAP)
CONFIGURE_ARGS+=	--enable-mmap
.endif

SED_SCRIPT=	-e 's,%%NSDUSER%%,${NSDUSER},g' \
		-e 's,%%NSDDIR%%,${NSDDIR},g' \
		-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%RC_SUBR%%,${RC_SUBR},g'

MAN8=	nsd.8 zonec.8 nsdc.8 nsd-notify.8

PORTDOCS=	README RELNOTES CREDITS DIFFERENCES REQUIREMENTS

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "nsd has the following tunables:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITHOUT_IPV6		Disables IPv6 support"
	@${ECHO_MSG} "  WITHOUT_AXFR		Disables AXFR"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITH_PLUGINS		Enable plugin support"
	@${ECHO_MSG} "  WITH_BIND8_STATS	Enables BIND8 like NSTATS & XSTATS"
	@${ECHO_MSG} "  WITH_DNSSEC		Enable experimental DNSSEC support"
	@${ECHO_MSG} "			according to the latest drafts"
	@${ECHO_MSG} "  WITH_ROOT_SERVER	Configure NSD as a root server"
	@${ECHO_MSG} "  WITH_MMAP		Configure NSD to load the database using mmap(2)"
	@${ECHO_MSG} ""

pre-build:

post-install:
	${SED} ${SED_SCRIPT} < ${FILESDIR}/nsd.sh.tmpl >${WRKDIR}/nsd.sh
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	${INSTALL_DATA} ${WRKSRC}/nsd.zones.sample \
		${PREFIX}/etc/nsd/nsd.zones.sample
	${INSTALL_SCRIPT} ${WRKDIR}/nsd.sh ${PREFIX}/etc/rc.d/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
