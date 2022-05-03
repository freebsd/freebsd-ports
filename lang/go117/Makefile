PORTVERSION=	1.17.9
# Always set PORTREVISION and PORTEPOCH explicitly as otherwise they are inherited from lang/go
PORTREVISION=	0
PORTEPOCH=	0
MASTER_SITES=	https://github.com/dmgk/go-bootstrap/releases/download/${BOOTSTRAP_TAG}/:bootstrap \
		LOCAL/dmgk:bootstrap
PKGNAMESUFFIX=	117
DISTFILES=	go-${OPSYS:tl}-${GOARCH_${ARCH}}${GOARM_${ARCH}}-${BOOTSTRAP_TAG}.tar.xz:bootstrap

# Avoid conflicting patch files
PATCHFILES=

COMMENT=	Go programming language (development version)

USE_GITHUB=	yes
GH_ACCOUNT=	golang
GH_TAGNAME=	7dd10d4ce20e64d96a10cb67794851a58d96a2aa

CONFLICTS_INSTALL=	go

MASTERDIR=	${.CURDIR}/../go
PATCHDIR=	${.CURDIR}/files
DISTINFO_FILE=	${.CURDIR}/distinfo

post-extract:
	@[ -f ${WRKSRC}/VERSION ] || ${ECHO_CMD} "${PORTVERSION} +${GH_TAGNAME}" > ${WRKSRC}/VERSION

.include "${MASTERDIR}/Makefile"
