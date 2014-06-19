# Created by: Gabor Pali <pgj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cppcheck
PORTVERSION=	1.63
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Static analysis of C/C++ code

LICENSE=	GPLv3

LIB_DEPENDS=	libtinyxml2.so:${PORTSDIR}/textproc/tinyxml2

USES=		gmake tar:bzip2

ALL_TARGET=	cppcheck
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	TINYXML=-ltinyxml2

OPTIONS_DEFINE=		MATCHCOMPILER RULES MANPAGES
OPTIONS_DEFAULT=	MATCHCOMPILER RULES MANPAGES

MATCHCOMPILER_DESC=	Build-time optimizations via Python
RULES_DESC=		User-defined rule support (requires PCRE)

PLIST_FILES=	bin/cppcheck bin/cppcheck-htmlreport

.include <bsd.port.options.mk>

.ifndef(NOPORTDATA)
MAKE_ENV+=	CFGDIR="${DATADIR}/cfg"
PORTDATA=	*
.endif

.if ${PORT_OPTIONS:MMANPAGES}
ALL_TARGET+=	man
BUILD_DEPENDS+=	xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl
MAKE_ENV+=	DB2MAN="${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl"

PLIST_FILES+=	man/man1/cppcheck.1.gz

post-install:
	@${INSTALL_MAN} ${WRKSRC}/cppcheck.1 ${STAGEDIR}${PREFIX}/man/man1
.endif

.if ${PORT_OPTIONS:MMATCHCOMPILER}
MAKE_ENV+=		SRCDIR=build
USE_PYTHON_BUILD=	2
.endif

.if ${PORT_OPTIONS:MRULES}
LIB_DEPENDS+=	libpcre.so:${PORTSDIR}/devel/pcre
MAKE_ENV+=	HAVE_RULES=yes
.endif

post-patch:
	@${REINPLACE_CMD} \
	-e 's|-Iexternals -Iexternals/tinyxml|-I${LOCALBASE}/include|' \
		${WRKSRC}/Makefile
.if ${PORT_OPTIONS:MMANPAGES}
	@${REINPLACE_CMD} -e '\|DB2MAN=|d' \
		${WRKSRC}/Makefile
.endif
.if ${PORT_OPTIONS:MMATCHCOMPILER}
	@${REINPLACE_CMD} -e 's|python|${PYTHON_CMD}|' \
		${WRKSRC}/Makefile
.endif
.if ${PORT_OPTIONS:MRULES}
	@${REINPLACE_CMD} \
	-e '\|CXXFLAGS +=| \
	s| -DTIXML_USE_STL $$(shell pcre-config --cflags)||' \
	-e '\|$$(SRCDIR)/cppcheck.cpp| \
	s|$${INCLUDE_FOR_LIB}|& $$(shell pcre-config --cflags)|' \
			${WRKSRC}/Makefile
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cppcheck ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/htmlreport/cppcheck-htmlreport ${STAGEDIR}${PREFIX}/bin
.ifndef(NOPORTDATA)
	@${MKDIR} ${STAGEDIR}${DATADIR}/cfg
	@cd ${WRKSRC}/cfg; ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/cfg/
.endif

check regression-test test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
