DISTVERSION=	1.22.6
# Always set PORTREVISION explicitly as otherwise they are inherited from lang/go-devel
PORTREVISION=	1
MASTER_SITES=	https://golang.org/dl/ \
		https://github.com/dmgk/go-bootstrap/releases/download/${BOOTSTRAP_TAG}/:bootstrap \
		LOCAL/dmgk:bootstrap
DISTFILES=	go${DISTVERSION}.src.tar.gz \
		go-${OPSYS:tl}-${GOARCH_${ARCH}}${GOARM_${ARCH}}-${BOOTSTRAP_TAG}.tar.xz:bootstrap

# Avoid conflicting patch files
PATCHFILES=
PATCHDIR=	${.CURDIR}/files

COMMENT=	Go programming language

MASTERDIR=	${.CURDIR}/../go-devel
WRKSRC=		${WRKDIR}/go
DISTINFO_FILE=	${.CURDIR}/distinfo

.include "${MASTERDIR}/Makefile"
