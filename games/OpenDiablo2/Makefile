# $FreeBSD$

PORTNAME=	OpenDiablo2
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1-g20210312
CATEGORIES=	games

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Open source re-implementation of Diablo 2

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libglfw.so:graphics/glfw

USES=		gl go:modules openal pkgconfig xorg
USE_GITHUB=	yes
GH_TAGNAME=	536233f
GH_TUPLE=	\
		JoshVarga:blast:681c804fb9f0:joshvarga_blast/vendor/github.com/JoshVarga/blast \
		alecthomas:template:fb15b899a751:alecthomas_template/vendor/github.com/alecthomas/template \
		alecthomas:units:f65c72e2690d:alecthomas_units/vendor/github.com/alecthomas/units \
		davecgh:go-spew:v1.1.0:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		go-gl:glfw:5321531c36a2:go_gl_glfw_glfw/vendor/github.com/go-gl/glfw \
		go-restruct:restruct:v1.2.0-alpha:go_restruct_restruct/vendor/github.com/go-restruct/restruct \
		go-sourcemap:sourcemap:v1.0.5:go_sourcemap_sourcemap/vendor/gopkg.in/sourcemap.v1 \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:exp:e3b2a7f2fdc7:golang_exp/vendor/golang.org/x/exp \
		golang:image:e162460cd6b5:golang_image/vendor/golang.org/x/image \
		golang:mobile:973feb4309de:golang_mobile/vendor/golang.org/x/mobile \
		golang:sys:c5abc1b1d397:golang_sys/vendor/golang.org/x/sys \
		google:uuid:v1.1.2:google_uuid/vendor/github.com/google/uuid \
		gravestench:akara:a64208a7fd3c:gravestench_akara/vendor/github.com/gravestench/akara \
		hajimehoshi:ebiten:v2.0.2:hajimehoshi_ebiten_v2/vendor/github.com/hajimehoshi/ebiten/v2 \
		hajimehoshi:oto:v0.6.8:hajimehoshi_oto/vendor/github.com/hajimehoshi/oto \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:profile:v1.5.0:pkg_profile/vendor/github.com/pkg/profile \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		robertkrimen:otto:ef014fd054ac:robertkrimen_otto/vendor/github.com/robertkrimen/otto \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify
USE_GL=		gl
USE_XORG=	x11 xcursor xi xinerama xrandr xxf86vm

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
