PORTNAME=	uiCA
PORTVERSION=	g20220630+${INSTRVERSION}
CATEGORIES=	benchmarks devel
MASTER_SITES=	https://uops.info/instructions.xml?dummy=/:instructions \
		https://uops.info/:instructions
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${INSTRUCTIONS}:instructions
EXTRACT_ONLY=	${DISTFILES:C,:[^:]*$,,:N*.xml}

MAINTAINER=	fuz@fuz.su
COMMENT=	Code Analyzer from the uops.info project

LICENSE=	AGPLv3 APACHE20
LICENSE_COMB=	multi

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plotly>0:graphics/py-plotly@${PY_FLAVOR}

USES=		compiler python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	andreas-abel
GH_TAGNAME=	ba6ad5557ebd96a10fa0d0e076c9961ec5024574
GH_TUPLE=	andreas-abel:XED-to-XML:c71679ee893ae91db677056d542f305fcc433cb1:xed/XED-to-XML \
		intelxed:mbuild:09b6654be0c52bf1df44e88c88b411a67b624cbd:mbuild/mbuild
USE_PYTHON=	concurrent flavors
SHEBANG_FILES=	uiCA.py

# manually build a file name like instructions_Apr2022.xml from
# the machine-sortable INSTRVERSION.  Use := to have date run only once
INSTRVERSION=	2022.04
INSTRUCTIONS:=	instructions_${LC_ALL=C date -j -f %Y.%m ${INSTRVERSION} +%b%Y:L:sh}.xml

MFLAGS=		--compiler=${COMPILER_TYPE:S/gcc/gnu/} \
		--cc=${CC} \
		--cxx=${CXX} \
		--strip=${STRIP_CMD} \
		--extra-ccflags='${CFLAGS}' \
		--extra-cxxflags='${CXXFLAGS}' \
		--extra-linkflags='${LDFLAGS}'

do-configure:
	${REINPLACE_CMD} -e 's,%%DATADIR%%,${DATADIR},' ${WRKSRC}/uiCA.py

do-build:
	(cd ${WRKSRC}/XED-to-XML && ${PYTHON_CMD} mfile.py ${MFLAGS} --no-encoder pymodule)
	${LN} -f ${WRKSRC}/XED-to-XML/xed.* ${WRKSRC}/
	(cd ${WRKSRC} && ${PYTHON_CMD} convertXML.py ${DISTDIR}/${INSTRUCTIONS})
	${RM} -r ${WRKSRC}/__pycache__
.for f in microArchConfigs.py uiCA.py x64_lib.py instrData
	${PYTHON_CMD} -m compileall ${WRKSRC}/$f
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${PYTHON_LIBDIR}/lib-dynload/
	${INSTALL_DATA} ${WRKSRC}/traceTemplate.html ${STAGEDIR}${DATADIR}/
	${INSTALL_LIB} ${WRKSRC}/xed${PYTHON_EXT_SUFFIX}.so ${STAGEDIR}${PYTHON_LIBDIR}/lib-dynload/
	(cd ${WRKSRC} && ${COPYTREE_SHARE} '__pycache__ instrData microArchConfigs.py x64_lib.py' ${STAGEDIR}${PYTHON_LIBDIR})
	${INSTALL_SCRIPT} ${WRKSRC}/uiCA.py ${STAGEDIR}${PREFIX}/bin/uiCA

.include <bsd.port.mk>
