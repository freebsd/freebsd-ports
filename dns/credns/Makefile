# Created by: Jaap Akkerhuis <jaap@NLnetLabs.nl>
# $FreeBSD$

PORTNAME=	credns
PORTVERSION=	0.2.10
PORTREVISION=	2
CATEGORIES=	dns security
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/credns/

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Verifier performing validation in the DNS notify/transfer-chain

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_SSL=	openssl-devel

USE_RC_SUBR=	credns

USERS?=		bind
GROUPS?=	bind
CREDNSLSDIR=	/var
CREDNSDBDIR=	/var/db/nsd
CREDNSRUNDIR=	/var/run/nsd
NSDMAX_IPS?=	512

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-user=${CREDNSUSER} \
		--localstatedir=${CREDNSLSDIR} \
		--with-dbfile=${CREDNSDBDIR}/nsd.db \
		--with-pidfile=${CREDNSRUNDIR}/nsd.pid

PLIST_SUB=	CREDNSUSER=${USERS} \
		CREDNSGROUP=${GROUPS} \
		CREDNSDBDIR=${CREDNSDBDIR} \
		CREDNSRUNDIR=${CREDNSRUNDIR}

USES=		ssl

PORTDOCS=	*

OPTIONS_DEFINE=	ROOT_SERVER IPV6 CHECKING MMAP MAXIPS DOCS

ROOT_SERVER_DESC=	Credns as proxy for a (local) root
CHECKING_DESC=	Internal runtime checks
MMAP_DESC=	Use mmap() instead of malloc() (experimental)
MAXIPS_DESC=	Raise max-ips from 8 to ${NSDMAX_IPS}

ROOT_SERVER_CONFIGURE_ENABLE=	root-server
IPV6_CONFIGURE_ENABLE=		ipv6
CHECKING_CONFIGURE_ENABLE=	checking
MMAP_CONFIGURE_ENABLE=		mmap
MAXIPS_CONFIGURE_ON=		--with-max-ips=${NSDMAX_IPS}

post-install:
.for f in credns credns-checkconf credns-notify credns-patch credns-xfer
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/${f}
.endfor
	${INSTALL_DATA} ${WRKSRC}/credns.conf.sample \
		${STAGEDIR}${PREFIX}/etc/credns/credns.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
