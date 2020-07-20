# $FreeBSD$

PORTNAME=	gonic
PORTVERSION=	0.10.0
DISTVERSIONPREFIX=	v
CATEGORIES=	audio net

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Music streaming server / subsonic server API implementation

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtag.so:audio/taglib

USES=		go:modules openal pkgconfig

USE_RC_SUBR=	${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	sentriz
GO_TARGET=	./cmd/gonic

GH_TUPLE=	Masterminds:goutils:v1.1.0:masterminds_goutils/vendor/github.com/Masterminds/goutils \
		Masterminds:semver:v1.5.0:masterminds_semver/vendor/github.com/Masterminds/semver \
		Masterminds:sprig:v2.22.0:masterminds_sprig/vendor/github.com/Masterminds/sprig \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		faiface:beep:v1.0.2:faiface_beep/vendor/github.com/faiface/beep \
		go-check:check:788fd7840127:go_check_check/vendor/gopkg.in/check.v1 \
		go-gormigrate:gormigrate:v1.6.0:go_gormigrate_gormigrate/vendor/gopkg.in/gormigrate.v1 \
		golang:crypto:06a226fb4e37:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:00229845015e:golang_exp/vendor/golang.org/x/exp \
		golang:image:33d19683fad8:golang_image/vendor/golang.org/x/image \
		golang:lint:959b441ac422:golang_lint/vendor/github.com/golang/lint \
		golang:mobile:4c31acba0007:golang_mobile/vendor/golang.org/x/mobile \
		golang:sys:fe76b779f299:golang_sys/vendor/golang.org/x/sys \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		gorilla:context:v1.1.1:gorilla_context/vendor/github.com/gorilla/context \
		gorilla:mux:v1.7.4:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:securecookie:v1.1.1:gorilla_securecookie/vendor/github.com/gorilla/securecookie \
		gorilla:sessions:v1.2.0:gorilla_sessions/vendor/github.com/gorilla/sessions \
		hajimehoshi:go-mp3:v0.2.1:hajimehoshi_go_mp3/vendor/github.com/hajimehoshi/go-mp3 \
		hajimehoshi:oto:v0.6.1:hajimehoshi_oto/vendor/github.com/hajimehoshi/oto \
		huandu:xstrings:v1.3.1:huandu_xstrings/vendor/github.com/huandu/xstrings \
		icza:bitio:v1.0.0:icza_bitio/vendor/github.com/icza/bitio \
		imdario:mergo:v0.3.9:imdario_mergo/vendor/github.com/imdario/mergo \
		jinzhu:gorm:v1.9.12:jinzhu_gorm/vendor/github.com/jinzhu/gorm \
		jinzhu:inflection:v1.0.0:jinzhu_inflection/vendor/github.com/jinzhu/inflection \
		josephburnett:jd:aa1a7c66b42f:josephburnett_jd/vendor/github.com/josephburnett/jd \
		karrick:godirwalk:v1.15.6:karrick_godirwalk/vendor/github.com/karrick/godirwalk \
		kr:pretty:v0.1.0:kr_pretty/vendor/github.com/kr/pretty \
		mattn:go-sqlite3:v2.0.3:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		mewkiz:flac:v1.0.6:mewkiz_flac/vendor/github.com/mewkiz/flac \
		mewkiz:pkg:f6b5e26764c3:mewkiz_pkg/vendor/github.com/mewkiz/pkg \
		mitchellh:copystructure:v1.0.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:reflectwalk:v1.0.1:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		nicksellen:audiotags:94015fa599bd:nicksellen_audiotags/vendor/github.com/nicksellen/audiotags \
		oklog:run:v1.1.0:oklog_run/vendor/github.com/oklog/run \
		oxtoacart:bpool:03653db5a59c:oxtoacart_bpool/vendor/github.com/oxtoacart/bpool \
		peterbourgon:ff:v1.7.0:peterbourgon_ff/vendor/github.com/peterbourgon/ff \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		rainycape:unidecode:cb7f23ec59be:rainycape_unidecode/vendor/github.com/rainycape/unidecode \
		wader:gormstore:65a111a20c23:wader_gormstore/vendor/github.com/wader/gormstore

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PLIST_FILES=	bin/gonic

.include <bsd.port.mk>
