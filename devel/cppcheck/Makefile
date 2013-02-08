# Created by: Gabor Pali <pgj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cppcheck
PORTVERSION=	1.58
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Static analysis of C/C++ code

LICENSE=	GPLv3

LIB_DEPENDS=	tinyxml:${PORTSDIR}/textproc/tinyxml

USE_BZIP2=	yes
USE_GMAKE=	yes

ALL_TARGET=	cppcheck
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib
MAKE_ENV+=	TINYXML=-ltinyxml

OPTIONS_DEFINE=		MATCHCOMPILER RULES
OPTIONS_DEFAULT=	MATCHCOMPILER RULES

MATCHCOMPILER_DESC=	Build-time optimizations via Python
RULES_DESC=		User-defined rule support (requires PCRE)

PLIST_FILES=	bin/cppcheck

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	man
BUILD_DEPENDS+=	xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl
MAKE_ENV+=	DB2MAN="${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl"
MAN1=		cppcheck.1
MANCOMPRESSED=	no

post-install:
	@${INSTALL_MAN} ${WRKSRC}/cppcheck.1 ${PREFIX}/man/man1
.endif

.if ${PORT_OPTIONS:MMATCHCOMPILER}
MAKE_ENV+=		SRCDIR=build
USE_PYTHON_BUILD=	2.6+
.endif

.if ${PORT_OPTIONS:MRULES}
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
MAKE_ENV+=	HAVE_RULES=yes
.endif

post-patch:
	@${REINPLACE_CMD} \
	-e 's|-Iexternals/tinyxml|-I${LOCALBASE}/include|' \
		${WRKSRC}/Makefile
.if ${PORT_OPTIONS:MDOCS}
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
	@${INSTALL_PROGRAM} ${WRKSRC}/cppcheck ${PREFIX}/bin

check regression-test test: build
	@(cd ${BUILD_WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${_MAKE_JOBS} ${MAKE_ARGS} test)

.include <bsd.port.mk>
