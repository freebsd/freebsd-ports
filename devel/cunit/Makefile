# Created by: Stefan Pauly <stefan@fh-mainz.de>
# $FreeBSD$

PORTNAME=	cunit
PORTVERSION=	2.1.3
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/CUnit/${PORTVERSION:R}-${PORTVERSION:E}
DISTNAME=	CUnit-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Automated unit testing framework for C

LICENSE=	LGPL20

CONFLICTS=	c-unit-[0-9]*

OPTIONS_DEFINE=	AUTOMATED BASIC CONSOLE CURSES DEBUG EXAMPLES MEMTRACE TEST
OPTIONS_DEFAULT=AUTOMATED BASIC CONSOLE CURSES DEBUG EXAMPLES MEMTRACE TEST
OPTIONS_SUB=	yes
AUTOMATED_DESC=	Automated (XML) interface
BASIC_DESC=	Basic interface
CONSOLE_DESC=	Console interface
CURSES_DESC=	Curses interface
DEBUG_DESC=	Debug interface
EXAMPLES_DESC=	Example programs
MEMTRACE_DESC=	Internal memory tracking
TEST_DESC=	Internal test program

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix tar:bzip2
USE_AUTOTOOLS=	aclocal autoconf autoheader automake libtoolize
USE_LDCONFIG=	yes

DATADIR=	${PREFIX}/share/CUnit
DOCSDIR=	${PREFIX}/share/doc/CUnit
EXAMPLESDIR=	${PREFIX}/share/examples/CUnit
PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	*

AUTOMAKE_ARGS=	--add-missing
PATHFIX_MAKEFILEIN=	Makefile.am

AUTOMATED_CONFIGURE_ENABLE=	automated
BASIC_CONFIGURE_ENABLE=	basic
CONSOLE_CONFIGURE_ENABLE=	console
CURSES_CONFIGURE_ENABLE=curses
CURSES_LDFLAGS=		-lcurses
CURSES_USES=		ncurses
DEBUG_CONFIGURE_ENABLE=	debug
EXAMPLES_CONFIGURE_ENABLE=	examples
MEMTRACE_CONFIGURE_ENABLE=	memtrace
TEST_CONFIGURE_ENABLE=	test

post-patch:
	@${REINPLACE_CMD} -e 's|/doc/@PACKAGE@|/share/doc/@PACKAGE@|g' ${WRKSRC}/doc/Makefile.am ${WRKSRC}/doc/headers/Makefile.am
	@${REINPLACE_CMD} -e 's|/@PACKAGE@/Examples/|/examples/@PACKAGE@/|g' ${WRKSRC}/Examples/*/Makefile.am
	@${REINPLACE_CMD} -e 's|CUnit-[A-Z][a-z]*\.[a-z]*|${DATADIR}/&|' ${WRKSRC}/CUnit/Sources/Automated/Automated.c
	@${REINPLACE_CMD} -e '/fprintf/ s|Memory-Dump\.[a-z]*|${DATADIR}/&|' ${WRKSRC}/CUnit/Sources/Framework/MyMem.c

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcunit.so.1.0.1

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>
