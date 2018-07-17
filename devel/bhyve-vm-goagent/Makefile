# $FreeBSD$

PORTNAME=	bhyve-vm-goagent
PORTVERSION=	1.0
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	devel sysutils

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Agent developed in Go that runs inside guest vm

LICENSE=	BSD2CLAUSE

BROKEN=		attempts to download dependencies during build
DEPRECATED=	Broken for more than 5 months
EXPIRATION_DATE=	2018-08-20

ONLY_FOR_ARCHS=	amd64 i386

BUILD_DEPENDS=	git:devel/git

USES=		go
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	freenas
GH_TAGNAME=	a640870c90752e01af30e394ce7c8157f4371a1b
GH_TUPLE=	gorilla:websocket:v1.2.0:websocket/src/github.com/gorilla/websocket \
		shirou:gopsutil:v2.17.12:gopsutil/src/github.com/shirou/gopsutil

MAKE_ENV=	GOPATH=${WRKSRC} GOROOT=${LOCALBASE}/go

PLIST_FILES=	sbin/bhyve-vm-goagent

do-build:
	cd ${WRKSRC} ; make deps ; make build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-freebsd-${ARCH}-1.0-RELEASE \
		${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}

.include <bsd.port.mk>
