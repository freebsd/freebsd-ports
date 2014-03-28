# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	alog
PORTVERSION=	0.4.1
CATEGORIES=	devel
MASTER_SITES=	http://www.codelabs.ch/download/
DISTNAME=	libalog-${PORTVERSION}

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Stackable logging framework for Ada

LICENSE=	LGPL21

USES=		ada tar:bzip2
ALL_TARGET=	all
MAKE_ARGS+=	NUM_CPUS=${MAKE_JOBS_NUMBER} \
		LIBRARY_KIND=static

OPTIONS_DEFINE=	FULL TEST DOCS
OPTIONS_SUB=	yes
TEST_DESC=	Run unit test suite before installation
FULL_DESC=	Full capabilities (requires PGSQL and AWS)
NO_OPTIONS_SORT=yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTEST}
BUILD_DEPENDS+=	${LOCALBASE}/lib/gnat/ahven.gpr:${PORTSDIR}/devel/ahven
ALL_TARGET+=	tests
.endif

.if ${PORT_OPTIONS:MFULL}
MAKE_ENV+=	TARGET=full
BUILD_DEPENDS+=	apq-pgsql>0:${PORTSDIR}/databases/apq-pgsql \
		aws>0:${PORTSDIR}/www/aws
.endif

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+= asciidoc:${PORTSDIR}/textproc/asciidoc \
		source-highlight:${PORTSDIR}/textproc/source-highlight
ALL_TARGET+=	doc
USES+=		gmake
.endif

post-patch:
	${REINPLACE_CMD} -e '/^NUM_CPUS/d' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's/\(not-allowed\)/NONEXISTENT\/\1/' \
		${WRKSRC}/tests/facility_tests-fd.adb
	${REINPLACE_CMD} -e "s|\.Linker_Switches;|.Linker_Switches \& (\"-R`gnatls -v|awk '/adalib/ {print $$1}'`\");|" \
		${WRKSRC}/alog_full_tests.gpr

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/gnat \
		${STAGEDIR}${PREFIX}/lib/alog \
		${STAGEDIR}${PREFIX}/include/alog
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${PREFIX}/include/alog
	${INSTALL_DATA} ${WRKSRC}/lib/*/*.ali ${STAGEDIR}${PREFIX}/lib/alog
	${INSTALL_DATA} ${WRKSRC}/gnat/alog.gpr ${STAGEDIR}${PREFIX}/lib/gnat
	${INSTALL_DATA} ${WRKSRC}/lib/*/libalog.a ${STAGEDIR}${PREFIX}/lib/alog
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
