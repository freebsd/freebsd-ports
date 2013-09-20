# Created by: Johannes 5 Joemann <joemann@beefree.free.de>
# $FreeBSD$

PORTNAME=	asdlgen
PORTVERSION=	2.0.b20060323
CATEGORIES=	devel haskell java
MASTER_SITES=	http://moby.cs.uchicago.edu/downloads/ \
		ftp://mirror.free.de/http/moby.cs.uchicago.edu/downloads/
DISTFILES=	asdlGen.tar.gz

MAINTAINER=	joemann@beefree.free.de
COMMENT=	Interoperable serializers for C,C++,Haskell,Icon,Java,ML

BUILD_DEPENDS=	smlnj-devel>=110.65:${PORTSDIR}/lang/sml-nj-devel

USE_DOS2UNIX=	src/icon/libasdl.icn

OPTIONS_DEFINE=	CII EXAMPLES
CII_DESC=	libcii for use by generated C and C++ code

OPTIONS_DEFAULT=	CII

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCII}
RUN_DEPENDS+=	libcii>=1.1:${PORTSDIR}/devel/libcii
.endif

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	sgmlfmt:${PORTSDIR}/textproc/sgmlformat
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
DEMOVERSION=	20071030
DEMOARCHIVE=	asdlgen-demo.${DEMOVERSION}.tar.gz
DEMODIR=	arithexp
MASTER_SITES+=	ftp://offshore.free.de/pub/dist/FreeBSD/ports/devel/:demo
DISTFILES+=	${DEMOARCHIVE}:demo
PLIST_SUB+=	EXAMPLES="" DEMODIR=${DEMODIR}
.else
PLIST_SUB+=	EXAMPLES="@comment " DEMODIR=${DEMODIR}
.endif

WRKSRC=		${WRKDIR}/asdlGen
HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	SMLNJ_DEVEL=yes
ALL_TARGET=	build
MAKE_ENV+=	SMLNJ_DEVEL=yes

# Nowadays Java package names must be all lowercase, says JDK1.5. Cf.
# http://java.sun.com/docs/books/tutorial/java/package/namingpkgs.html
pre-patch:
.for dir in StdPkl StdPrims StdTypes
	cd ${WRKSRC}/src/java/asts && [ -d ${dir} ] && ${MV} ${dir} ${dir:L}
.endfor

post-build:
	cd ${WRKSRC}/src/sml && heap2exec asdlGen.*-bsd asdlGen
.if ${PORT_OPTIONS:MDOCS}
.for format in ascii html ps
	@${MKDIR} ${WRKSRC}/doc-build/README
	cd ${WRKSRC}/doc-build/README && \
	sgmlfmt -f ${format} ${WRKSRC}/README.sgml
	@${MKDIR} ${WRKSRC}/doc-build/manual
	cd ${WRKSRC}/doc-build/manual && \
	sgmlfmt -f ${format} ${WRKSRC}/src/doc/manual.sgml
.endfor
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/sml/asdlGen ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/src/asdl/tests && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}
	${INSTALL_DATA} -p ${WRKSRC}/src/asdl/std-types.asdl ${EXAMPLESDIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} -p ${WRKSRC}/COPYRIGHT ${DOCSDIR}
	cd ${WRKSRC}/doc-build && ${COPYTREE_SHARE} \* ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	cd ${WRKDIR}/${DEMODIR} && ${MAKE} clean
	cd ${WRKDIR} && ${COPYTREE_SHARE} ${DEMODIR} ${EXAMPLESDIR}
.endif

# The following test-* targets are used for maintaining this port but
# might be interesting for users exploring different target languages.

.ifmake test-compile || test-demo
BUILD_DEPENDS+=	libcii>=1.1:${PORTSDIR}/devel/libcii \
		hugs:${PORTSDIR}/lang/hugs \
		icont:${PORTSDIR}/lang/icon \
		javac:${PORTSDIR}/java/diablo-jdk15 \
		ocaml:${PORTSDIR}/lang/ocaml

.ifmake test-compile
# This target runs the generate+compile tests from the asdlGen distribution
# for all supported languages. The "Test" structure is defined in
# ${WRKSRC}/src/sml/test/harness.sml .
test-compile:	depends clean-depends build
.if ${PORT_OPTIONS:MCII}
	cd ${WRKSRC}/src/sml && export SMLNJ_DEVEL=yes && \
	${ECHO_CMD} "Test.do_it ();" | sml -m sources.cm
.else
	@${ECHO_CMD} "You have to set the CII option (make config)"
	@${ECHO_CMD} "before you can use the test-compile target."
	@exit 1
.endif
.endif

.ifmake test-demo
test-demo:	clean depends clean-depends build
.if ${PORT_OPTIONS:MCII} && ${PORT_OPTIONS:MEXAMPLES}
	cd ${WRKDIR}/${DEMODIR} && ${MAKE} ASDLGEN=${WRKSRC}/src/sml/asdlGen
.else
	@${ECHO_CMD} "You have to set the CII and EXAMPLES options"
	@${ECHO_CMD} "(make config) before you can use the test-demo target."
	@exit 1
.endif
.endif
.endif

.include <bsd.port.mk>
