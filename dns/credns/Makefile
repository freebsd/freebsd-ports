# New ports collection makefile for:	credns
# Date created:	9 July 2012
# Whom:		jaap
#
# $FreeBSD$
#

PORTNAME=	credns
PORTVERSION=	0.2.10
CATEGORIES=	dns security
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/credns/

MAINTAINER=	jaap@NLnetLab.nl
COMMENT=	A verifier performing validation in the DNS notify/transfer-chain

USE_RC_SUBR=	credns

CREDNSUSER?=	bind
CREDNSGROUP?=	bind
CREDNSLSDIR=	/var
CREDNSDBDIR=	/var/db/nsd
CREDNSRUNDIR=	/var/run/nsd
NSDMAX_IPS?=	512

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-user=${CREDNSUSER} \
		--localstatedir=${CREDNSLSDIR} \
		--with-dbfile=${CREDNSDBDIR}/nsd.db \
		--with-pidfile=${CREDNSRUNDIR}/nsd.pid

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST+=	CREDNSUSER=${CREDNSUSER} \
		CREDNSGROUP=${CREDNSGROUP} \
		CREDNSDBDIR=${CREDNSDBDIR} \
		CREDNSRUNDIR=${CREDNSRUNDIR}

USE_OPENSSL=	yes

MAN5=		credns.conf.5
MAN8=		credns-notify.8 credns-checkconf.8 credns-patch.8 \
		credns-xfer.8 credns.8 crednsc.8

PORTDOCS=	CREDITS ChangeLog LICENSE NSD-DATABASE NSD-DIFFFILE \
		NSD-CREDNS-MODS NSD-FOR-BIND-USERS NSD-README README \
		README.icc README.svn RELNOTES REQUIREMENTS TESTPLAN \
		TODO UPGRADING coding-style differences.pdf differences.tex

OPTIONS=	ROOT_SERVER	"Dnssexy as proxy for a (local) root" Off \
		IPV6		"Enable IPv6 support" On \
		CHECKING	"Enable internal runtime checks" Off \
		MMAP		"Use mmap instead of malloc(experimental)" Off \
		MAXIPS		"Raise max-ips from 8 to ${NSDMAX_IPS}" Off

.include <bsd.port.pre.mk>

.if defined(WITH_ROOT_SERVER)
CONFIGURE_ARGS+=	--enable-root-server
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(WITH_CHECKING)
CONFIGURE_ARGS+=	--enable-checking
.endif

.if defined(WITH_MMAP)
CONFIGURE_ARGS+=	--enable-mmap
.endif

.if defined(WITH_MAXIPS)
CONFIGURE_ARGS+=	--with-max-ips=${NSDMAX_IPS}
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/credns.conf.sample \
		${PREFIX}/etc/credns/credns.conf.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}/${f}
.endfor
.endif
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
