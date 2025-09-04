PORTNAME=	git-who
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Git blame for file trees
WWW=		https://github.com/sinclairtarget/git-who

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	sinclairtarget
GH_TUPLE=	bmatcuk:doublestar:v4.8.1:bmatcuk_doublestar_v4/vendor/github.com/bmatcuk/doublestar/v4 \
		golang:sys:v0.29.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.28.0:golang_term/vendor/golang.org/x/term \
		google:go-cmp:v0.6.0:google_go_cmp/vendor/github.com/google/go-cmp \
		mattn:go-runewidth:v0.0.16:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg

GO_BUILDFLAGS=	-ldflags="-s -w -X main.Commit=${DISTVERSIONFULL} -X main.Version=${DISTVERSIONFULL}"

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor

.include <bsd.port.mk>
