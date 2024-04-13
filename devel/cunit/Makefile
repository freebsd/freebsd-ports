PORTNAME=	cunit
PORTVERSION=	2.1.3
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/cunit/CUnit/${PORTVERSION:R}-${PORTVERSION:E}
DISTNAME=	CUnit-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Automated unit testing framework for C
WWW=		https://cunit.sourceforge.net/

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake libtool ncurses pathfix tar:bzip2

CONFIGURE_ARGS=	--enable-automated --enable-basic --enable-console --enable-curses --enable-debug --enable-memtrace --enable-test
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
LDFLAGS+=	-lncurses
TEST_TARGET=	check
USE_LDCONFIG=	yes

DATADIR=	${PREFIX}/share/CUnit
DOCSDIR=	${PREFIX}/share/doc/CUnit
EXAMPLESDIR=	${PREFIX}/share/examples/CUnit

CONFLICTS_INSTALL=	c-unit

OPTIONS_DEFINE=	DOCS EXAMPLES

EXAMPLES_CONFIGURE_ENABLE=	examples

post-patch:
	@${REINPLACE_CMD} -e 's|/doc/@PACKAGE@|/share/doc/@PACKAGE@|g' ${WRKSRC}/doc/Makefile.am ${WRKSRC}/doc/headers/Makefile.am
	@${REINPLACE_CMD} -e 's|/@PACKAGE@/Examples/|/examples/@PACKAGE@/|g' ${WRKSRC}/Examples/*/Makefile.am
	@${REINPLACE_CMD} -e 's|CUnit-[A-Z][a-z]*\.[a-z]*|${DATADIR}/&|' ${WRKSRC}/CUnit/Sources/Automated/Automated.c
	@${REINPLACE_CMD} -e '/fprintf/ s|Memory-Dump\.[a-z]*|${DATADIR}/&|' ${WRKSRC}/CUnit/Sources/Framework/MyMem.c

.include <bsd.port.mk>
