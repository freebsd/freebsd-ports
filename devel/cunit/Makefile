# Created by: Stefan Pauly <stefan@fh-mainz.de>
# $FreeBSD$

PORTNAME=	cunit
PORTVERSION=	2.1.3
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/CUnit/${PORTVERSION:R}-${PORTVERSION:E}
DISTNAME=	CUnit-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Automated unit testing framework for C

LICENSE=	LGPL20

CONFLICTS=	c-unit-[0-9]*

OPTIONS_DEFINE=	AUTOMATED BASIC CONSOLE CURSES DEBUG DOCS EXAMPLES MEMTRACE TEST
OPTIONS_DEFAULT=AUTOMATED BASIC CONSOLE CURSES DEBUG MEMTRACE TEST
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
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes
USES=		autoreconf gmake libtool pathfix tar:bzip2

DATADIR=	${PREFIX}/share/CUnit
DOCSDIR=	${PREFIX}/share/doc/CUnit
EXAMPLESDIR=	${PREFIX}/share/examples/CUnit
PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	*

AUTOMATED_CONFIGURE_ENABLE=	automated
BASIC_CONFIGURE_ENABLE=	basic
CONSOLE_CONFIGURE_ENABLE=	console
CURSES_CONFIGURE_ENABLE=curses
CURSES_LDFLAGS=		-lncurses
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

.include <bsd.port.mk>
