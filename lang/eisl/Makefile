PORTNAME=	eisl
DISTVERSIONPREFIX=	v
DISTVERSION=	2.37
CATEGORIES=	lang devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	78560c2760eaf990601cd0a73c6a8036eba0f8cc.patch:-p1 # https://github.com/sasagawa888/eisl/pull/168

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interpreter and compiler compatible with ISLisp standard

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/documents/license.txt

USES=		gmake ncurses:base

USE_GITHUB=	yes
GH_ACCOUNT=	sasagawa888

ALL_TARGET=	${PORTNAME}

MAKEFILE=	makefile

LDFLAGS+=	-lncursesw

PLIST_FILES=	bin/edlis \
		bin/eisl

.include <bsd.port.mk>
