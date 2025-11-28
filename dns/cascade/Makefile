PORTNAME=	cascade
DISTVERSION=	0.1.0-RC1
PORTREVISION=	4
CATEGORIES=	dns net
PKGNAMESUFFIX=	-dns

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Friendly DNSSEC signing solution
WWW=		https://github.com/NLnetLabs/cascade

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	dnst:dns/dnst

USES=		cargo cpe ssl
CPE_VENDOR=	nlnetlabs
USE_GITHUB=	yes
GH_ACCOUNT=	NLnetLabs
GH_TAGNAME=	07ba70c2e
USE_RC_SUBR=	${PORTNAME}

SUB_LIST=	USERS=${USERS} \
		GROUPS=${GROUPS} \
		DBDIR=${DBDIR}

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PLIST_SUB+=	USERS=${USERS} \
		GROUPS=${GROUPS}

DBDIR=		/var/db/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|%%ETCDIR%%|${ETCDIR}|g; \
		s|%%DBDIR%%|${DBDIR}|g; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/etc/config.template.toml

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/policy.template.toml ${STAGEDIR}${ETCDIR}/policy.toml.sample
	${INSTALL_DATA} ${WRKSRC}/etc/config.template.toml ${STAGEDIR}${ETCDIR}/config.toml.sample

.include <bsd.port.mk>
