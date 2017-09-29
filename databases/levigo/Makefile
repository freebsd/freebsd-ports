# $FreeBSD$

PORTNAME=	levigo
PORTVERSION=	20150216
PORTREVISION=	3
CATEGORIES=	databases

MAINTAINER=	cheffo@freebsd-bg.org
COMMENT=	Levigo is a Go wrapper for LevelDB

LICENSE=	MIT

BUILD_DEPENDS=	go:lang/go
LIB_DEPENDS=	libleveldb.so:databases/leveldb

ONLY_FOR_ARCHS=	i386 amd64

USES=		compiler go

USE_GITHUB=	yes
GH_ACCOUNT=	jmhodges
GH_TAGNAME=	1ddad808d4

.include <bsd.port.pre.mk>

# Build fails on FreeBSD10+ if value of "CC" is not set to "clang"
# (checked by configure)

.if ${COMPILER_TYPE} == clang
CC=		clang
.else
USE_GCC=	yes
.endif

CONFIGURE_ENV+=	CC=${CC} \
		CXX=${CXX}
GO_ENV+=	${CONFIGURE_ENV}

.include <bsd.port.post.mk>
