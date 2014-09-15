# Created by: Takanori Sawada <tak.swd@gmail.com>
# $FreeBSD$

PORTNAME=	c-unit
DISTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	tak.swd@gmail.com
COMMENT=	Unit testing framework for C

LICENSE=	LGPL20

CONFLICTS=	cunit-[0-9]*

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix
USE_AUTOTOOLS=	aclocal autoconf autoheader automake libtoolize
USE_LDCONFIG=	yes

DATADIR=	${PREFIX}/share/CUnit
EXAMPLESDIR=	${PREFIX}/share/examples/CUnit

AUTOMAKE_ARGS=	--add-missing
PATHFIX_MAKEFILEIN=	Makefile.am

OPTIONS_DEFINE=		AUT BAS CON CUR DEB EXA ITE MEM
OPTIONS_DEFAULT=	AUT BAS CON
OPTIONS_SUB=		yes
AUT_DESC=	Automated(XML) interface
BAS_DESC=	Basic interface
CON_DESC=	Console interface
CUR_DESC=	Curses interface
DEB_DESC=	Debug interface
EXA_DESC=	Example programs
ITE_DESC=	Internal test program
MEM_DESC=	Internal memory tracking

AUT_CONFIGURE_ENABLE=	automated
BAS_CONFIGURE_ENABLE=	basic
CON_CONFIGURE_ENABLE=	console
CUR_CONFIGURE_ENABLE=	curses
CUR_LDFLAGS=		-lcurses
CUR_USES=		ncurses
DEB_CONFIGURE_ENABLE=	debug
EXA_CONFIGURE_ENABLE=	examples
ITE_CONFIGURE_ENABLE=	test
MEM_CONFIGURE_ENABLE=	memtrace

post-patch:
	@${REINPLACE_CMD} -e 's|/doc/@PACKAGE@|/share/doc/@PACKAGE@|g' ${WRKSRC}/doc/Makefile.am ${WRKSRC}/doc/headers/Makefile.am
	@${REINPLACE_CMD} -e 's|/@PACKAGE@/Examples/|/examples/@PACKAGE@/|g' ${WRKSRC}/Examples/*/Makefile.am

.include <bsd.port.mk>
