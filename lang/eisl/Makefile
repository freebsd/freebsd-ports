PORTNAME=	eisl
DISTVERSIONPREFIX=	v
DISTVERSION=	2.50-114
PORTREVISION=	2
DISTVERSIONSUFFIX=	-g1216d9e
CATEGORIES=	lang devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interpreter and compiler compatible with ISLisp standard

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/documents/license.txt

TEST_DEPENDS=	cppcheck:devel/cppcheck

USES=		gmake ncurses:port # port because tests need ncurses6-config

USE_GITHUB=	yes
GH_ACCOUNT=	sasagawa888

ALL_TARGET=	${PORTNAME}
TEST_TARGET=	check # tests print some errors and warnings, see https://github.com/sasagawa888/eisl/issues/181#issuecomment-1195147029

MAKEFILE=	makefile

LDFLAGS+=	-lncursesw

PLIST_FILES=	bin/edlis \
		bin/eisl

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64 || ${ARCH} == riscv64
EXTRA_PATCHES=	${FILESDIR}/extra-patch-makefile
.endif

.include <bsd.port.mk>
