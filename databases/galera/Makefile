# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	galera
PORTVERSION=	25.3.5
DISTVERSIONSUFFIX=	-src
CATEGORIES=	databases
MASTER_SITES=	https://launchpadlibrarian.net/170877450/

MAINTAINER=	horia@racoviceanu.com
COMMENT=	Synchronous multi-master replication engine

LICENSE=	GPLv2

BUILD_DEPENDS=	checkmk:${PORTSDIR}/devel/libcheck \
		doxygen:${PORTSDIR}/devel/doxygen \
		${PYTHON_PKGNAMEPREFIX}cloud_sptheme>=0:${PORTSDIR}/textproc/py-cloud_sptheme
LIB_DEPENDS=	libboost_date_time.so:${PORTSDIR}/devel/boost-libs \
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo

USES=		scons shebangfix

USE_CXXSTD=	c++11
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USE_PYTHON=	yes

MAKE_CMD=	${SCONS} -j${MAKE_JOBS_NUMBER} --config=force

SHEBANG_FILES=	docs/sphinx-*

PLIST_FILES=	%%GARB%%bin/garbd \
		lib/libgalera_smm.so \
		lib/libgalera.so

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS README

DOCSRCDIR2=	${DOCSRCDIR1}/docs/build/doc

DOCSRCDIR3=	${DOCSRCDIR1}/galerautils
DOCSDIR3=	${DOCSDIR}/galerautils
DOC_FILES3=	ChangeLog README

DOCSRCDIR4=	${DOCSRCDIR1}/gcache
DOCSDIR4=	${DOCSDIR}/gcache
DOC_FILES4=	AUTHORS README

DOCSRCDIR5=	${DOCSRCDIR1}/gcs
DOCSDIR5=	${DOCSDIR}/gcs
DOC_FILES5=	ChangeLog README doc/*.txt doc/*.odt doc/*.png

OPTIONS_DEFINE=	BOOSTPOOL BPOSTATIC DEBUG DOCS GARB TEST
OPTIONS_GROUP=	DOCS
OPTIONS_GROUP_DOCS=	EPUB JSON LATEX PICKLE
OPTIONS_DEFAULT=GARB
OPTIONS_SUB=	yes

BOOSTPOOL_DESC=	Use boost pool allocator
BPOSTATIC_DESC=	Use static boost_program_options
EPUB_DESC=	EPUB support
PICKLE_DESC=	Pickle support
GARB_DESC=	Galera Arbitrator

GARB_USE=	RC_SUBR=garb

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 1000000
BUILD_DEPENDS+=	asio>=0:${PORTSDIR}/net/asio
RUN_DEPENDS:=	${BUILD_DEPENDS}
.else
USE_GCC=	yes
.endif

.if ${OSVERSION} < 900506
IGNORE=	need __WORDSIZE found in FreeBSD 9
.endif

.if ${PORT_OPTIONS:MBOOSTPOOL}
MAKE_CMD+=	boost_pool=1
.endif

.if ${PORT_OPTIONS:MBPOSTATIC}
MAKE_CMD+=	bpostatic=${PREFIX}/lib/libboost_program_options.so
.endif

.if ${PORT_OPTIONS:MDEBUG}
MAKE_CMD+=	debug=3
.endif

.if ${PORT_OPTIONS:MGARB}
SUB_LIST=	LD_LIBRARY_PATH=${LOCALBASE}/lib/${CC}:$$LD_LIBRARY_PATH
.endif

post-patch:
	@${REINPLACE_CMD} -e '/-Werror/d' ${WRKSRC}/SConstruct

.if ${OSVERSION} > 1000000
	@${REINPLACE_CMD} -e '/#\/asio/d' ${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e 's|LLONG_MAX|gu::LOG_MAX|' \
		${WRKSRC}/galera/src/monitor.hpp
.endif

.if ! ${PORT_OPTIONS:MGARB}
	@${REINPLACE_CMD} -e "s|'galera/SConscript',|'galera/SConscript'])|; \
		/'garb\/SConscript'])/d" ${WRKSRC}/SConscript
.endif

	@${REINPLACE_CMD} -e "s|'tests', 1|'tests', 0|" ${WRKSRC}/SConstruct

.if ! ${PORT_OPTIONS:MTEST}
	@${REINPLACE_CMD} -e 's| tests/SConscript||' \
		${WRKSRC}/galerautils/SConscript ${WRKSRC}/gcache/SConscript
	@${REINPLACE_CMD} -e "s|, 'tests/SConscript'||" \
		${WRKSRC}/galera/SConscript
.endif

	@${REINPLACE_CMD} -e "s|\[u'Codership Oy'\], 1|\[u'Codership Oy'\], 8|" \
		${WRKSRC}/docs/pasture/source/conf.py

.for d in galerautils gcomm gcs
	@${REINPLACE_CMD} -e 's|= ./|= ../../docs/build/doc/${d}|; \
		s|= man|= ../../man|' ${WRKSRC}/${d}/doc/Doxyfile

. if ! ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${WRKSRC}/docs/build/doc/${d}
	@${REINPLACE_CMD} -e '/GENERATE_HTML / s|YES|NO|' \
		${WRKSRC}/${d}/doc/Doxyfile
. elif ${PORT_OPTIONS:MLATEX}
	@${REINPLACE_CMD} -e '/GENERATE_LATEX/ s|NO|YES|; s|= a4wide|= a4|; \
		/LATEX_OUTPUT/ s|latex|&|' ${WRKSRC}/${d}/doc/Doxyfile
. endif
.endfor

post-build:
	@(cd ${BUILD_WRKSRC}/docs && sphinx-build -a -b man \
		-d build/doctrees source build/man/man1)
	@(cd ${BUILD_WRKSRC}/docs && sphinx-build -a -b man \
		-d build/doctrees/pasture pasture/source build/man/man8)

.if ${PORT_OPTIONS:MDOCS}
	@(cd ${BUILD_WRKSRC}/docs && sphinx-build -a -b html \
		-d build/doctrees source build/doc/galera/html)
	@(cd ${BUILD_WRKSRC}/docs && sphinx-build -a -b text \
		-d build/doctrees source build/doc/galera/text)
	@(cd ${BUILD_WRKSRC}/docs && sphinx-build -a -b html \
		-d build/doctrees/pasture pasture/source build/doc/pasture/html)
	@(cd ${BUILD_WRKSRC}/docs && sphinx-build -a -b text \
		-d build/doctrees/pasture pasture/source build/doc/pasture/text)

. if ${PORT_OPTIONS:MEPUB}
	@(cd ${BUILD_WRKSRC}/docs && sphinx-build -a -b epub \
		-d build/doctrees source build/doc/galera/epub)
	@(cd ${BUILD_WRKSRC}/docs && sphinx-build -a -b epub \
		-d build/doctrees/pasture pasture/source build/doc/pasture/epub)
. endif

. if ${PORT_OPTIONS:MJSON}
	@(cd ${BUILD_WRKSRC}/docs && sphinx-build -a -b json \
		-d build/doctrees source build/doc/galera/json)
	@(cd ${BUILD_WRKSRC}/docs && sphinx-build -a -b json \
		-d build/doctrees/pasture pasture/source build/doc/pasture/json)
. endif

. if ${PORT_OPTIONS:MLATEX}
	@(cd ${BUILD_WRKSRC}/docs && sphinx-build -a -b latex \
		-d build/doctrees source build/doc/galera/latex)
	@(cd ${BUILD_WRKSRC}/docs && sphinx-build -a -b latex \
		-d build/doctrees/pasture pasture/source \
		build/doc/pasture/latex)
. endif

. if ${PORT_OPTIONS:MPICKLE}
	@(cd ${BUILD_WRKSRC}/docs && sphinx-build -a -b pickle \
		-d build/doctrees source build/doc/galera/pickle)
	@(cd ${BUILD_WRKSRC}/docs && sphinx-build -a -b pickle \
		-d build/doctrees/pasture \
		pasture/source build/doc/pasture/pickle)
. endif
.endif

	@(cd ${BUILD_WRKSRC}/galerautils/doc && doxygen Doxyfile)
	@(cd ${BUILD_WRKSRC}/gcomm/doc && doxygen Doxyfile)
	@(cd ${BUILD_WRKSRC}/gcs/doc && doxygen Doxyfile)

do-install:
	${INSTALL_LIB} ${WRKDIR}/${DISTNAME}/libgalera_smm.so \
		${STAGEDIR}${PREFIX}/lib/
	@(cd ${STAGEDIR}${PREFIX}/lib && ${LN} -sf libgalera_smm.so \
		libgalera.so)

.if ${PORT_OPTIONS:MGARB}
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/garb/garbd \
		${STAGEDIR}${PREFIX}/bin/
.endif

	@(cd ${WRKSRC}/docs/build/man/man1 && ${INSTALL_MAN} \
		${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/)
	@(cd ${WRKSRC}/docs/build/man/man3 && ${RM} _*.3 && ${INSTALL_MAN} \
		*.3 ${STAGEDIR}${MAN3PREFIX}/man/man3/)
	@(cd ${WRKSRC}/docs/build/man/man8 && ${INSTALL_MAN} \
		${PORTNAME}.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/)

	@cd ${STAGEDIR}${MANPREFIX} && \
		${FIND} -H -s man/man*/ -maxdepth 1 -type f -print | \
		${SED} 's|$$|.gz|' >> ${TMPPLIST}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DOCSDIR4}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	(cd ${DOCSRCDIR2} && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${DOC_FILES3:S|^|${DOCSRCDIR3}/|} ${STAGEDIR}${DOCSDIR3}
	${INSTALL_DATA} ${DOC_FILES4:S|^|${DOCSRCDIR4}/|} ${STAGEDIR}${DOCSDIR4}
	${INSTALL_DATA} ${DOC_FILES5:S|^|${DOCSRCDIR5}/|} ${STAGEDIR}${DOCSDIR5}
.endif

.include <bsd.port.post.mk>
