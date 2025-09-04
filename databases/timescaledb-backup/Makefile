PORTNAME=	timescaledb-backup
DISTVERSION=	0.1.1
PORTREVISION=	29
CATEGORIES=	databases

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Tool for performing TimescaleDB backups across versions
WWW=		https://github.com/timescale/timescaledb-backup

LICENSE=	TSL
LICENSE_NAME=	Timescale License Agreement
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	timescale
GH_TUPLE=	Microsoft:go-winio:v0.4.11:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		Microsoft:hcsshim:v0.8.6:microsoft_hcsshim/vendor/github.com/Microsoft/hcsshim \
		cenkalti:backoff:v2.2.1:cenkalti_backoff/vendor/github.com/cenkalti/backoff \
		containerd:continuity:aaeac12a7ffc:containerd_continuity/vendor/github.com/containerd/continuity \
		docker:distribution:0d3efadf0154:docker_distribution/vendor/github.com/docker/distribution \
		docker:go-connections:v0.4.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-units:v0.3.3:docker_go_units/vendor/github.com/docker/go-units \
		gogo:protobuf:v1.2.0:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:crypto:0ec3e9974c59:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:74dc4d7220e7:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:112230192c58:golang_sync/vendor/golang.org/x/sync \
		golang:sys:c7b8b68b1456:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:xerrors:a985d3407aa7:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-genproto:c66870c02cf8:google_go_genproto/vendor/google.golang.org/genproto \
		grpc:grpc-go:v1.17.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		jackc:chunkreader:v2.0.1:jackc_chunkreader_v2/vendor/github.com/jackc/chunkreader/v2 \
		jackc:pgconn:v1.5.0:jackc_pgconn/vendor/github.com/jackc/pgconn \
		jackc:pgio:v1.0.0:jackc_pgio/vendor/github.com/jackc/pgio \
		jackc:pgpassfile:v1.0.0:jackc_pgpassfile/vendor/github.com/jackc/pgpassfile \
		jackc:pgproto3:v2.0.1:jackc_pgproto3_v2/vendor/github.com/jackc/pgproto3/v2 \
		jackc:pgservicefile:3430c5407db8:jackc_pgservicefile/vendor/github.com/jackc/pgservicefile \
		jackc:pgtype:v1.3.0:jackc_pgtype/vendor/github.com/jackc/pgtype \
		jackc:pgx:v4.6.0:jackc_pgx_v4/vendor/github.com/jackc/pgx/v4 \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		moby:moby:b20a14b54661:moby_moby/vendor/github.com/docker/docker \
		opencontainers:go-digest:v1.0.0-rc1:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.0.1:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		opencontainers:runc:v0.1.1:opencontainers_runc/vendor/github.com/opencontainers/runc \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		satori:go.uuid:v1.2.0:satori_go_uuid/vendor/github.com/satori/go.uuid \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		testcontainers:testcontainers-go:v0.3.1:testcontainers_testcontainers_go/vendor/github.com/testcontainers/testcontainers-go

GO_TARGET=	./cmd/ts-dump ./cmd/ts-restore

PLIST_FILES=	bin/ts-dump \
		bin/ts-restore

.include <bsd.port.mk>
