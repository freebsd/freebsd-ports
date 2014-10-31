# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	alog
PORTVERSION=	0.5.0
CATEGORIES=	devel
MASTER_SITES=	http://www.codelabs.ch/download/
DISTNAME=	libalog-${PORTVERSION}

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Stackable logging framework for Ada

LICENSE=	LGPL21

BUILD_DEPENDS=	gprbuild:${PORTSDIR}/devel/gprbuild

USES=		ada tar:bzip2
ALL_TARGET=	all
PORTDOCS=	html
MAKE_ARGS+=	NUM_CPUS=${MAKE_JOBS_NUMBER} \
		LIBRARY_KIND=static

OPTIONS_DEFINE=	TEST DOCS
OPTIONS_SUB=	yes
TEST_DESC=	Run unit test suite before installation
NO_OPTIONS_SORT=yes

DOCS_USES=		gmake
DOCS_BUILD_DEPENDS=	asciidoc:${PORTSDIR}/textproc/asciidoc \
			source-highlight:${PORTSDIR}/textproc/source-highlight
TEST_BUILD_DEPENDS=	${LOCALBASE}/lib/gnat/ahven.gpr:${PORTSDIR}/devel/ahven

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTEST}
ALL_TARGET+=	tests
.endif

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	doc
.endif

post-patch:
	${REINPLACE_CMD} -e '/^NUM_CPUS/d' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's/\(not-allowed\)/NONEXISTENT\/\1/' \
		${WRKSRC}/tests/facility_tests-fd.adb

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/gnat \
		${STAGEDIR}${PREFIX}/lib/alog \
		${STAGEDIR}${PREFIX}/include/alog \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${PREFIX}/include/alog
	${INSTALL_DATA} ${WRKSRC}/lib/*/*.ali ${STAGEDIR}${PREFIX}/lib/alog
	${INSTALL_DATA} ${WRKSRC}/gnat/alog.gpr ${STAGEDIR}${PREFIX}/lib/gnat
	${INSTALL_DATA} ${WRKSRC}/lib/*/libalog.a ${STAGEDIR}${PREFIX}/lib/alog
.if ${PORT_OPTIONS:MDOCS}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
