ATS_IMPL=	anairiats
ATS_VER=	0.2.5

ATS_LIBDIR_REL=	lib/ats-${ATS_IMPL}-${ATS_VER}
ATS_LIBDIR=	${LOCALBASE}/${ATS_LIBDIR_REL}

PLIST_SUB+=	ATS_LIBDIR="${ATS_LIBDIR_REL}"

.if defined(ATS_CTRB)

PKGNAMEPREFIX=	${ATS_CTRBPREFIX}
ATS_CTRBPREFIX=	ats-contrib-
ATS_CTRBEXAMPLEDIR=	${PREFIX}/share/examples/${ATS_CTRBPREFIX}${PORTNAME}

BUILD_DEPENDS+=	${LOCALBASE}/bin/atscc:${PORTSDIR}/lang/ats \
		${NONEXISTENT}:${PORTSDIR}/lang/ats:patch

USE_GMAKE=	yes
MAKE_ENV+=	ATSHOME=${LOCALBASE}
MAKE_ARGS+=	-C contrib/${ATS_CTRB}

ATS_WRKSRC=	cd ${PORTSDIR}/lang/ats; ${MAKE} -V WRKSRC

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -sf $$(${ATS_WRKSRC}) ${WRKDIR}/${DISTNAME}

pre-build:
	${SED} -i '' \
	    -e 's/^ATSCC=\(.*\)/ATSCC=\1 $$(CFLAGS)/' \
	    ${BUILD_WRKSRC}/contrib/${ATS_CTRB}/Makefile
	${LN} -sf ${BUILD_WRKSRC}/contrib ${BUILD_WRKSRC}/contrib/${ATS_CTRB}/

do-install:
	cd ${INSTALL_WRKSRC}/contrib; \
	${FIND} -d ${ATS_CTRB} -type d \
	    -exec ${INSTALL} -d ${ATS_LIBDIR}/contrib/{} \; ; \
	${FIND} ${ATS_CTRB} -type f \
	    -exec ${INSTALL_DATA} {} ${ATS_LIBDIR}/contrib/{} \;
.if !defined(NOPORTEXAMPLES) && defined(ATS_CTRBEXAMPLE)
	cd ${INSTALL_WRKSRC}/doc/EXAMPLE/${ATS_CTRBEXAMPLE}; \
	${FIND} -d . -type d \
	    -exec ${INSTALL} -d ${ATS_CTRBEXAMPLEDIR}/{} \; ; \
	${FIND} . -type f \
	    -exec ${INSTALL_DATA} {} ${ATS_CTRBEXAMPLEDIR}/{} \;
	${FIND} ${ATS_CTRBEXAMPLEDIR} -name Makefile \
	    -exec ${SED} -i '' \
	                 -e 's|^ATSUSRQ=.*|ATSUSRQ="${LOCALBASE}"|' \
	                 -e 's|^ATSLIBQ=.*|ATSLIBQ="${ATS_LIBDIR}"|' {} \;
.endif

post-install-script:
	@${FIND} -ds ${ATS_LIBDIR}/contrib/${ATS_CTRB} -type f -print | \
	    ${SED} -e 's|^${LOCALBASE}/||' >> ${TMPPLIST}
	@${FIND} -ds ${ATS_LIBDIR}/contrib/${ATS_CTRB} -type d -print | \
	    ${SED} -e 's|^${LOCALBASE}/|@dirrm |' >> ${TMPPLIST}
.if !defined(NOPORTEXAMPLES) && defined(ATS_CTRBEXAMPLE)
	@${FIND} -ds ${ATS_CTRBEXAMPLEDIR} -type f -print | \
	    ${SED} -E -e 's|^${PREFIX}/?||' >> ${TMPPLIST}
	@${FIND} -ds ${ATS_CTRBEXAMPLEDIR} -type d -print | \
	    ${SED} -E -e 's|^${PREFIX}/?|@dirrm |' >> ${TMPPLIST}
.endif
	@${ECHO_CMD} '@unexec rmdir %D/${ATS_LIBDIR_REL}/contrib 2>/dev/null || true' >> ${TMPPLIST}
.endif
