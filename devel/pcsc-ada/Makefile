# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pcsc-ada
PORTVERSION=	0.7.2
CATEGORIES=	devel
MASTER_SITES=	http://www.codelabs.ch/download/
DISTNAME=	libpcscada-${PORTVERSION}

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Ada binding to PC/SC middleware (Smart card interface)

LICENSE=	LGPL21

USES=		ada tar:bzip2
ALL_TARGET=	all
GPRLINK=	"-L${LOCALBASE}/lib", "-lpcsclite"
MAKE_ARGS+=	NUM_CPUS=${MAKE_JOBS_NUMBER} \
		LIBRARY_KIND=static

OPTIONS_DEFINE=	UNIT_TEST INTF_TEST DOCS EXAMPLES
OPTIONS_SUB=	yes
UNIT_TEST_DESC= Run unit test suite before installation
INTF_TEST_DESC= Run interface tests against installed smart card after build
NO_OPTIONS_SORT=yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUNIT_TEST} || ${PORT_OPTIONS:MINTF_TEST}
BUILD_DEPENDS+=	${LOCALBASE}/lib/gnat/ahven.gpr:${PORTSDIR}/devel/ahven
. if ${PORT_OPTIONS:MUNIT_TEST}
ALL_TARGET+=	utests
. endif
. if ${PORT_OPTIONS:MINTF_TEST}
ALL_TARGET+=	itests
. endif
.endif

LIB_DEPENDS+=	libpcsclite.so:${PORTSDIR}/devel/pcsc-lite

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+= asciidoc:${PORTSDIR}/textproc/asciidoc \
		source-highlight:${PORTSDIR}/textproc/source-highlight
ALL_TARGET+=	doc
USES+=		gmake
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
ALL_TARGET+=	examples
PORTEXAMPLES=	src bin
.endif

post-patch:
	${REINPLACE_CMD} -e 's|"-lpcsclite"|${GPRLINK}|' \
		${WRKSRC}/pcscada_lib.gpr
	${REINPLACE_CMD} -e 's|gnaty.*|gnatyd",|' ${WRKSRC}/pcscada_common.gpr
	(cd ${WRKSRC} && ${REINPLACE_CMD} -e 's|"-lpcsclite");|"-L${LOCALBASE}/lib"); pragma Linker_Options ("-lpcsclite");|' \
		examples/cardd/cardd.adb \
		examples/sample/sample.adb \
		examples/pinverify/pinpad.adb \
		examples/thin/thin_example.adb \
		tests/runner.adb \
		tests/test_pcscada.adb)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/gnat \
		${STAGEDIR}${PREFIX}/lib/pcscada \
		${STAGEDIR}${PREFIX}/include/pcscada
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${PREFIX}/include/pcscada
	${INSTALL_DATA} ${WRKSRC}/lib/static/* \
		${STAGEDIR}${PREFIX}/lib/pcscada
	${INSTALL_DATA} ${FILESDIR}/pcscada.gpr ${STAGEDIR}${PREFIX}/lib/gnat
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/src ${STAGEDIR}${EXAMPLESDIR}/bin
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR}/src)
	${RM} ${STAGEDIR}${EXAMPLESDIR}/src/*/*.bak
	(cd ${WRKSRC}/obj/examples && ${INSTALL_PROGRAM} cardd pinpad \
		thin_example ${STAGEDIR}${EXAMPLESDIR}/bin)
.endif

.include <bsd.port.mk>
