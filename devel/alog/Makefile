# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	alog
PORTVERSION=	0.6.1
CATEGORIES=	devel
MASTER_SITES=	http://www.codelabs.ch/download/
DISTNAME=	libalog-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Stackable logging framework for Ada

LICENSE=	LGPL21

BUILD_DEPENDS=	gprbuild:devel/gprbuild

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
DOCS_BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor
DOCS_ALL_TARGET=	doc

TEST_BUILD_DEPENDS=	${LOCALBASE}/lib/gnat/ahven.gpr:devel/ahven
TEST_ALL_TARGET=	tests

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

do-install-DOCS-on:
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
