PORTNAME=	etcd
DISTVERSIONPREFIX=	v
DISTVERSION=	3.6.0-rc.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://raw.githubusercontent.com/etcd-io/${PORTNAME}/${DISTVERSIONFULL}/:gomod
PKGNAMEPREFIX=	coreos-
PKGNAMESUFFIX=	36
DISTFILES=	go.mod:gomod \
		api/go.mod:gomod \
		pkg/go.mod:gomod \
		client/pkg/go.mod:gomod \
		client/v3/go.mod:gomod \
		etcdctl/go.mod:gomod \
		etcdutl/go.mod:gomod \
		server/go.mod:gomod \
		tests/go.mod:gomod

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Highly-available key value store and service discovery
WWW=		https://etcd.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:1.23,modules
USE_GITHUB=	yes
GH_ACCOUNT=	etcd-io
GO_MODULE=	go.etcd.io/etcd/v3
GO_MOD_DIST=	github
GO_TARGET=	./etcdctl ./etcdutl ./server

CONFLICTS_INSTALL=	coreos-etcd[0-9][0-9]

PLIST_FILES=	bin/etcd \
		bin/etcdctl \
		bin/etcdutl

# This target is based on the post-extract target from Uses/go.mk
post-extract:
.for gt in ${GO_TARGET:T}
	@${ECHO_MSG} "===> Tidying ${GO_MODNAME} dependencies";
	@(cd ${GO_WRKSRC}/${gt}; ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=${GO_MODCACHE} ${GO_CMD} mod tidy -e)
	@${ECHO_MSG} "===> Vendoring ${GO_MODNAME} dependencies";
	@(cd ${GO_WRKSRC}/${gt}; ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=${GO_MODCACHE} ${GO_CMD} mod vendor -e)
.endfor

# This target is based on the do-build target from Uses/go.mk.
do-build:
.for gt in ${GO_TARGET:T}
	(cd ${GO_WRKSRC}/${gt}; \
	for t in ${gt}; do \
		out=$$(${BASENAME} $$(${ECHO_CMD} $${t} | \
			${SED} -Ee 's/^[^:]*:([^:]+).*$$/\1/' -e 's/^\.$$/${PORTNAME}/')); \
		pkg=$$(${ECHO_CMD} $${t} | \
			${SED} -Ee 's/^([^:]*).*$$/\1/' -e 's/^${PORTNAME}$$/./'); \
		${ECHO_MSG} "===>  Building $${out} from $${pkg}"; \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOMAXPROCS=${MAKE_JOBS_NUMBER} GOPROXY=off ${GO_CMD} build ${GO_BUILDFLAGS} \
			-o ${GO_WRKDIR_BIN}/$${out} \
			.; \
	done)
.endfor

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/server ${STAGEDIR}${PREFIX}/bin/etcd

.include <bsd.port.mk>
