PORTNAME=	cayley
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.7
CATEGORIES=	databases

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open-source graph database
WWW=		https://github.com/cayleygraph/cayley

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	gopkg.in/mgo.v2/bson/json.go:320:7: constant 9007199254740992 overflows int

USES=		go:modules

#USE_GITHUB=	yes
#GH_ACCOUNT=	${PORTNAME}graph
#GH_TUPLE=	\
		AndreasBriese:bbloom:e2d15f34fcf9:andreasbriese_bbloom/vendor/github.com/AndreasBriese/bbloom \
		Azure:go-ansiterm:d6e3b3328b78:azure_go_ansiterm/vendor/github.com/Azure/go-ansiterm \
		Microsoft:go-winio:v0.4.12:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		Nvveen:Gotty:cd527374f1e5:nvveen_gotty/vendor/github.com/Nvveen/Gotty \
		badgerodon:peg:9e5f7f4d07ca:badgerodon_peg/vendor/github.com/badgerodon/peg \
		beorn7:perks:v1.0.0:beorn7_perks/vendor/github.com/beorn7/perks \
		boltdb:bolt:v1.3.1:boltdb_bolt/vendor/github.com/boltdb/bolt \
		cayleygraph:quad:v1.1.0:cayleygraph_quad/vendor/github.com/cayleygraph/quad \
		cenkalti:backoff:v2.1.1:cenkalti_backoff/vendor/github.com/cenkalti/backoff \
		containerd:continuity:aaeac12a7ffc:containerd_continuity/vendor/github.com/containerd/continuity \
		coreos:bbolt:v1.3.3:coreos_bbolt/vendor/github.com/coreos/bbolt \
		cznic:mathutil:1447ad269d64:cznic_mathutil/vendor/github.com/cznic/mathutil \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dennwc:base:v1.0.0:dennwc_base/vendor/github.com/dennwc/base \
		dennwc:graphql:12cfed44bc5d:dennwc_graphql/vendor/github.com/dennwc/graphql \
		dgraph-io:badger:v1.5.5:dgraph_io_badger/vendor/github.com/dgraph-io/badger \
		dgryski:go-farm:6a90982ecee2:dgryski_go_farm/vendor/github.com/dgryski/go-farm \
		dlclark:regexp2:v1.1.4:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		docker:go-connections:v0.4.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-units:v0.4.0:docker_go_units/vendor/github.com/docker/go-units \
		dop251:goja:6d5bf35058fa:dop251_goja/vendor/github.com/dop251/goja \
		flimzy:kivik:v1.8.1:flimzy_kivik/vendor/github.com/flimzy/kivik \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		fsouza:go-dockerclient:v1.2.2:fsouza_go_dockerclient/vendor/github.com/fsouza/go-dockerclient \
		go-kivik:couchdb:v1.8.1:go_kivik_couchdb/vendor/github.com/go-kivik/couchdb \
		go-kivik:kivik:v1.8.1:go_kivik_kivik \
		go-kivik:pouchdb:v1.3.5:go_kivik_pouchdb/vendor/github.com/go-kivik/pouchdb \
		go-sourcemap:sourcemap:v2.1.2:go_sourcemap_sourcemap/vendor/github.com/go-sourcemap/sourcemap \
		go-sql-driver:mysql:v1.4.1:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-stack:stack:v1.8.0:go_stack_stack/vendor/github.com/go-stack/stack \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobuffalo:envy:v1.7.1:gobuffalo_envy/vendor/github.com/gobuffalo/envy \
		gobuffalo:logger:v1.0.1:gobuffalo_logger/vendor/github.com/gobuffalo/logger \
		gobuffalo:packd:v0.3.0:gobuffalo_packd/vendor/github.com/gobuffalo/packd \
		gobuffalo:packr:v2.7.1:gobuffalo_packr_v2/vendor/github.com/gobuffalo/packr \
		gogo:protobuf:v1.3.0:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.1:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:34f69633bfdc:golang_crypto/vendor/golang.org/x/crypto \
		golang:glog:23def4e6c14b:golang_glog/vendor/github.com/golang/glog \
		golang:net:da137c7871d7:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.3.1:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:cd5d95a43a6e:golang_sync/vendor/golang.org/x/sync \
		golang:sys:06d7bd2c5f4f:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:tools:0337d82405ff:golang_tools/vendor/golang.org/x/tools \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		gopherjs:gopherjs:3e4dfb77656c:gopherjs_gopherjs/vendor/github.com/gopherjs/gopherjs \
		gopherjs:jsbuiltin:50091555e127:gopherjs_jsbuiltin/vendor/github.com/gopherjs/jsbuiltin \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hidal-go:hidalgo:42e03f3b5eaa:hidal_go_hidalgo/vendor/github.com/hidal-go/hidalgo \
		imdario:mergo:v0.3.7:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jackc:pgx:v3.3.0:jackc_pgx/vendor/github.com/jackc/pgx \
		joho:godotenv:v1.3.0:joho_godotenv/vendor/github.com/joho/godotenv \
		julienschmidt:httprouter:v1.2.0:julienschmidt_httprouter/vendor/github.com/julienschmidt/httprouter \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		lib:pq:v1.1.1:lib_pq/vendor/github.com/lib/pq \
		linkeddata:gojsonld:4f5db6791326:linkeddata_gojsonld/vendor/github.com/linkeddata/gojsonld \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		mailru:easyjson:b2ccc519800e:mailru_easyjson/vendor/github.com/mailru/easyjson \
		mattn:go-sqlite3:v1.10.0:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		moby:moby:a422774e593b:moby_moby/vendor/github.com/docker/docker \
		mongodb:mongo-go-driver:v1.0.4:mongodb_mongo_go_driver/vendor/go.mongodb.org/mongo-driver \
		olivere:elastic:v5.0.81:olivere_elastic/vendor/gopkg.in/olivere/elastic.v5 \
		opencontainers:go-digest:v1.0.0-rc1:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.0.1:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		opencontainers:runc:v0.1.1:opencontainers_runc/vendor/github.com/opencontainers/runc \
		ory:dockertest:v3.3.4:ory_dockertest/vendor/github.com/ory/dockertest \
		pborman:uuid:v1.2.0:pborman_uuid/vendor/github.com/pborman/uuid \
		pelletier:go-toml:v1.4.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		peterh:liner:88609521dc4b:peterh_liner/vendor/github.com/peterh/liner \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v0.9.3:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:fd36f4220a90:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.4.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:5867b95ac084:prometheus_procfs/vendor/github.com/prometheus/procfs \
		rogpeppe:go-internal:v1.5.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		russross:blackfriday:v1.5.2:russross_blackfriday/vendor/github.com/russross/blackfriday \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:afero:v1.2.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v0.0.5:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.4.0:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		syndtr:goleveldb:v1.0.0:syndtr_goleveldb/vendor/github.com/syndtr/goleveldb \
		tylertreat:BoomFilters:611b3dbe80e8:tylertreat_boomfilters/vendor/github.com/tylertreat/BoomFilters \
		xdg:scram:7eeb5667e42c:xdg_scram/vendor/github.com/xdg/scram \
		xdg:stringprep:v1.0.0:xdg_stringprep/vendor/github.com/xdg/stringprep

GO_MODULE=	github.com/cayleygraph/cayley
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X github.com/${GH_ACCOUNT}graph/${GH_PROJECT}/version.GitHash=${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
