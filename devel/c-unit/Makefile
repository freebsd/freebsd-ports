# New ports collection makefile for:	c-unit
# Date created:	 	14 Apr 2012
# Whom: 		Takanori Sawada <tak.swd@gmail.com>
#
# $FreeBSD$

PORTNAME=	c-unit
DISTVERSION=	1.1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	tak.swd@gmail.com
COMMENT=	A unit testing framework for C

CONFLICTS=	cunit-[0-9]*

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoheader
USE_LDCONFIG=	yes

MAN3=		CUnit.3

OPTIONS=	DEB "Enable debug interface" Off \
		AUT "Enable automated(XML) interface" On \
		BAS "Enable basic interface" On \
		CON "Enable console interface" On \
		CUR "Enable curses interface" Off \
		EXA "Compile example programs" Off \
		ITE "Compile internal test program" Off \
		MEM "Enable internal memory tracking" Off
#		DEP "Enable use of deprecated v1.1 names" Off

post-patch:
	@${REINPLACE_CMD} \
		's|/@PACKAGE@/Examples/Automated|/examples/@PACKAGE@/Automated|g' \
		${WRKSRC}/Examples/AutomatedTest/Makefile.in
	@${REINPLACE_CMD} \
		's|/@PACKAGE@/Examples/Basic|/examples/@PACKAGE@/Basic|g' \
		${WRKSRC}/Examples/BasicTest/Makefile.in
	@${REINPLACE_CMD} \
		's|/@PACKAGE@/Examples/Console|/examples/@PACKAGE@/Console|g' \
		${WRKSRC}/Examples/ConsoleTest/Makefile.in
	@${REINPLACE_CMD} \
		's|/@PACKAGE@/Examples/Curses|/examples/@PACKAGE@/Curses|g' \
		${WRKSRC}/Examples/CursesTest/Makefile.in

.include <bsd.port.pre.mk>

.if defined(WITH_DEB)
CONFIGURE_ARGS+=	--enable-debug
.endif
.if defined(WITHOUT_AUT)
CONFIGURE_ARGS+=	--disable-automated
.else
PLIST_FILES+=		include/CUnit/Automated.h
.endif
.if defined(WITHOUT_BAS)
CONFIGURE_ARGS+=	--disable-basic
.else
PLIST_FILES+=		include/CUnit/Basic.h
.endif
.if defined(WITHOUT_CON)
CONFIGURE_ARGS+=	--disable-console
.else
PLIST_FILES+=		include/CUnit/Console.h
.endif
.if defined(WITH_CUR)
CONFIGURE_ARGS+=	--enable-curses
PLIST_FILES+=		include/CUnit/CUCurses.h
.endif
.if defined(WITH_EXA)
CONFIGURE_ARGS+=	--enable-examples
.if defined(WITH_AUT)
PLIST_FILES+=		share/examples/CUnit/Automated/AutomatedTest \
			share/examples/CUnit/Automated/README
.endif
.if defined(WITH_BAS)
PLIST_FILES+=		share/examples/CUnit/Basic/BasicTest \
			share/examples/CUnit/Basic/README
.endif
.if defined(WITH_CON)
PLIST_FILES+=		share/examples/CUnit/Console/ConsoleTest \
			share/examples/CUnit/Console/README
.endif
.if defined(WITH_CUR)
PLIST_FILES+=		share/examples/CUnit/Curses/CursesTest \
			share/examples/CUnit/Curses/README
.endif
.endif
.if defined(WITH_ITE)
CONFIGURE_ARGS+=	--enable-test
PLIST_FILES+=		share/CUnit/Test/test_cunit
.endif
.if defined(WITH_MEM)
CONFIGURE_ARGS+=	--enable-memtrace
.endif
#.if defined(WITH_DEP)
#CONFIGURE_ARGS+=	--enable-deprecated
#.endif

.include <bsd.port.post.mk>
