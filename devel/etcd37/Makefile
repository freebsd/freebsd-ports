PORTNAME=	etcd
DISTVERSIONPREFIX=	v
DISTVERSION=	3.7.1
CATEGORIES=	devel
MASTER_SITES=	https://raw.githubusercontent.com/etcd-io/${PORTNAME}/${DISTVERSIONFULL}/:gomod
PKGNAMEPREFIX=	coreos-
PKGNAMESUFFIX=	${DISTVERSION:C/[.][0-9]+$//:S/.//}
DISTFILES=	go.mod:gomod \
		${_SUBMODS:S|$|/go.mod:gomod|}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Highly-available key value store and service discovery
WWW=		https://etcd.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	etcd-io
GO_MOD_DIST=	github
GO_MODULE=	go.etcd.io/etcd/v3
GO_TARGET=	./etcdctl ./etcdutl ./server:etcd

MAKE_ENV=	GOWORK=off

CONFLICTS_INSTALL=	coreos-etcd[0-9][0-9]

PLIST_FILES=	bin/etcd \
		bin/etcdctl \
		bin/etcdutl

_SUBMODS=	api pkg client/pkg client/v3 etcdctl etcdutl server tests

# This target is based on the post-extract target from Uses/go.mk
post-extract:
.for t in ${GO_TARGET:C/:.*//}
	@${ECHO_MSG} "===> Vendoring dependencies for ${t:T}"
	@cd ${GO_WRKSRC}/${t} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} \
		GOPROXY=${GO_MODCACHE} ${GO_CMD} mod tidy -e && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} \
		GOPROXY=${GO_MODCACHE} ${GO_CMD} mod vendor -e
.endfor

# This target is based on the do-build target from Uses/go.mk.
do-build:
.for t in ${GO_TARGET}
	@${ECHO_MSG} "===>  Building ${t:C/^.*://:T} from ${t:C/:.*//}"
	@cd ${GO_WRKSRC}/${t:C/:.*//} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} \
		GOMAXPROCS=${MAKE_JOBS_NUMBER} GOPROXY=off ${GO_CMD} build \
		${GO_BUILDFLAGS} -o ${GO_WRKDIR_BIN}/${t:C/^.*://:T} .
.endfor

.include <bsd.port.mk>
