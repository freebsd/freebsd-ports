# $FreeBSD$

PORTNAME=	gonic
PORTVERSION=	0.8.4
DISTVERSIONPREFIX=	v
CATEGORIES=	audio net

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Music streaming server / subsonic server API implementation

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtag.so:audio/taglib

USES=		go:modules pkgconfig

USE_RC_SUBR=	${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	sentriz
GO_TARGET=	./cmd/gonic ./cmd/gonicscan

GH_TUPLE=	\
		Masterminds:goutils:v1.1.0:masterminds_goutils/vendor/github.com/Masterminds/goutils \
		Masterminds:semver:v1.4.2:masterminds_semver/vendor/github.com/Masterminds/semver \
		Masterminds:sprig:v2.20.0:masterminds_sprig/vendor/github.com/Masterminds/sprig \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		go-gormigrate:gormigrate:v1.6.0:go_gormigrate_gormigrate/vendor/gopkg.in/gormigrate.v1 \
		golang:appengine:v1.6.1:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:cc06ce4a13d4:golang_crypto/vendor/golang.org/x/crypto \
		golang:lint:959b441ac422:golang_lint/vendor/github.com/golang/lint \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		googleapis:google-cloud-go:v0.40.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gorilla:context:v1.1.1:gorilla_context/vendor/github.com/gorilla/context \
		gorilla:mux:v1.7.3:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:securecookie:v1.1.1:gorilla_securecookie/vendor/github.com/gorilla/securecookie \
		gorilla:sessions:v1.1.3:gorilla_sessions/vendor/github.com/gorilla/sessions \
		huandu:xstrings:v1.2.0:huandu_xstrings/vendor/github.com/huandu/xstrings \
		imdario:mergo:v0.3.7:imdario_mergo/vendor/github.com/imdario/mergo \
		jinzhu:gorm:v1.9.10:jinzhu_gorm/vendor/github.com/jinzhu/gorm \
		jinzhu:inflection:v1.0.0:jinzhu_inflection/vendor/github.com/jinzhu/inflection \
		josephburnett:jd:1f9071c800e7:josephburnett_jd/vendor/github.com/josephburnett/jd \
		karrick:godirwalk:v1.15.2:karrick_godirwalk/vendor/github.com/karrick/godirwalk \
		kr:pretty:v0.1.0:kr_pretty/vendor/github.com/kr/pretty \
		mattn:go-sqlite3:v1.10.0:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		nicksellen:audiotags:94015fa599bd:nicksellen_audiotags/vendor/github.com/nicksellen/audiotags \
		oxtoacart:bpool:03653db5a59c:oxtoacart_bpool/vendor/github.com/oxtoacart/bpool \
		peterbourgon:ff:v1.2.0:peterbourgon_ff/vendor/github.com/peterbourgon/ff \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		rainycape:unidecode:cb7f23ec59be:rainycape_unidecode/vendor/github.com/rainycape/unidecode \
		wader:gormstore:acb787ba3755:wader_gormstore/vendor/github.com/wader/gormstore

USERS=	${PORTNAME}
GROUPS=	${PORTNAME}

PLIST_FILES=	bin/gonic \
		bin/gonicscan

.include <bsd.port.mk>
