DISTVERSION=	1.20.14
# Always set PORTREVISION explicitly as otherwise they are inherited from lang/go-devel
PORTREVISION=	5
MASTER_SITES=	https://golang.org/dl/ \
		https://github.com/dmgk/go-bootstrap/releases/download/${BOOTSTRAP_TAG}/:bootstrap \
		LOCAL/dmgk:bootstrap
DISTFILES=	go${DISTVERSION}.src.tar.gz \
		go-${OPSYS:tl}-${GOARCH_${ARCH}}${GOARM_${ARCH}}-${BOOTSTRAP_TAG}.tar.xz:bootstrap

# Avoid conflicting patch files
PATCHFILES=

COMMENT=	Go programming language

BUILD_DEPENDS=

MASTERDIR=	${.CURDIR}/../go-devel
PATCHDIR=	${.CURDIR}/files
WRKSRC=		${WRKDIR}/go
DISTINFO_FILE=	${.CURDIR}/distinfo
SHEBANG_FILES=	misc/wasm/go_js_wasm_exec \
		src/net/http/cgi/testdata/test.cgi
BASH=		${SH}

DEPRECATED=	Old version, unsupported upstream
EXPIRATION_DATE=2026-01-01

.include "${MASTERDIR}/Makefile"
