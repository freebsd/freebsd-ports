# Created by: Devon H. O'Dell <devon.odell@gmail.com>
# $FreeBSD$

PORTVERSION=	g20200514
# Always set PORTREVISION and PORTEPOCH explicitly as otherwise it is inherited from lang/go
PORTEPOCH=	0
MASTER_SITES=	https://github.com/dmgk/go-bootstrap/releases/download/${BOOTSTRAP_TAG}/:bootstrap \
		LOCAL/dmgk:bootstrap
PKGNAMESUFFIX=	-devel
DISTFILES=	go-${OPSYS:tl}-${GOARCH_${ARCH}}${GOARM_${ARCH}}-${BOOTSTRAP_TAG}.tar.xz:bootstrap

COMMENT=	Go programming language (development version)

USE_GITHUB=	yes
GH_ACCOUNT=	golang
GH_TAGNAME=	f296b7a6f045325a230f77e9bda1470b1270f817

CONFLICTS_INSTALL=	go

MASTERDIR=	${.CURDIR}/../go
PATCHDIR=	${.CURDIR}/files
DISTINFO_FILE=	${.CURDIR}/distinfo

post-extract:
	@[ -f ${WRKSRC}/VERSION ] || ${ECHO_CMD} "devel +${GH_TAGNAME}" > ${WRKSRC}/VERSION

.include "${MASTERDIR}/Makefile"
