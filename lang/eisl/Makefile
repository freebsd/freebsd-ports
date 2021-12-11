PORTNAME=	eisl
DISTVERSIONPREFIX=	v
DISTVERSION=	2.34
CATEGORIES=	lang devel

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
