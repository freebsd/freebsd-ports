# Created by: Lutz Boehne <lboehne@damogran.de>
# $FreeBSD$

PORTNAME=	udis86
PORTVERSION=	1.7.2
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Minimalistic x86 and x86-64 disassembler library

LICENSE=	BSD2CLAUSE

USES=		gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-sphinx-build --enable-shared
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

INFO=		udis86
PORTDOCS=	x86

OPTIONS_DEFINE=	DOCS TEST

TEST_BUILD_DEPENDS=	${LOCALBASE}/bin/yasm:devel/yasm
TEST_USES=		python:2.7,build
TEST_TEST_TARGET=	check
TEST_CONFIGURE_ENV=	PYTHON="${PYTHON_CMD}" YASM="${LOCALBASE}/bin/yasm"
TEST_CONFIGURE_ENV_OFF=	PYTHON="${FALSE}"
TEST_CONFIGURE_OFF=	--without-yasm

post-patch:
	@${REINPLACE_CMD} -Ee 's/function ([^#]+).*/\1 ()/' \
		${WRKSRC}/tests/difftest.sh.in

post-patch-DOCS-on:
	@${REINPLACE_CMD} -e '\|docdir =|s|/docs/|/doc/|' \
		${WRKSRC}/docs/manual/Makefile.in \
		${WRKSRC}/docs/x86/Makefile.in

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/SUBDIRS \=/s/ docs//' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/manual/udis86.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH}

.include <bsd.port.mk>
