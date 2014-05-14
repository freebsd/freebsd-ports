# Created by: Stefan Pauly <stefan@fh-mainz.de>
# $FreeBSD$

PORTNAME=	cunit
PORTVERSION=	2.1.3
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/CUnit/${PORTVERSION:R}-${PORTVERSION:E}
DISTNAME=	CUnit-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Automated unit testing framework for C

LICENSE=	LGPL20

CONFLICTS=	c-unit-[0-9]*

OPTIONS_DEFINE=	AUT BAS CON CUR DEB EXA ITE MEM
OPTIONS_DEFAULT=AUT BAS CON
OPTIONS_SUB=	yes
AUT_DESC=	Automated (XML) interface
BAS_DESC=	Basic interface
CON_DESC=	Console interface
CUR_DESC=	Curses interface
DEB_DESC=	Debug interface
EXA_DESC=	Example programs
ITE_DESC=	Internal test program
MEM_DESC=	Internal memory tracking

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
LIBTOOLIZE_ARGS=--copy --force --install
PATHFIX_MAKEFILEIN=	Makefile.am

AUT_CONFIGURE_ENABLE=	automated
BAS_CONFIGURE_ENABLE=	basic
CON_CONFIGURE_ENABLE=	console
CUR_CONFIGURE_ENABLE=	curses
DEB_CONFIGURE_ENABLE=	debug
EXA_CONFIGURE_ENABLE=	examples
ITE_CONFIGURE_ENABLE=	test
MEM_CONFIGURE_ENABLE=	memtrace

post-patch:
	@${REINPLACE_CMD} -e 's|/doc/@PACKAGE@|/share/doc/@PACKAGE@|g' ${WRKSRC}/doc/Makefile.am ${WRKSRC}/doc/headers/Makefile.am
	@${REINPLACE_CMD} -e 's|/@PACKAGE@/Examples/|/examples/@PACKAGE@/|g' ${WRKSRC}/Examples/*/Makefile.in
	@${REINPLACE_CMD} -e 's|CUnit-[A-Z][a-z]*\.[a-z]*|${DATADIR}/&|' ${WRKSRC}/CUnit/Sources/Automated/Automated.c
	@${REINPLACE_CMD} -e '/fprintf/ s|Memory-Dump\.[a-z]*|${DATADIR}/&|' ${WRKSRC}/CUnit/Sources/Framework/MyMem.c

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcunit.so.1.0.1

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>
