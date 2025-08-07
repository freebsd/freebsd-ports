PORTNAME=	etcd
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.37
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://raw.githubusercontent.com/etcd-io/${PORTNAME}/${DISTVERSIONFULL}/:gomod
PKGNAMEPREFIX=	coreos-
PKGNAMESUFFIX=	34
DISTFILES=	go.mod:gomod

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Highly-available key value store and service discovery
WWW=		https://github.com/coreos/etcd

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:1.23,modules
USE_GITHUB=	yes
GH_ACCOUNT=	etcd-io
GO_MODULE=	go.etcd.io/etcd/v3
GO_MOD_DIST=	github
GO_TARGET=	./etcdctl .

CONFLICTS_INSTALL=	coreos-etcd[0-9][0-9]

PLIST_FILES=	bin/etcd \
		bin/etcdctl

# This target is based on the post-extract target from Uses/go.mk
post-extract:
.for gt in ${GO_TARGET:T}
	@${ECHO_MSG} "===> Tidying ${gt} dependencies";
	@(cd ${GO_WRKSRC}/${gt}; ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=${GO_MODCACHE} ${GO_CMD} mod tidy -e)
	@${ECHO_MSG} "===> Vendoring ${gt} dependencies";
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

.include <bsd.port.mk>
