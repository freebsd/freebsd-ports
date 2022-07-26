PORTNAME=	eisl
DISTVERSIONPREFIX=	v
DISTVERSION=	2.50-114
DISTVERSIONSUFFIX=	-g1216d9e
CATEGORIES=	lang devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interpreter and compiler compatible with ISLisp standard

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/documents/license.txt

BROKEN_riscv64=	hard-float 'd' ABI can't be used for a target that doesn't support the D instruction set extension (ignoring target-abi)

USES=		gmake ncurses:base

USE_GITHUB=	yes
GH_ACCOUNT=	sasagawa888

ALL_TARGET=	${PORTNAME}

MAKEFILE=	makefile

LDFLAGS+=	-lncursesw

PLIST_FILES=	bin/edlis \
		bin/eisl

.include <bsd.port.mk>
