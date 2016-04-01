# Created by: Lutz Boehne <lboehne@damogran.de>
# $FreeBSD$

PORTNAME=	udis86
PORTVERSION=	1.7.2
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Minimalistic x86 and x86-64 disassembler library

LICENSE=	BSD2CLAUSE

USES=		gmake libtool
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-sphinx-build  --enable-shared

INFO=		udis86
PORTDOCS=	x86

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -Ee 's/function ([^#]+).*/\1 ()/' \
		${WRKSRC}/tests/difftest.sh.in
.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '\|docdir =|s|/docs/|/doc/|' \
		${WRKSRC}/docs/manual/Makefile.in \
		${WRKSRC}/docs/x86/Makefile.in
.else
	@${REINPLACE_CMD} -e '/SUBDIRS \=/s/ docs//' ${WRKSRC}/Makefile.in
.endif

.if defined(MAINTAINER_MODE) || defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=		${LOCALBASE}/bin/yasm:devel/yasm
CONFIGURE_ENV+=		PYTHON="${PYTHON_CMD}" YASM="${LOCALBASE}/bin/yasm"
USES+=			python:build

check regression-test test: build
	@cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} check

.else
CONFIGURE_ARGS+=	--without-yasm
CONFIGURE_ENV+=		PYTHON="${FALSE}"
.endif

post-install:
	@${INSTALL_DATA} ${WRKSRC}/docs/manual/udis86.info ${STAGEDIR}${PREFIX}/${INFO_PATH}/

.include <bsd.port.mk>
