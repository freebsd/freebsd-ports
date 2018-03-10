# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pcsc-ada
PORTVERSION=	0.7.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.codelabs.ch/download/
DISTNAME=	libpcscada-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ada binding to PC/SC middleware (Smart card interface)

LICENSE=	LGPL21

LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite

USES=		ada tar:bzip2
ALL_TARGET=	all
GPRLINK=	"-L${LOCALBASE}/lib", "-lpcsclite"
MAKE_ARGS+=	NUM_CPUS=${MAKE_JOBS_NUMBER} \
		LIBRARY_KIND=static
PORTEXAMPLES=	src bin

OPTIONS_DEFINE=	UNIT_TEST INTF_TEST DOCS EXAMPLES
OPTIONS_SUB=	yes
UNIT_TEST_DESC= Run unit test suite before installation
INTF_TEST_DESC= Run interface tests against installed smart card after build
NO_OPTIONS_SORT=yes

DOCS_USES=		gmake

DOCS_BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
			source-highlight:textproc/source-highlight
UNIT_TEST_BUILD_DEPENDS=${LOCALBASE}/lib/gnat/ahven.gpr:devel/ahven
INTF_TEST_BUILD_DEPENDS=${LOCALBASE}/lib/gnat/ahven.gpr:devel/ahven

DOCS_ALL_TARGET=	doc
EXAMPLES_ALL_TARGET=	examples
UNIT_TEST_ALL_TARGET=	utests
INTF_TEST_ALL_TARGET=	itests

post-patch:
	${REINPLACE_CMD} -e 's|"-lpcsclite"|${GPRLINK}|' \
		${WRKSRC}/pcscada_common.gpr \
		${WRKSRC}/pcscada_lib.gpr

do-build:
#	We cannot use a redefined ALL_TARGET because MAKE_JOBS_SAFE is set
#	for PROCESSORS, but that also sets -j for gmake can break build
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS:NDESTDIR=*} ${ALL_TARGET})

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gnat \
		${STAGEDIR}${PREFIX}/lib/pcscada \
		${STAGEDIR}${PREFIX}/include/pcscada \
		${STAGEDIR}${EXAMPLESDIR}/src \
		${STAGEDIR}${EXAMPLESDIR}/bin \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${PREFIX}/include/pcscada
	${INSTALL_DATA} ${WRKSRC}/lib/static/* \
		${STAGEDIR}${PREFIX}/lib/pcscada
	${INSTALL_DATA} ${FILESDIR}/pcscada.gpr ${STAGEDIR}${PREFIX}/lib/gnat

post-install-DOCS-on:
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR}/src)
	${RM} ${STAGEDIR}${EXAMPLESDIR}/src/*/*.bak
	(cd ${WRKSRC}/obj/examples && ${INSTALL_PROGRAM} cardd pinpad \
		thin_example ${STAGEDIR}${EXAMPLESDIR}/bin)

.include <bsd.port.mk>
