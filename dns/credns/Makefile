# Created by: jaap
# $FreeBSD$

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

OPTIONS_DEFINE=	ROOT_SERVER IPV6 CHECKING MMAP MAXIPS DOCS
ROOT_SERVER_DESC=	Dnssexy as proxy for a (local) root
CHECKING_DESC=	Internal runtime checks
MMAP_DESC=	Use mmap instead of malloc(experimental)
MAXIPS_DESC=	Raise max-ips from 8 to ${NSDMAX_IPS}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MROOT_SERVER}
CONFIGURE_ARGS+=	--enable-root-server
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MCHECKING}
CONFIGURE_ARGS+=	--enable-checking
.endif

.if ${PORT_OPTIONS:MMMAP}
CONFIGURE_ARGS+=	--enable-mmap
.endif

.if ${PORT_OPTIONS:MMAXIPS}
CONFIGURE_ARGS+=	--with-max-ips=${NSDMAX_IPS}
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/credns.conf.sample \
		${PREFIX}/etc/credns/credns.conf.sample
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}/${f}
.endfor
.endif
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
