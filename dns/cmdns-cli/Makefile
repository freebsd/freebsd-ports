PORTNAME=	cmdns-cli
PORTVERSION=	1.3.0
CATEGORIES=	dns
MASTER_SITES=	https://codeberg.org/DNS-OARC/${PORTNAME}/archive/v${PORTVERSION}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Check-My-DNS CLI client
WWW=		https://www.dns-oarc.net/oarc/services/cmdns

LICENSE=	MIT

USES=		go
USE_GITHUB=	yes
GH_TUPLE=	golang:mod:v0.31.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.48.0:golang_net/vendor/golang.org/x/net \
		golang:sync:v0.19.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.39.0:golang_sys/vendor/golang.org/x/sys \
		golang:tools:v0.40.0:golang_tools/vendor/golang.org/x/tools \
		gorilla:websocket:v1.5.3:gorilla_websocket/vendor/github.com/gorilla/websocket \
		miekg:dns:v1.1.72:miekg_dns/vendor/github.com/miekg/dns

PLIST_FILES=	bin/cmdns-cli

post-extract:
		${MV} ${WRKDIR}/${PORTNAME}/* ${WRKDIR}/${PORTNAME}-${PORTVERSION}/

.include <bsd.port.mk>
