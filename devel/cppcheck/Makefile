# Created by: Gabor Pali <pgj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cppcheck
PORTVERSION=	1.73
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Static analysis of C/C++ code

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtinyxml2.so:textproc/tinyxml2

USES=		compiler:c++11-lib execinfo gmake tar:bzip2
USE_CXXSTD=	c++11

ALL_TARGET=	cppcheck
TEST_TARGET=	test
LDFLAGS+=	-L${LOCALBASE}/lib -lexecinfo
MAKE_ENV=	TINYXML=-ltinyxml2 CFGDIR="${DATADIR}/cfg"

PLIST_FILES=	bin/cppcheck bin/cppcheck-htmlreport
PORTDATA=	*

OPTIONS_DEFINE=		MATCHCOMPILER RULES MANPAGES
OPTIONS_DEFAULT=	MATCHCOMPILER RULES MANPAGES

MATCHCOMPILER_DESC=	Build-time optimizations via Python
RULES_DESC=		User-defined rule support (requires PCRE)

MANPAGES_ALL_TARGET=	man
MANPAGES_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
			${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl
MANPAGES_MAKE_ENV=	DB2MAN="${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl"
MANPAGES_PLIST_FILES=	man/man1/cppcheck.1.gz

MATCHCOMPILER_MAKE_ENV=	SRCDIR=build
MATCHCOMPILER_USES=	python:2,build

RULES_LIB_DEPENDS=	libpcre.so:devel/pcre
RULES_MAKE_ENV=		HAVE_RULES=yes

post-patch:
	@${REINPLACE_CMD} \
	-e 's|-Iexternals/tinyxml|-I${LOCALBASE}/include|' \
		${WRKSRC}/Makefile

post-patch-MANPAGES-on:
	@${REINPLACE_CMD} -e '\|DB2MAN=|d' \
		${WRKSRC}/Makefile

post-patch-MATCHCOMPILER-on:
	@${REINPLACE_CMD} -e 's|python|${PYTHON_CMD}|' \
		${WRKSRC}/Makefile

post-patch-RULES-on:
	@${REINPLACE_CMD} \
		-e '\|CXXFLAGS +=| \
			s| -DTIXML_USE_STL $$(shell pcre-config --cflags)||' \
		-e '\|$$(SRCDIR)/cppcheck.cpp| \
			s|$${INCLUDE_FOR_LIB}|& $$(shell pcre-config --cflags)|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cppcheck ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/htmlreport/cppcheck-htmlreport ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/cfg
	@cd ${WRKSRC}/cfg; ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/cfg/

do-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/cppcheck.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
