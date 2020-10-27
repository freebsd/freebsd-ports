# $FreeBSD$

PORTNAME=	OpenDiablo2
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1
DISTVERSIONSUFFIX=	-pre-alpha
CATEGORIES=	games

MAINTAINER=	ed.arrakis@gmail.com
COMMENT=	Diablo II engine for modern operating systems

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libglfw.so:graphics/glfw

USES=		gl go:modules openal pkgconfig xorg
USE_GL=		gl
USE_XORG=	x11 xcursor xi xinerama xrandr xxf86vm
USE_GITHUB=	yes
GH_TUPLE=	\
		JoshVarga:blast:681c804fb9f0:joshvarga_blast/vendor/github.com/JoshVarga/blast \
		alecthomas:kingpin:v2.2.6:alecthomas_kingpin/vendor/gopkg.in/alecthomas/kingpin.v2 \
		alecthomas:template:fb15b899a751:alecthomas_template/vendor/github.com/alecthomas/template \
		alecthomas:units:f65c72e2690d:alecthomas_units/vendor/github.com/alecthomas/units \
		davecgh:go-spew:v1.1.0:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		go-gl:glfw:5321531:go_gl_glfw_glfw/vendor/github.com/go-gl/glfw \
		go-restruct:restruct:5734170a48a1:go_restruct_restruct/vendor/github.com/go-restruct/restruct \
		go-sourcemap:sourcemap:v1.0.5:go_sourcemap_sourcemap/vendor/gopkg.in/sourcemap.v1 \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:exp:ec7cb31e5a56:golang_exp/vendor/golang.org/x/exp \
		golang:image:c13761719519:golang_image/vendor/golang.org/x/image \
		golang:mobile:3c8601c510d0:golang_mobile/vendor/golang.org/x/mobile \
		golang:sys:33540a1f6037:golang_sys/vendor/golang.org/x/sys \
		google:uuid:v1.1.2:google_uuid/vendor/github.com/google/uuid \
		hajimehoshi:ebiten:v1.11.4:hajimehoshi_ebiten/vendor/github.com/hajimehoshi/ebiten \
		hajimehoshi:oto:v0.5.4:hajimehoshi_oto/vendor/github.com/hajimehoshi/oto \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:profile:v1.5.0:pkg_profile/vendor/github.com/pkg/profile \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		robertkrimen:otto:c382bd3c16ff:robertkrimen_otto/vendor/github.com/robertkrimen/otto \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify

PLIST_FILES=	bin/${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
