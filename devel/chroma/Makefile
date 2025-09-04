PORTNAME=	chroma
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.2
PORTREVISION=	30
CATEGORIES=	devel
PKGNAMESUFFIX=	-syntax-highlighter

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	General purpose syntax highlighter in pure Go
WWW=		https://github.com/alecthomas/chroma

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	alecthomas
GH_TUPLE=	\
		alecthomas:assert:405dbfeb8e38:alecthomas_assert/vendor/github.com/alecthomas/assert \
		alecthomas:colour:60882d9e2721:alecthomas_colour/vendor/github.com/alecthomas/colour \
		alecthomas:kong:v0.2.4:alecthomas_kong/vendor/github.com/alecthomas/kong \
		alecthomas:repr:117648cd9897:alecthomas_repr/vendor/github.com/alecthomas/repr \
		danwakefield:fnmatch:cbb64ac3d964:danwakefield_fnmatch/vendor/github.com/danwakefield/fnmatch \
		dlclark:regexp2:v1.4.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys \
		mattn:go-colorable:v0.1.6:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		sergi:go-diff:v1.0.0:sergi_go_diff/vendor/github.com/sergi/go-diff
# modules2tuples should be used (not GO_MODULE) because library and command line tool are in the same archive which complicates it for GO_MODULE.

CONFLICTS_INSTALL=	chroma

GO_TARGET=	./cmd/chroma

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
