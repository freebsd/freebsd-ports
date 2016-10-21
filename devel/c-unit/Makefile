# Created by: Takanori Sawada <tak.swd@gmail.com>
# $FreeBSD$

PORTNAME=	c-unit
DISTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	tak.swd@gmail.com
COMMENT=	Unit testing framework for C

LICENSE=	LGPL20

BROKEN=		Unfetchable (google code has gone away)

CONFLICTS=	cunit-[0-9]*

GNU_CONFIGURE=	yes
USES=		autoreconf gmake libtool pathfix
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

DATADIR=	${PREFIX}/share/CUnit
EXAMPLESDIR=	${PREFIX}/share/examples/CUnit

OPTIONS_DEFINE=		AUT BAS CON CUR DEB EXA ITE MEM
OPTIONS_DEFAULT=	AUT BAS CON
OPTIONS_SUB=		yes

AUT_DESC=	Automated (XML) interface
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
