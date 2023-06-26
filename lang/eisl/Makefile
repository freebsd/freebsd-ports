PORTNAME=	eisl
DISTVERSIONPREFIX=	v
DISTVERSION=	3.03
CATEGORIES=	lang devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interpreter and compiler compatible with ISLisp standard
WWW=		https://github.com/sasagawa888/eisl

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

BROKEN_i386=	stage breaks: data segment of more than 500GB is required, see https://github.com/sasagawa888/eisl/issues/218

TEST_DEPENDS=	cppcheck:devel/cppcheck

USES=		gmake ncurses:port # port because tests need ncurses6-config

USE_GITHUB=	yes
GH_ACCOUNT=	sasagawa888

ALL_TARGET=	${PORTNAME}
TEST_TARGET=	check # tests print some errors and warnings, see https://github.com/sasagawa888/eisl/issues/181#issuecomment-1195147029

MAKEFILE=	makefile

LDFLAGS+=	-lncursesw

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64 || ${ARCH} == riscv64
EXTRA_PATCHES=	${FILESDIR}/extra-patch-makefile
.endif

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>
