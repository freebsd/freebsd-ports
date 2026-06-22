PORTNAME=	encrypted-dns-server
DISTVERSION=	0.9.21
CATEGORIES=	dns

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	68ac68fbbb17e4fa0c258f272ed10b6b8d81e32e.patch:-p1

MAINTAINER=	ea@uoga.net
COMMENT=	High-performance, zero maintenance encrypted DNS proxy
WWW=		https://github.com/jedisct1/encrypted-dns-server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	jedisct1
USE_RC_SUBR=	encrypted_dns

CARGO_FEATURES=	--no-default-features

USERS=		_encrypted-dns
GROUPS=		_encrypted-dns

PLIST_FILES=	"@dir(${USERS},${GROUPS},0755) ${ETCDIR}" \
		"@sample ${ETCDIR}/encrypted-dns.toml.sample" \
		"@sample ${ETCDIR}/undelegated.txt.sample" \
		bin/encrypted-dns
PLIST_SUB=	GROUPS=${GROUPS} \
		USERS=${USERS}

OPTIONS_DEFINE=		METRICS
OPTIONS_DEFAULT=	METRICS

METRICS_DESC=	Enable Prometheus metrics
METRICS_VARS=	CARGO_FEATURES+=metrics

post-extract:
	${MV} ${WRKSRC}/undelegated.txt \
		${WRKSRC}/undelegated.txt.sample

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/encrypted-dns.toml.sample \
		${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/undelegated.txt.sample \
		${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
