# $FreeBSD$

PORTNAME=	python33
PORTVERSION=	3.3.2
PORTREVISION=	4
CATEGORIES=	lang python ipv6
MASTER_SITES=	PYTHON
MASTER_SITE_SUBDIR=	${PYTHON_MASTER_SITE_SUBDIR}
DISTFILES=	${PYTHON_DISTFILE}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Interpreted object-oriented programming language

DIST_SUBDIR=	python
WRKSRC=		${PYTHON_WRKSRC}/portbld.static
PATCH_WRKSRC=	${PYTHON_WRKSRC}
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../configure # must be relative
CONFIGURE_ENV=	OPT="" SVNVERSION="echo freebsd"
MAKE_ENV=	VPATH="${PYTHON_WRKSRC}"
USE_LDCONFIG=	yes
INSTALL_TARGET=	altinstall
MAN1=		${PYTHON_VERSION}.1

USE_XZ=		yes
USE_PYTHON=	yes
USES=		gmake
PYTHON_VERSION=	python3.3
PYTHON_NO_DEPENDS=	yes

PYABIVER=	# default empty, for after appending

SHARED_WRKSRC=	${PYTHON_WRKSRC}/portbld.shared
PLIST_SUB=	PYVER=${PYTHON_VERSION:S/python//} \
		PYMAJOR=${PYTHON_MAJOR_VER} \
		PYVER_WITHPAT=${PORTVERSION:S/.rc/rc/} \
		PYABIVER=${PYABIVER}
EXAMPLESDIR=	${PREFIX}/share/examples/${PYTHON_VERSION}
DATADIR=	${PREFIX}/share/${PYTHON_VERSION}

PLATFORMS=	plat-freebsd4 plat-freebsd5 plat-freebsd6 \
		plat-freebsd7 plat-freebsd8 plat-freebsd9 \
		plat-freebsd10 plat-freebsd11

BIN_SCRIPTS=	2to3 idle3 pydoc3
BIN_FILES=	python python-shared python-config python-shared-config \
		${BIN_SCRIPTS}
BINLINKS_SUB=	-e 's,(2to3|idle3|pydoc3),\1-${PYTHON_VER},' \
		-e 's,(python-shared|python),\1${PYTHON_VER},'

OPTIONS_DEFINE=	THREADS PYMALLOC IPV6 FPECTL EXAMPLES NLS
OPTIONS_DEFAULT=	THREADS PYMALLOC IPV6

NLS_DESC=	Enable Gettext support for the locale module

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
LDFLAGS+=	-L${LOCALBASE}/lib
# We use CPPFLAGS over CFLAGS here due to -I ordering causing things like
# elementtree and pyexpat to break with python27, or to silence preprocessor
# complaints with python33
CPPFLAGS+=	-I${LOCALBASE}/include
.else
CONFIGURE_ENV+=	ac_cv_lib_intl_textdomain=no ac_cv_header_libintl_h=no
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTHREADS}
PLIST_SUB+=	THREADS=""
CONFIGURE_ARGS+=	--with-threads
CFLAGS+=		${PTHREAD_CFLAGS}
LDFLAGS+=		${PTHREAD_LIBS}
.else
PLIST_SUB+=	THREADS="@comment "
CONFIGURE_ARGS+=	--without-threads
.endif

.if empty(PORT_OPTIONS:MPYMALLOC)
CONFIGURE_ARGS+=	--without-pymalloc
.else
PYABIVER:=	m${PYABIVER}
.endif

.if ${ARCH} == sparc64
CFLAGS+=	-DPYTHON_DEFAULT_RECURSION_LIMIT=900
.endif

# See http://bugs.freebsd.org/115940
.if !exists(/usr/bin/ypcat) || defined(WITHOUT_NIS) # the world with NO_NIS
PLIST_SUB+=	NO_NIS="@comment "
WITHOUT_NIS?=	detected
.else
PLIST_SUB+=	NO_NIS=""
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MFPECTL}
CONFIGURE_ARGS+=	--with-fpectl
.endif

pre-patch:
	${CP} -r ${PATCH_WRKSRC}/Lib/plat-freebsd8 \
		${PATCH_WRKSRC}/Lib/plat-freebsd9
	${CP} -r ${PATCH_WRKSRC}/Lib/plat-freebsd8 \
		${PATCH_WRKSRC}/Lib/plat-freebsd10
	${CP} -r ${PATCH_WRKSRC}/Lib/plat-freebsd8 \
		${PATCH_WRKSRC}/Lib/plat-freebsd11
	${MKDIR} ${WRKSRC} ${SHARED_WRKSRC}/Modules
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
		s|[(]LIBDIR[)]/pkgconfig|(prefix)/libdata/pkgconfig|g; \
		s|*\(..INSTALL_SCRIPT.*\)python-config$$|#port \1|' \
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
.if defined(WITHOUT_NIS)
	${REINPLACE_CMD} -e \
	    's/disabled_module_list =[^]]*/&, "nis"/' \
		${PATCH_WRKSRC}/setup.py
.endif

post-configure:
	${TAR} -C ${WRKSRC} -cf - . | ${TAR} -C ${SHARED_WRKSRC} -xf -
	${LN} -sf ${PYTHON_WRKSRC}/Lib ${WRKSRC}/Lib
	${SED} -e 's,^\(LDLIBRARY=\).*$$,\1libpython$$(LDVERSION).so,' \
		-e 's,^\(BLDLIBRARY=\).*$$,\1-L. -lpython$$(LDVERSION),' \
		-e 's,^\(CFLAGSFORSHARED=\).*$$,\1$$(CCSHARED),' \
		-e 's,^\(Makefile Modules/config.c:.*\)Makefile.pre,\1,' \
		-e 's,^\(.(BUILDPYTHON)\: .*\).(LIBRARY),\1,' \
		-e 's,^\(.(BUILDPYTHON):.*\).(LIBRARY),\1,' \
		${WRKSRC}/Makefile > ${SHARED_WRKSRC}/Makefile

pre-build:
	cd ${SHARED_WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${MAKE} lib${PYTHON_VERSION}${PYABIVER}.so python; \
	${LN} -f lib${PYTHON_VERSION}${PYABIVER}.so lib${PYTHON_VERSION}${PYABIVER}.so.1; \
	${LN} -f python ${PYTHON_VERSION:S/thon/thon-shared/}

pre-su-install:
.for platform in ${PLATFORMS}
	${MKDIR} ${PYTHONPREFIX_LIBDIR}/${platform}
.for file in IN.py regen
	${INSTALL_DATA} ${WRKSRC}/Lib/${platform}/${file} \
		${PYTHONPREFIX_LIBDIR}/${platform}/
.endfor
.endfor

post-install:
	@# install config providers
	${INSTALL_SCRIPT} ${WRKDIR}/${PYTHON_VERSION}-config ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/${PYTHON_VERSION:S/thon/thon-shared/}-config ${PREFIX}/bin

	@# shared version of executable and library
	${INSTALL_PROGRAM} ${SHARED_WRKSRC}/lib${PYTHON_VERSION}${PYABIVER}.so.1 \
		${PREFIX}/lib
	cd ${PREFIX}/lib; ${LN} -sf lib${PYTHON_VERSION}${PYABIVER}.so.1 \
		lib${PYTHON_VERSION}${PYABIVER}.so
	${LN} -sf ${PREFIX}/lib/lib${PYTHON_VERSION}${PYABIVER}.so ${PYTHONPREFIX_LIBDIR}/config
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

.if !defined(NOPORTDATA)
	@${MKDIR} ${DATADIR}
	@cd ${PYTHON_WRKSRC}; ${TAR} -cf - Tools | \
		(cd ${DATADIR}; ${TAR} -xf -)
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
