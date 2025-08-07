PORTNAME=	magia
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
PORTREVISION=	29
CATEGORIES=	emulators

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GBA emulator written in golang
WWW=		https://github.com/pokemium/magia

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libglfw.so:graphics/glfw

USES=		gl go:modules openal pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	pokemium

GH_TUPLE=	anthonynsimon:bild:v0.13.0:anthonynsimon_bild/vendor/github.com/anthonynsimon/bild \
		go-gl:glfw:5321531c36a2:go_gl_glfw_glfw/vendor/github.com/go-gl/glfw \
		golang:exp:ec7cb31e5a56:golang_exp/vendor/golang.org/x/exp \
		golang:image:e162460cd6b5:golang_image/vendor/golang.org/x/image \
		golang:mobile:f462b3930c8f:golang_mobile/vendor/golang.org/x/mobile \
		golang:sys:dfb3f7c4e634:golang_sys/vendor/golang.org/x/sys \
		hajimehoshi:ebiten:v2.0.8:hajimehoshi_ebiten_v2/vendor/github.com/hajimehoshi/ebiten/v2 \
		hajimehoshi:oto:v0.7.1:hajimehoshi_oto/vendor/github.com/hajimehoshi/oto

USE_GL=		glu

GO_TARGET=	./cmd:${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
