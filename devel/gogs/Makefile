# $FreeBSD$

PORTNAME=	gogs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.3
CATEGORIES=	devel www

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Painless self-hosted Git service

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go-bindata:devel/go-bindata
RUN_DEPENDS=	git:devel/git \
		bash:shells/bash

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	gogs
GH_TUPLE=	\
		Masterminds:semver:v3.1.0:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		alexcesaro:quotedprintable:2caba252f4dc:alexcesaro_quotedprintable/vendor/gopkg.in/alexcesaro/quotedprintable.v3 \
		aymerick:douceur:v0.2.0:aymerick_douceur/vendor/github.com/aymerick/douceur \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bgentry:speakeasy:v0.1.0:bgentry_speakeasy/vendor/github.com/bgentry/speakeasy \
		boombuler:barcode:6c824513bacc:boombuler_barcode/vendor/github.com/boombuler/barcode \
		bradfitz:gomemcache:551aad21a668:bradfitz_gomemcache/vendor/github.com/bradfitz/gomemcache \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		chris-ramon:douceur:v0.2.0:chris_ramon_douceur \
		cpuguy83:go-md2man:f79a8a8ca69d:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		denisenkom:go-mssqldb:bbfc9a55622e:denisenkom_go_mssqldb/vendor/github.com/denisenkom/go-mssqldb \
		editorconfig:editorconfig-core-go:v2.3.2:editorconfig_editorconfig_core_go_v2/vendor/github.com/editorconfig/editorconfig-core-go/v2 \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		go-asn1-ber:asn1-ber:f715ec2f112d:go_asn1_ber_asn1_ber/vendor/gopkg.in/asn1-ber.v1 \
		go-bufio:bufio:567b2bfa514e:go_bufio_bufio/vendor/gopkg.in/bufio.v1 \
		go-clog:clog:v2.1.2:go_clog_clog/vendor/unknwon.dev/clog/v2 \
		go-gomail:gomail:81ebce5c23df:go_gomail_gomail/vendor/gopkg.in/gomail.v2 \
		go-ini:ini:v1.56.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-ldap:ldap:v2.5.1:go_ldap_ldap/vendor/gopkg.in/ldap.v2 \
		go-macaron:binding:v1.1.0:go_macaron_binding/vendor/github.com/go-macaron/binding \
		go-macaron:cache:10f7c57e2196:go_macaron_cache/vendor/github.com/go-macaron/cache \
		go-macaron:captcha:v0.2.0:go_macaron_captcha/vendor/github.com/go-macaron/captcha \
		go-macaron:csrf:946f6d303a4c:go_macaron_csrf/vendor/github.com/go-macaron/csrf \
		go-macaron:gzip:cad1c6580a07:go_macaron_gzip/vendor/github.com/go-macaron/gzip \
		go-macaron:i18n:v0.5.0:go_macaron_i18n/vendor/github.com/go-macaron/i18n \
		go-macaron:inject:d8a0b8677191:go_macaron_inject/vendor/github.com/go-macaron/inject \
		go-macaron:macaron:v1.3.9:go_macaron_macaron/vendor/gopkg.in/macaron.v1 \
		go-macaron:session:1a3cdc6f5659:go_macaron_session/vendor/github.com/go-macaron/session \
		go-macaron:toolbox:94defb8383c6:go_macaron_toolbox/vendor/github.com/go-macaron/toolbox \
		go-redis:redis:v2.3.2:go_redis_redis/vendor/gopkg.in/redis.v2 \
		go-sql-driver:mysql:v1.5.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		gogs:chardet:2404f7772561:gogs_chardet/vendor/github.com/gogs/chardet \
		gogs:cron:9f6c956d3e14:gogs_cron/vendor/github.com/gogs/cron \
		gogs:git-module:v1.1.2:gogs_git_module/vendor/github.com/gogs/git-module \
		gogs:go-gogs-client:c69cb7680fd4:gogs_go_gogs_client/vendor/github.com/gogs/go-gogs-client \
		gogs:go-libravatar:33a75213d0a0:gogs_go_libravatar/vendor/github.com/gogs/go-libravatar \
		gogs:minwinsvc:95be6356811a:gogs_minwinsvc/vendor/github.com/gogs/minwinsvc \
		golang-sql:civil:cb61b32ac6fe:golang_sql_civil/vendor/github.com/golang-sql/civil \
		golang:crypto:bac4c82f6975:golang_crypto/vendor/golang.org/x/crypto \
		golang:mod:v0.2.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:da9a3fd4c582:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.4.0:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:1957bb5e6d1f:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		google:go-github:v17.0.0:google_go_github/vendor/github.com/google/go-github \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		gorilla:css:v1.0.0:gorilla_css/vendor/github.com/gorilla/css \
		issue9:identicon:v1.0.1:issue9_identicon/vendor/github.com/issue9/identicon \
		jaytaylor:html2text:01ec452cbe43:jaytaylor_html2text/vendor/github.com/jaytaylor/html2text \
		jinzhu:gorm:v1.9.12:jinzhu_gorm/vendor/github.com/jinzhu/gorm \
		jinzhu:inflection:v1.0.0:jinzhu_inflection/vendor/github.com/jinzhu/inflection \
		json-iterator:go:v1.1.10:json_iterator_go/vendor/github.com/json-iterator/go \
		klauspost:compress:v1.8.6:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:cpuid:v1.2.1:klauspost_cpuid/vendor/github.com/klauspost/cpuid \
		lib:pq:v1.3.0:lib_pq/vendor/github.com/lib/pq \
		mattn:go-colorable:v0.1.4:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.4:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-sqlite3:v2.0.3:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mcuadros:go-version:035f6764e8d2:mcuadros_go_version/vendor/github.com/mcuadros/go-version \
		microcosm-cc:bluemonday:v1.0.4:microcosm_cc_bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		msteinert:pam:f29b9f28d6f9:msteinert_pam/vendor/github.com/msteinert/pam \
		nfnt:resize:83c6a9932646:nfnt_resize/vendor/github.com/nfnt/resize \
		niklasfasching:go-org:v0.1.9:niklasfasching_go_org/vendor/github.com/niklasfasching/go-org \
		olekukonko:tablewriter:v0.0.1:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		pquerna:otp:v1.2.0:pquerna_otp/vendor/github.com/pquerna/otp \
		prometheus:client_golang:v1.6.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.9.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.11:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.21.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		russross:blackfriday:v1.5.2:russross_blackfriday/vendor/github.com/russross/blackfriday \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		saintfish:chardet:3af4cd4741ca:saintfish_chardet/vendor/github.com/saintfish/chardet \
		satori:go.uuid:v1.2.0:satori_go_uuid/vendor/github.com/satori/go.uuid \
		sergi:go-diff:v1.1.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		ssor:bom:6386211fdfcf:ssor_bom/vendor/github.com/ssor/bom \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify \
		t-tiger:gorm-bulk-insert:v1.3.0:t_tiger_gorm_bulk_insert/vendor/github.com/t-tiger/gorm-bulk-insert \
		unknwon:cae:v1.0.2:unknwon_cae/vendor/github.com/unknwon/cae \
		unknwon:com:v1.0.1:unknwon_com/vendor/github.com/unknwon/com \
		unknwon:i18n:5c6446a380b6:unknwon_i18n/vendor/github.com/unknwon/i18n \
		unknwon:paginater:45e5d631308e:unknwon_paginater/vendor/github.com/unknwon/paginater \
		urfave:cli:v1.22.4:urfave_cli/vendor/github.com/urfave/cli

_XORM_TUPLE=    builder:v0.3.6:vendor/xorm.io/builder \
                core:v0.7.2:vendor/xorm.io/core \
                xorm:v0.8.0:vendor/xorm.io/xorm

GO_TARGET=	:${PREFIX}/libexec/${PORTNAME}/${PORTNAME}
GO_BUILDFLAGS=	-tags "sqlite pam cert"


SUB_FILES=	gogs \
		gogs-service \
		gogs-rm-data \
		pkg-message
SUB_LIST=	PORTNAME=${PORTNAME} \
		PORTNAME_FANCY=${PORTNAME_FANCY} \
		GOGS_USER=${USERS} \
		GOGS_DBDIR=${GOGS_DBDIR} \
		GOGS_LOGDIR=${GOGS_LOGDIR}

USERS=		git
GROUPS=		git

PLIST_SUB=	GOGS_USER=${USERS} \
		GOGS_GROUP=${GROUPS} \
		GOGS_DBDIR=${GOGS_DBDIR} \
		GOGS_LOGDIR=${GOGS_LOGDIR}

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

GOGS_DBDIR?=	/var/db/gogs
GOGS_LOGDIR?=	/var/log/gogs
PORTNAME_FANCY=	Gogs

.include <bsd.port.pre.mk>

.for project tag subdir in ${_XORM_TUPLE:S/:/ /g}
MASTER_SITES+=	https://gitea.com/xorm/${project}/archive/${tag}${EXTRACT_SUFX}?dummy=/:xorm_${project}
DISTFILES+=	xorm-${project}-${tag}_GITEA0${EXTRACT_SUFX}:xorm_${project}
.endfor

post-extract:
.for project tag subdir in ${_XORM_TUPLE:S/:/ /g}
	@${MKDIR} ${WRKSRC}/${subdir:H}
	@${RLN} ${WRKDIR}/${project} ${WRKSRC}/${subdir}
.endfor
	@${MKDIR} ${WRKSRC}/vendor/github.com/chris-ramon
	@${RLN} ${WRKSRC_aymerick_douceur} ${WRKSRC}/vendor/github.com/chris-ramon/douceur

post-patch:
	@${REINPLACE_CMD} \
		-e '/^# \!\!\!/d' \
		-e 's|^RUN_USER = git$$|RUN_USER = ${USERS}|' \
		-e 's|^RUN_MODE = dev$$|RUN_MODE = prod|' \
		-e 's|^ROOT =$$|ROOT = ${GOGS_DBDIR}/repositories|' \
		-e 's|^ROOT_PATH =$$|ROOT_PATH = ${GOGS_LOGDIR}|' \
		-e 's|^TYPE = postgres$$|DB_TYPE = sqlite3|' \
		${WRKSRC}/conf/app.ini

pre-build:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} generate internal/assets/templates/templates.go \

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/gogs ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKDIR}/gogs-rm-data ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKDIR}/gogs-service ${STAGEDIR}${PREFIX}/etc/rc.d/gogs
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "conf public templates" ${STAGEDIR}${PREFIX}/libexec/${PORTNAME})
	@${MKDIR} ${STAGEDIR}${ETCDIR}/conf
	@${MKDIR} ${STAGEDIR}${ETCDIR}/https
	${INSTALL_DATA} ${WRKSRC}/conf/app.ini ${STAGEDIR}${ETCDIR}/conf/app.ini.sample
	@${RLN} ${STAGEDIR}${ETCDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/custom
	@${MKDIR} ${STAGEDIR}${GOGS_DBDIR}/data ${STAGEDIR}${GOGS_DBDIR}/repositories
	@${LN} -sf ${GOGS_DBDIR}/data ${STAGEDIR}/${PREFIX}/libexec/${PORTNAME}/data
	@${MKDIR} ${STAGEDIR}${GOGS_LOGDIR}
	@${LN} -sf ${GOGS_LOGDIR} ${STAGEDIR}/${PREFIX}/libexec/${PORTNAME}/log

.include <bsd.port.post.mk>
