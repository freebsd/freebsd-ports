# New ports collection makefile for:    python-devel
# Date created:         3 July 2003
# Whom:                 Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	python
PORTVERSION=	2.4.a0.20040311
CATEGORIES=	lang python ipv6
MASTER_SITES=	${PYTHON_MASTER_SITES}
MASTER_SITE_SUBDIR=	${PYTHON_MASTER_SITE_SUBDIR}
DISTFILES=	${PYTHON_DISTFILE}

MAINTAINER=	perky@FreeBSD.org
COMMENT?=	An interpreted object-oriented programming language

DIST_SUBDIR=	python
WRKSRC=		${PYTHON_WRKSRC}
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-fpectl
CONFIGURE_ENV=	OPT="${CFLAGS}"
MAKE_ENV=	VPATH="${WRKSRC}"
INSTALLS_SHLIB=	yes
INSTALL_TARGET=	altinstall
MAN1=		${PYTHON_VERSION}.1

USE_PYTHON=	yes
USE_REINPLACE=	yes
PYTHON_VERSION=	python2.4
PYTHON_NO_DEPENDS=	yes
LATEST_LINK=	${PYTHON_VERSION:S/.//}

SHARED_WRKSRC=	${WRKSRC}/build.shared
PLIST_SUB=	PYVER=${PYTHON_VERSION:S/python//}
DEMODIR=	${PREFIX}/share/examples/${PYTHON_VERSION}
TOOLSDIR=	${PREFIX}/share/${PYTHON_VERSION}

#
# If you don't want to use Python's thread module, you need to set
# WITHOUT_THREADS.
#
.if !defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=	--with-threads
CFLAGS+=		${PTHREAD_CFLAGS}
.if !defined(WANT_HUGE_STACK_SIZE)
CFLAGS+=		-DTHREAD_STACK_SIZE=0x20000
.else
CFLAGS+=		-DTHREAD_STACK_SIZE=0x100000
.endif # !defined(WANT_HUGE_STACK_SIZE)
CONFIGURE_ENV+=		LDFLAGS="${PTHREAD_LIBS} ${LDFLAGS}"
.else
CONFIGURE_ARGS+=	--without-threads
.if defined(LDFLAGS)
CONFIGURE_ENV+=		LDFLAGS="${LDFLAGS}"
.endif # defined(LDFLAGS)
.endif # !defined(WITHOUT_THREADS)

.if !defined(WITH_UCS2)
CONFIGURE_ARGS+=	--enable-unicode=ucs4
.endif

.if defined(WITHOUT_PYMALLOC)
CONFIGURE_ARGS+=        --without-pymalloc
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
PLIST_SUB+=	X86_ONLY=""
.else
PLIST_SUB+=	X86_ONLY="@comment "
.endif
.if ${ARCH} == amd64 || ${ARCH} == ia64 || ${ARCH} == sparc64 || ${ARCH} == alpha
PLIST_SUB+=     32BIT_ONLY="@comment "
.else
PLIST_SUB+=     32BIT_ONLY=""
.endif
.if ${ARCH} == sparc64
CFLAGS+=        -DPYTHON_DEFAULT_RECURSION_LIMIT=900
.endif

.if ${OSVERSION} < 400000
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
CFLAGS+=	-I${LOCALBASE}/include/ncurses -I${LOCALBASE}/include
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib"
.endif

.if ${OSVERSION} >= 500000 && ${OSVERSION} < 500005
CONFIGURE_ARGS+=	--with-libs='-lxpg4'
.endif
.if ${OSVERSION} < 400020
CONFIGURE_ARGS+=	--with-libs='-lxpg4'
.endif

.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+= --enable-ipv6
.else
CONFIGURE_ARGS+= --disable-ipv6
.endif

.if ${OSVERSION} >= 500000
PLATFORMS=plat-freebsd2 plat-freebsd3 plat-freebsd4
.elif ${OSVERSION} >= 400000
PLATFORMS=plat-freebsd2 plat-freebsd3 plat-freebsd5
.elif ${OSVERSION} >= 300000
PLATFORMS=plat-freebsd2 plat-freebsd4 plat-freebsd5
.else
PLATFORMS=plat-freebsd3 plat-freebsd4 plat-freebsd5
.endif

post-extract:
	${SED} -e '1s,^.*$$,#!${PREFIX}/bin/${PYTHON_VERSION},' \
		${WRKSRC}/Tools/scripts/pydoc > ${WRKDIR}/pydoc2.4
	${SED} -e '1s,^.*$$,#!${PREFIX}/bin/${PYTHON_VERSION},' \
		${WRKSRC}/Tools/scripts/idle > ${WRKDIR}/idle2.4

post-patch:
	${REINPLACE_CMD} -e 's,\(PY_VERSION.*\)2\.4a0,\1${PORTVERSION},g' \
		${WRKSRC}/Include/patchlevel.h
	${REINPLACE_CMD} -e 's,^.*freenet.*$$,,' ${WRKSRC}/Lib/base64.py

post-configure:
	@# prepare a subdir for shared build
.for subdir in Modules Parser Python Objects
	${MKDIR} ${SHARED_WRKSRC}/${subdir}
.endfor
	${SED} -e 's,^\(LDLIBRARY=\).*$$,\1libpython$$(VERSION).so,' \
		-e 's,^\(BLDLIBRARY=\).*$$,\1-L. -lpython$$(VERSION),' \
		-e 's,^\(CFLAGSFORSHARED=\).*$$,\1$$(CCSHARED),' \
		-e 's,^\(Makefile Modules/config.c:.*\)Makefile.pre,\1,' \
		-e 's,^\(.(BUILDPYTHON)\: .*\).(LIBRARY),\1,' \
		-e 's,^\(.(BUILDPYTHON):.*\).(LIBRARY),\1,' \
		${WRKSRC}/Makefile > ${SHARED_WRKSRC}/Makefile
	${LN} -sf ${WRKSRC}/pyconfig.h ${WRKSRC}/Include ${WRKSRC}/Grammar \
		${SHARED_WRKSRC}/
	${LN} -sf ${WRKSRC}/Python/getplatform.c ${WRKSRC}/Python/importdl.c \
		${WRKSRC}/Python/importdl.h \
		${SHARED_WRKSRC}/Python/
	${LN} -sf ${WRKSRC}/Modules/makesetup ${WRKSRC}/Modules/Setup* \
		${WRKSRC}/Modules/*.c ${WRKSRC}/Modules/*.h \
		${SHARED_WRKSRC}/Modules/

post-build:
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

post-install:
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
	${INSTALL_SCRIPT} ${WRKDIR}/pydoc2.4 ${WRKDIR}/idle2.4 \
		${PREFIX}/bin
	@${MKDIR} ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/Misc/python.man \
		${MANPREFIX}/man/man1/${PYTHON_VERSION}.1

.if !defined(NOPORTDOCS)
	@${MKDIR} ${TOOLSDIR}
	@cd ${WRKSRC}; tar -c --exclude='*CVS*' -f - Tools | \
		(cd ${TOOLSDIR}; tar xf -)
	@${MKDIR} ${DEMODIR}
	@cd ${WRKSRC}/Demo; tar -c --exclude='*CVS*' -f - * | \
		(cd ${DEMODIR}; tar xf -)
.endif

.include <bsd.port.post.mk>
