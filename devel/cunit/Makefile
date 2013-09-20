# Created by: Stefan Pauly <stefan@fh-mainz.de>
# $FreeBSD$

PORTNAME=	cunit
DISTVERSION=	2.1-0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/CUnit/2.1-0
DISTNAME=	${PORTNAME:S/^cu/CU/}-${DISTVERSION}-src

MAINTAINER=	stefan@fh-mainz.de
COMMENT=	Automated unit testing framework for C

CONFLICTS=	c-unit-[0-9]*

WRKSRC=	${WRKDIR}/${PORTNAME:S/^cu/CU/}-${DISTVERSION}
DOCSDIR=	${PREFIX}/share/doc/CUnit
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoheader
USE_LDCONFIG=	yes

MAN3=	CUnit.3

OPTIONS_DEFINE=	DEB AUT BAS CON CUR EXA ITE MEM
DEB_DESC=	Debug interface
AUT_DESC=	Automated(XML) interface
BAS_DESC=	Basic interface
CON_DESC=	Console interface
CUR_DESC=	Curses interface
EXA_DESC=	Compile example programs
ITE_DESC=	Compile internal test program
MEM_DESC=	Internal memory tracking

OPTIONS_DEFAULT=	AUT BAS CON

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|/doc/@PACKAGE@|/share/doc/@PACKAGE@|g' ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's|/doc/@PACKAGE@|/share/doc/@PACKAGE@|g' ${WRKSRC}/doc/headers/Makefile.in
	@${REINPLACE_CMD} -e 's|/@PACKAGE@/Examples/Automated|/examples/@PACKAGE@/Automated|g' ${WRKSRC}/Examples/AutomatedTest/Makefile.in
	@${REINPLACE_CMD} -e 's|/@PACKAGE@/Examples/Basic|/examples/@PACKAGE@/Basic|g' ${WRKSRC}/Examples/BasicTest/Makefile.in
	@${REINPLACE_CMD} -e 's|/@PACKAGE@/Examples/Console|/examples/@PACKAGE@/Console|g' ${WRKSRC}/Examples/ConsoleTest/Makefile.in
	@${REINPLACE_CMD} -e 's|/@PACKAGE@/Examples/Curses|/examples/@PACKAGE@/Curses|g' ${WRKSRC}/Examples/CursesTest/Makefile.in
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's|CUnit doc Man Share|CUnit Man Share|g' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEB}
CONFIGURE_ARGS+=	--enable-debug
.endif
.if ${PORT_OPTIONS:MAUT}
PLIST_FILES+=		include/CUnit/Automated.h
.else
CONFIGURE_ARGS+=	--disable-automated
.endif
.if ${PORT_OPTIONS:MBAS}
PLIST_FILES+=		include/CUnit/Basic.h
.else
CONFIGURE_ARGS+=	--disable-basic
.endif
.if ${PORT_OPTIONS:MCON}
PLIST_FILES+=		include/CUnit/Console.h
.else
CONFIGURE_ARGS+=	--disable-console
.endif
.if ${PORT_OPTIONS:MCUR}
CONFIGURE_ARGS+=	--enable-curses
PLIST_FILES+=		include/CUnit/CUCurses.h
.endif
.if ${PORT_OPTIONS:MEXA}
CONFIGURE_ARGS+=	--enable-examples
.if ${PORT_OPTIONS:MAUT}
PLIST_FILES+=		share/examples/CUnit/Automated/AutomatedTest \
			share/examples/CUnit/Automated/README
.endif
.if ${PORT_OPTIONS:MBAS}
PLIST_FILES+=		share/examples/CUnit/Basic/BasicTest \
			share/examples/CUnit/Basic/README
.endif
.if ${PORT_OPTIONS:MCON}
PLIST_FILES+=		share/examples/CUnit/Console/ConsoleTest \
			share/examples/CUnit/Console/README
.endif
.if ${PORT_OPTIONS:MCUR}
PLIST_FILES+=		share/examples/CUnit/Curses/CursesTest \
			share/examples/CUnit/Curses/README
.endif
.endif
.if ${PORT_OPTIONS:MITE}
CONFIGURE_ARGS+=	--enable-test
PLIST_FILES+=		share/CUnit/Test/test_cunit
.endif
.if ${PORT_OPTIONS:MMEM}
CONFIGURE_ARGS+=	--enable-memtrace
.endif

.include <bsd.port.mk>
