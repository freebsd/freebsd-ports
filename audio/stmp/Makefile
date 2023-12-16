PORTNAME=	stmp
PORTVERSION=	0.0.2
PORTREVISION=	18
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Subsonic terminal music player
WWW=		https://github.com/wildeyedskies/stmp/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		fails to build with mpv 0.35, see bug 267114

BUILD_DEPENDS=	${LOCALBASE}/lib/libHLSL.a:graphics/glslang
LIB_DEPENDS=	libmpv.so:multimedia/mpv

USES=		go:modules xorg gl

USE_GL=		egl

USE_GITHUB=	yes
GH_ACCOUNT=	wildeyedskies

GH_TUPLE=	\
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v2.1.0:gdamore_tcell_v2/vendor/github.com/gdamore/tcell/v2 \
		go-ini:ini:v1.51.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-yaml:yaml:v2.2.4:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:sys:b09fb700fbb7:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		lucasb-eyer:go-colorful:v1.0.3:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		rivo:tview:5406288b8e4e:rivo_tview/vendor/github.com/rivo/tview \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		spf13:afero:v1.1.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.7.1:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		yourok:go-mpv:ecdfd901e332:yourok_go_mpv/vendor/github.com/yourok/go-mpv

CGO_CFLAGS=	-DTAG_EGL
CGO_LDFLAGS=	-lEGL

PLIST_FILES=	bin/stmp \
		${EXAMPLESDIR}/stmp-example.toml

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/stmp-example.toml ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
