DISTVERSION=	1.19.12
# Always set PORTREVISION explicitly as otherwise they are inherited from lang/go-devel
PORTREVISION=	1
MASTER_SITES=	https://golang.org/dl/ \
		https://github.com/dmgk/go-bootstrap/releases/download/${BOOTSTRAP_TAG}/:bootstrap \
		LOCAL/dmgk:bootstrap
DISTFILES=	go${DISTVERSION}.src.tar.gz \
		go-${OPSYS:tl}-${GOARCH_${ARCH}}${GOARM_${ARCH}}-${BOOTSTRAP_TAG}.tar.xz:bootstrap

# Avoid conflicting patch files
PATCHFILES=

COMMENT=	Go programming language

DEPRECATED=	Upsrteam EOL reached on 2023-09-06
EXPIRATION_DATE=	2024-04-18

MASTERDIR=	${.CURDIR}/../go-devel
PATCHDIR=	${.CURDIR}/files
WRKSRC=		${WRKDIR}/go
DISTINFO_FILE=	${.CURDIR}/distinfo

.include "${MASTERDIR}/Makefile"
