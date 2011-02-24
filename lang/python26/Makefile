# New ports collection makefile for:    python26
# Date created:         3 July 2003
# Whom:                 Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	python26
PORTVERSION=	2.6.6
CATEGORIES=	lang python ipv6
MASTER_SITES=	${PYTHON_MASTER_SITES}
MASTER_SITE_SUBDIR=	${PYTHON_MASTER_SITE_SUBDIR}
DISTFILES=	${PYTHON_DISTFILE}

MAINTAINER=	python@FreeBSD.org
COMMENT=	An interpreted object-oriented programming language

DIST_SUBDIR=	python
WRKSRC=		${PYTHON_WRKSRC}/portbld.static
PATCH_WRKSRC=	${PYTHON_WRKSRC}
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../configure # must be relative
CONFIGURE_ENV=	OPT="${CFLAGS}" SVNVERSION="echo freebsd"
MAKE_ENV=	VPATH="${PYTHON_WRKSRC}"
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes
INSTALL_TARGET=	altinstall
MAN1=		${PYTHON_VERSION}.1

USE_PYTHON=	yes
PYTHON_VERSION=	python2.6
PYTHON_NO_DEPENDS=	yes

SHARED_WRKSRC=	${PYTHON_WRKSRC}/portbld.shared
PLIST=		${WRKDIR}/PLIST
PLIST_TEMPLATE?=${PKGDIR}/pkg-plist
PLIST_SUB=	PYVER=${PYTHON_VERSION:S/python//} \
		PYVER_WITHPAT=${PORTVERSION:S/.c/c/}
EXAMPLESDIR=	${PREFIX}/share/examples/${PYTHON_VERSION}
DATADIR=	${PREFIX}/share/${PYTHON_VERSION}

PLATFORMS=	plat-freebsd6 plat-freebsd7 plat-freebsd8 plat-freebsd9

BIN_SCRIPTS=	2to3 idle pydoc smtpd.py
BIN_FILES=	python python-shared python-config python-shared-config \
		${BIN_SCRIPTS}
BINLINKS_SUB=	-e 's,smtpd,smtpd${PYTHON_VER},' \
		-e 's,2to3,2to3-${PYTHON_VER},' \
		-e 's,(idle|pydoc|python-shared|python),\1${PYTHON_VER},'

OPTIONS=	THREADS "Enable thread support" on \
		HUGE_STACK_SIZE "Use a larger thread stack" off \
		SEM "Use POSIX semaphores (experimental)" off \
		PTH "Use GNU Pth for threading/multiprocessing" off \
		UCS4 "Use UCS4 for unicode support" on \
		PYMALLOC "Use python's internal malloc" on \
		IPV6 "Enable IPv6 support" on \
		FPECTL "Enable floating point exception handling" off

.include <bsd.port.pre.mk>

.if defined(WITH_SEM)
.if ${OSVERSION} >= 701106
SEM_MSG=	""
.else
IGNORE=		POSIX semaphore support only works in FreeBSD 7-STABLE and later
.endif # ${OSVERSION} >= 701106
.else # !defined(WITH_SEM)
SEM_MSG=	"@comment "
.endif # defined(WITH_SEM)

SUB_FILES=	pkg-message
SUB_LIST=	SEM=${SEM_MSG}

.if ${PYTHON_VERSION} == ${PYTHON_DEFAULT_VERSION} || !exists(${LOCALBASE}/bin/python)
MLINKS=		${PYTHON_VERSION}.1 python.1
PLIST_SUB+=	IF_DEFAULT=""
.else
PLIST_SUB+=	IF_DEFAULT="@comment "
.endif

# workaround for a bug in base curses.h.
CFLAGS+=	-D__wchar_t=wchar_t

.if !defined(WITHOUT_THREADS)
.if defined(WITH_PTH)
CONFIGURE_ARGS+=	--with-pth
EXTRA_PATCHES+=		${PATCHDIR}/extra-patch-configure-pth
LIB_DEPENDS+=		pth:${PORTSDIR}/devel/pth
_PTH_CPPFLAGS=		"-I${LOCALBASE}/include/pth"
_PTH_LDFLAGS=		"-L${LOCALBASE}/lib/pth"
CONFIGURE_ENV+=		CPPFLAGS="${_PTH_CPPFLAGS} ${CPPFLAGS}"
CONFIGURE_ENV+=		LDFLAGS="${_PTH_LDFLAGS} ${LDFLAGS}"
.else # !defined(WITH_PTH)
CONFIGURE_ARGS+=	--with-threads
CFLAGS+=		${PTHREAD_CFLAGS}
CONFIGURE_ENV+=		LDFLAGS="${PTHREAD_LIBS} ${LDFLAGS}"
.endif # defined(WITH_PTH)
.if defined(WITHOUT_HUGE_STACK_SIZE)
CFLAGS+=		-DTHREAD_STACK_SIZE=0x20000
.else
CFLAGS+=		-DTHREAD_STACK_SIZE=0x100000
.endif # defined(WITHOUT_HUGE_STACK_SIZE)
.else # defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=	--without-threads
.if defined(LDFLAGS)
CONFIGURE_ENV+=		LDFLAGS="${LDFLAGS}"
.endif # defined(LDFLAGS)
.endif # !defined(WITHOUT_THREADS)

.if !defined(WITHOUT_UCS4) && !defined(WITH_UCS2)
CONFIGURE_ARGS+=	--enable-unicode=ucs4
.endif

.if defined(WITHOUT_PYMALLOC)
CONFIGURE_ARGS+=	--without-pymalloc
.endif

.if ${ARCH} == amd64 || ${ARCH} == ia64 || ${ARCH} == sparc64 || ${ARCH} == alpha
PLIST_SUB+=	32BIT_ONLY="@comment "
.else
PLIST_SUB+=	32BIT_ONLY=""
.endif
.if ${ARCH} == sparc64
CFLAGS+=	-DPYTHON_DEFAULT_RECURSION_LIMIT=900
.endif

.if !exists(/usr/bin/ypcat) # the world with NO_NIS
PLIST_SUB+=	NO_NIS="@comment "
.else
PLIST_SUB+=	NO_NIS=""
.endif

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(WITH_FPECTL)
CONFIGURE_ARGS+=	--with-fpectl
.endif

pre-patch:
	${CP} -r ${PATCH_WRKSRC}/Lib/plat-freebsd8 \
		${PATCH_WRKSRC}/Lib/plat-freebsd9
	${MKDIR} ${WRKSRC} ${SHARED_WRKSRC}/Modules
	${LN} ${PATCH_WRKSRC}/Lib/smtpd.py ${PATCH_WRKSRC}/Tools/scripts/
.for script in ${BIN_SCRIPTS}
	${SED} -e '1s,^.*$$,#!${PREFIX}/bin/${PYTHON_VERSION},' \
		${PATCH_WRKSRC}/Tools/scripts/${script} \
		> ${WRKDIR}/`${ECHO_CMD} ${script} | ${SED} -E ${BINLINKS_SUB}`
.endfor
	${REINPLACE_CMD} -e \
		's,/usr/doc/python-docs-,${PREFIX}/share/doc/python,g' \
		${PATCH_WRKSRC}/Lib/pydoc.py
	${REINPLACE_CMD} -e \
		's|^\( *prefixes = .*\)\]$$|\1, "${LOCALBASE}"]|g' \
		${PATCH_WRKSRC}/Lib/site.py
	${REINPLACE_CMD} -e \
		's|^	\(..ASDLGEN.*\)$$|	${TRUE}|g; \
		s|[(]LIBDIR[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${PATCH_WRKSRC}/Makefile.pre.in

	${REINPLACE_CMD} -e \
		's|*\(..INSTALL_SCRIPT.*\)python-config$$|#port \1|' \
		${PATCH_WRKSRC}/Makefile.pre.in

	${SED} -e 's|^#!.*|#!${PREFIX}/bin/${PYTHON_VERSION}|' \
		${PATCH_WRKSRC}/Misc/python-config.in > ${WRKDIR}/${PYTHON_VERSION}-config
	${SED} -e 's|^#!.*|#!${PREFIX}/bin/${PYTHON_VERSION:S/thon/thon-shared/}|' \
		${PATCH_WRKSRC}/Misc/python-config.in > ${WRKDIR}/${PYTHON_VERSION:S/thon/thon-shared/}-config

.if defined(WITH_FPECTL) && ${ARCH} == i386
	${MKDIR} ${WRKSRC}/Modules
	${ECHO} "fpectl fpectlmodule.c" >> ${WRKSRC}/Modules/Setup.dist
.endif

post-patch:
.if defined(WITH_SEM)
.if ${OSVERSION} >= 701106
	@cd ${WRKSRC} && ${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-setup.py
.endif
.endif

post-configure:
	${TAR} -C ${WRKSRC} -cf - . | ${TAR} -C ${SHARED_WRKSRC} -xf -
	${LN} -sf ${PYTHON_WRKSRC}/Lib ${WRKSRC}/Lib
	${SED} -e 's,^\(LDLIBRARY=\).*$$,\1libpython$$(VERSION).so,' \
		-e 's,^\(BLDLIBRARY=\).*$$,\1-L. -lpython$$(VERSION),' \
		-e 's,^\(CFLAGSFORSHARED=\).*$$,\1$$(CCSHARED),' \
		-e 's,^\(Makefile Modules/config.c:.*\)Makefile.pre,\1,' \
		-e 's,^\(.(BUILDPYTHON)\: .*\).(LIBRARY),\1,' \
		-e 's,^\(.(BUILDPYTHON):.*\).(LIBRARY),\1,' \
		${WRKSRC}/Makefile > ${SHARED_WRKSRC}/Makefile

pre-build:
	cd ${SHARED_WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${MAKE} lib${PYTHON_VERSION}.so python; \
	${LN} -f lib${PYTHON_VERSION}.so lib${PYTHON_VERSION}.so.1; \
	${LN} -f python ${PYTHON_VERSION:S/thon/thon-shared/}

pre-su-install:
.for platform in ${PLATFORMS}
	${MKDIR} ${PYTHONPREFIX_LIBDIR}/${platform}
.for file in IN.py regen
	${INSTALL_DATA} ${WRKSRC}/Lib/${platform}/${file} \
		${PYTHONPREFIX_LIBDIR}/${platform}/
.endfor
.endfor

pre-install:
	${CAT} ${PLIST_TEMPLATE} | ${AWK} '{ print $$0; } \
	/LIBDIR.*\.py$$/ && \
	!/\/bad|tests\/data/ \
	{ print $$0 "o"; print $$0 "c"; }'      > ${PLIST}

	@# if openssl 0.9.8 is detected, _sha{256,512} module won't be installed
	([ -f ${WRKSRC}/.without_own_sha ] && \
		${GREP} -v 'lib-dynload/_sha' ${PLIST} > ${PLIST}.tmp && \
		${CAT} ${PLIST}.tmp > ${PLIST}) || ${TRUE}

post-install:
	@# install config providers
	${INSTALL_SCRIPT} ${WRKDIR}/${PYTHON_VERSION}-config ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/${PYTHON_VERSION:S/thon/thon-shared/}-config ${PREFIX}/bin

	@# shared version of executable and library
	${INSTALL_PROGRAM} ${SHARED_WRKSRC}/lib${PYTHON_VERSION}.so.1 \
		${PREFIX}/lib
	cd ${PREFIX}/lib; ${LN} -sf lib${PYTHON_VERSION}.so.1 \
		lib${PYTHON_VERSION}.so
	${LN} -sf ${PREFIX}/lib/lib${PYTHON_VERSION}.so ${PYTHONPREFIX_LIBDIR}/config
	${INSTALL_PROGRAM} \
		${SHARED_WRKSRC}/${PYTHON_VERSION:S/thon/thon-shared/} \
		${PREFIX}/bin

	@# additional files installing by ports
.for script in ${BIN_SCRIPTS}
	${INSTALL_SCRIPT} \
		${WRKDIR}/`${ECHO_CMD} ${script} | ${SED} -E ${BINLINKS_SUB}` \
		${PREFIX}/bin
.endfor
	@${MKDIR} ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${PYTHON_WRKSRC}/Misc/python.man \
		${MANPREFIX}/man/man1/${PYTHON_VERSION}.1

.if ${PYTHON_VERSION} == ${PYTHON_DEFAULT_VERSION} || !exists(${LOCALBASE}/bin/python)
	for f in ${BIN_FILES}; do \
		TARGET=`${ECHO_CMD} $$f | ${SED} -E ${BINLINKS_SUB}`; \
		cd ${PREFIX}/bin && ${LN} -f $$TARGET $$f; \
	done
.endif

.if !defined(NOPORTDATA)
	@${MKDIR} ${DATADIR}
	@cd ${PYTHON_WRKSRC}; ${TAR} -cf - Tools | \
		(cd ${DATADIR}; ${TAR} -xf -)
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${PYTHON_WRKSRC}/Demo; ${TAR} -cf - * | \
		(cd ${EXAMPLESDIR}; ${TAR} -xf -)
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
