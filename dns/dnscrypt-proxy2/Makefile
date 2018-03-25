# $FreeBSD$

PORTNAME=	dnscrypt-proxy
PORTVERSION=	2.0.7
CATEGORIES=	dns security
PKGNAMESUFFIX=	2

MAINTAINER=	egypcio@googlemail.com
COMMENT=	Flexible DNS proxy with support for encrypted protocols

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go
RUN_DEPENDS=	ca_root_nss>=3.35:security/ca_root_nss

USE_RC_SUBR=	${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	jedisct1

USERS=		_dnscrypt-proxy
GROUPS=		_dnscrypt-proxy

PORTDOCS=	${WRKSRC}/README.*
PORTEXAMPLES=	${WRKSRC}/${PORTNAME}/example*

CONFLICTS_INSTALL=	dnscrypt-proxy

OPTIONS_DEFINE=	DOCS EXAMPLES

do-build:
	${RLN} ${WRKSRC}/vendor ${WRKSRC}/src
	cd ${WRKSRC}/${PORTNAME} && \
		${SETENV} ${MAKE_ENV} ${BUILD_ENV} GOPATH=${WRKSRC} \
		go build -ldflags "-s -w" -o ${WRKDIR}/sbin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/sbin/${PORTNAME} ${STAGEDIR}${LOCALBASE}/sbin

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

post-install:
	# After install examples because of the priv drop issue with Go
	@${REINPLACE_CMD} -e \
		"s#\['127.0.0.1:53', '\[::1\]:53'\]#\['127.0.0.1:5353'\]#" \
		${WRKSRC}/${PORTNAME}/example-${PORTNAME}.toml
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/example-${PORTNAME}.toml \
		${STAGEDIR}${LOCALBASE}/etc/${PORTNAME}.toml.sample

.include <bsd.port.mk>
