# New ports collection makefile for:	nsd
# Date created:				08 August 2002
# Whom:					alexis
#
# $FreeBSD$
#

PORTNAME=	nsd
PORTVERSION=	3.2.3
CATEGORIES=	dns ipv6
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/nsd/	\
		ftp://ftp.rhnet.is/pub/nsd/

MAINTAINER=	osvaldsson@icelandic.net
COMMENT=	An authoritative only non-recursive name server

CONFLICTS=	nsd-[0-2]*

USE_RC_SUBR=	nsd

NSDUSER?=	bind
NSD_LSD=	/var
NSDMAX_INT?=	512

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-user=${NSDUSER} \
		--with-configdir=${PREFIX}/etc/nsd \
		--localstatedir=${NSD_LSD}

USE_OPENSSL=	yes

MAN5=	nsd.conf.5
MAN8=	nsd.8 nsdc.8 zonec.8 nsd-checkconf.8 nsd-notify.8 nsd-patch.8 \
	nsd-xfer.8

PORTDOCS=	CREDITS ChangeLog LICENSE NSD-DATABASE NSD-DIFFFILE \
		NSD-FOR-BIND-USERS README README.icc RELNOTES \
		REQUIREMENTS TESTPLAN TODO UPGRADING coding-style \
		differences.tex

OPTIONS=	ROOT_SERVER	"Configure NSD as a root server" Off \
		LARGEFILE	"Enable support for large files" On \
		IPV6		"Enable IPv6 support" On \
		DNSSEC		"Enable DNSSEC" On \
		BIND8_STATS	"Enable BIND8 like NSTATS & XSTATS" Off \
		CHECKING	"Enable internal runtime checks" Off \
		TSIG		"Enable TSIG support" On \
		NSEC3		"Enable NSEC3 support" On \
		NSID		"Enable NSID support" Off \
		MAXINT		"Raise max_interfaces from 8 to ${NSDMAX_INT}" Off

.include <bsd.port.pre.mk>

.if defined(WITH_ROOT_SERVER)
CONFIGURE_ARGS+=	--enable-root-server
.endif

.if defined(WITHOUT_LARGEFILE)
CONFIGURE_ARGS+=	--disable-largefile
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(WITHOUT_DNSSEC)
CONFIGURE_ARGS+=	--disable-dnssec
.endif

.if defined(WITH_BIND8_STATS)
CONFIGURE_ARGS+=	--enable-bind8-stats
.endif

.if defined(WITH_CHECKING)
CONFIGURE_ARGS+=	--enable-checking
.endif

.if defined(WITHOUT_TSIG)
CONFIGURE_ARGS+=	--disable-tsig
.endif

.if defined(WITHOUT_NSEC3)
CONFIGURE_ARGS+=	--disable-nsec3
.endif

.if defined(WITH_NSID)
CONFIGURE_ARGS+=	--enable-nsid
.endif

.if defined(WITH_MAXINT)
CONFIGURE_ARGS+=	--with-max_interfaces=${NSDMAX_INT}
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
		${PREFIX}/etc/nsd/nsd.conf.sample

.if exists(${PREFIX}/etc/nsd/nsd.conf)
	@${ECHO_MSG} "Upgrading to new ixfr.db format if needed"
	${PREFIX}/sbin/nsdc patch
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}/${f}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
