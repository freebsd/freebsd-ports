# $FreeBSD$

PORTNAME=	cayley
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.5-2
DISTVERSIONSUFFIX=	-gcf576ba
CATEGORIES=	databases

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open-source graph database

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	gopkg.in/mgo.v2/bson/json.go:320:7: constant 9007199254740992 overflows int

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}graph
GH_TUPLE=	badgerodon:peg:9e5f7f4:peg/src/github.com/badgerodon/peg \
		boltdb:bolt:fd01fc7:bolt/src/github.com/boltdb/bolt \
		dennwc:graphql:12cfed4:graphql/src/github.com/dennwc/graphql \
		dlclark:regexp2:7632a26:regexp2/src/github.com/dlclark/regexp2 \
		dop251:goja:9183045:goja/src/github.com/dop251/goja \
		fsnotify:fsnotify:c282820:fsnotify/src/github.com/fsnotify/fsnotify \
		hashicorp:hcl:ef8a98b:hcl/src/github.com/hashicorp/hcl \
		go-kivik:couchdb:d811cc7:couchdb/src/github.com/go-kivik/couchdb \
		go-kivik:kivik:d2ef974:kivik/src/github.com/go-kivik/kivik \
		go-mgo:mgo:5466044:mgo/src/gopkg.in/mgo.v2 \
		go-sourcemap:sourcemap:b019cc3:sourcemap/src/github.com/go-sourcemap/sourcemap \
		go-sql-driver:mysql:d523deb:mysql/src/github.com/go-sql-driver/mysql \
		go-yaml:yaml:v2.2.1:yaml/src/gopkg.in/yaml.v2 \
		gogo:protobuf:30cf7ac:protobuf/src/github.com/gogo/protobuf \
		golang:glog:23def4e:glog/src/github.com/golang/glog \
		golang:snappy:2e65f85:snappy/src/github.com/golang/snappy \
		imdario:mergo:7045960:mergo/src/github.com/imdario/mergo \
		jackc:pgx:8707449:pgx/src/github.com/jackc/pgx \
		julienschmidt:httprouter:adbc77e:httprouter/src/github.com/julienschmidt/httprouter \
		lib:pq:90697d6:pq/src/github.com/lib/pq \
		linkeddata:gojsonld:4f5db67:gojsonld/src/github.com/linkeddata/gojsonld \
		magiconair:properties:c235336:properties/src/github.com/magiconair/properties \
		mailru:easyjson:9825584:easyjson/src/github.com/mailru/easyjson \
		mattn:go-runewidth:ce7b0b5:runewidth/src/github.com/mattn/go-runewidth \
		mitchellh:mapstructure:bb74f1d:mapstructure/src/github.com/mitchellh/mapstructure \
		olivere:elastic:dabcc5d:elastic/src/gopkg.in/olivere/elastic.v5 \
		pborman:uuid:c65b2f8:uuid/src/github.com/pborman/uuid \
		pelletier:go-toml:66540cf:toml/src/github.com/pelletier/go-toml \
		peterh:liner:80ce870:liner/src/github.com/peterh/liner \
		pkg:errors:816c908:errors/src/github.com/pkg/errors \
		russross:blackfriday:11635eb:blackfriday/src/github.com/russross/blackfriday \
		spf13:afero:787d034:afero/src/github.com/spf13/afero \
		spf13:cast:8965335:cast/src/github.com/spf13/cast \
		spf13:cobra:1e58aa3:cobra/src/github.com/spf13/cobra \
		spf13:jWalterWeatherman:7c0cea3:jwalterweatherman/src/github.com/spf13/jwalterweatherman \
		spf13:pflag:3ebe029:pflag/src/github.com/spf13/pflag \
		spf13:viper:1573881:viper/src/github.com/spf13/viper \
		syndtr:goleveldb:5d6fca4:goleveldb/src/github.com/syndtr/goleveldb \
		tylertreat:BoomFilters:8298e22:boomfilters/src/github.com/tylertreat/BoomFilters \
		golang:net:6d3beae:net/src/golang.org/x/net \
		golang:sys:37707fd:sys/src/golang.org/x/sys \
		golang:text:b7ef84a:text/src/golang.org/x/text
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${GH_PROJECT}

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@cd ${WRKSRC} && \
		${FIND} . -name "*.go" | ${XARGS} ${REINPLACE_CMD} -i '' -e ' \
			s|github.com/flimzy/kivik|github.com/go-kivik/kivik|; \
			s|github.com/olivere/elastic|gopkg.in/olivere/elastic.v5|; \
			s|gopkg.in/mgo.v2-unstable|gopkg.in/mgo.v2|'

do-build:
	@cd ${WRKSRC} && [ -e ${PORTNAME} ] || ${LN} -s . ${PORTNAME}
	@cd ${WRKSRC}/${GH_SUBDIR} && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build \
			-ldflags="-X github.com/${GH_ACCOUNT}graph/${GH_PROJECT}/version.GitHash=${PORTVERSION}" \
			-o ${PORTNAME}x \
			-v ./cmd/cayley

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}x ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
