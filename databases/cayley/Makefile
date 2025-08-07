PORTNAME=	cayley
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.7
PORTREVISION=	19
CATEGORIES=	databases

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open-source graph database
WWW=		https://github.com/cayleygraph/cayley

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	gopkg.in/mgo.v2/bson/json.go:320:7: constant 9007199254740992 overflows int

USES=		go:modules
USE_GITHUB=	nodefault
GH_TUPLE=	golang:sys:v0.6.0:sys

GO_MODULE=	github.com/cayleygraph/cayley
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X github.com/${GH_ACCOUNT}graph/${GH_PROJECT}/version.GitHash=${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
