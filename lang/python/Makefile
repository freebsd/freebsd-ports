# New ports collection makefile for:    python
# Date created:         08 August 1995
# Whom:                 jkh
#
# $FreeBSD$
#

PORTNAME=	python
PORTVERSION=	2.4.1
PORTREVISION=	3
CATEGORIES=	lang python ipv6
MASTER_SITES=	${PYTHON_MASTER_SITES}
MASTER_SITE_SUBDIR=	${PYTHON_MASTER_SITE_SUBDIR}
DISTFILES=	${PYTHON_DISTFILE}

MAINTAINER=	perky@FreeBSD.org
COMMENT?=	An interpreted object-oriented programming language

CONFLICTS=	stackless_python-*
DIST_SUBDIR=	python
WRKSRC=		${PYTHON_WRKSRC}
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	OPT="${CFLAGS}"
MAKE_ENV=	VPATH="${WRKSRC}"
INSTALLS_SHLIB=	yes
INSTALL_TARGET=	install
MAN1=		python.1

USE_PYTHON=	yes
PYTHON_VERSION=	python2.4
PYTHON_NO_DEPENDS=	yes
USE_REINPLACE=	yes

SHARED_WRKSRC=	${WRKSRC}/build.shared
PLIST=		${WRKDIR}/pkg-plist
PLIST_SUB=	PYVER=${PYTHON_VERSION:S/python//}
DEMODIR=	${PREFIX}/share/examples/${PYTHON_VERSION}
TOOLSDIR=	${PREFIX}/share/${PYTHON_VERSION}

OPTIONS=	THREADS "Enable thread support" on \
		HUGE_STACK_SIZE "Use a larger thread stack" off \
		UCS4 "Use UCS4 for unicode support" on \
		PYMALLOC "Use python's internal malloc" on \
		IPV6 "Enable IPv6 support" on \
		FPECTL "Enable floating point exception handling" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=	--with-threads
CFLAGS+=		${PTHREAD_CFLAGS}
.if defined(WITHOUT_HUGE_STACK_SIZE)
CFLAGS+=		-DTHREAD_STACK_SIZE=0x20000
.else
CFLAGS+=		-DTHREAD_STACK_SIZE=0x100000
.endif # defined(WITHOUT_HUGE_STACK_SIZE)
CONFIGURE_ENV+=		LDFLAGS="${PTHREAD_LIBS} ${LDFLAGS}"
.else
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

.if ${ARCH} == i386
PLIST_SUB+=	X86_ONLY=""
.else
PLIST_SUB+=	X86_ONLY="@comment "
.endif
.if ${ARCH} == amd64 || ${ARCH} == ia64 || ${ARCH} == sparc64 || ${ARCH} == alpha
PLIST_SUB+=	32BIT_ONLY="@comment "
.else
PLIST_SUB+=	32BIT_ONLY=""
.endif
.if ${ARCH} == sparc64
CFLAGS+=	-DPYTHON_DEFAULT_RECURSION_LIMIT=900
.endif

.if !defined(WITHOUT_IPV6) && ${OSVERSION} >= 400014
CONFIGURE_ARGS+= --enable-ipv6
.else
CONFIGURE_ARGS+= --disable-ipv6
.endif

.if defined(WITH_FPECTL)
CONFIGURE_ARGS+= --with-fpectl
.endif

.if ${OSVERSION} >= 700000
PLATFORMS=plat-freebsd4 plat-freebsd5 plat-freebsd6
.elif ${OSVERSION} >= 600000
PLATFORMS=plat-freebsd4 plat-freebsd5 plat-freebsd7
.elif ${OSVERSION} >= 500000
PLATFORMS=plat-freebsd4 plat-freebsd6 plat-freebsd7
.else
PLATFORMS=plat-freebsd5 plat-freebsd6 plat-freebsd7
.endif

post-extract:
	${SED} -e '1s,^.*$$,#!${PREFIX}/bin/${PYTHON_VERSION},' \
		${WRKSRC}/Tools/scripts/pydoc > ${WRKDIR}/pydoc2.4
	${SED} -e '1s,^.*$$,#!${PREFIX}/bin/${PYTHON_VERSION},' \
		${WRKSRC}/Tools/scripts/idle > ${WRKDIR}/idle2.4
	${SED} -e '1s,^.*$$,#!${PREFIX}/bin/${PYTHON_VERSION},' \
		${WRKSRC}/Lib/smtpd.py > ${WRKDIR}/smtpd2.4.py

pre-patch:
	${REINPLACE_CMD} -e \
		's,/usr/doc/python-docs-,${PREFIX}/share/doc/python,g' \
		${WRKSRC}/Lib/pydoc.py
	${REINPLACE_CMD} -e \
		's|^\( *prefixes = .*\)\]$$|\1, "${X11BASE}"]|g' \
		${WRKSRC}/Lib/site.py
.if defined(WITH_FPECTL) && ${ARCH} == i386
	${ECHO} "fpectl fpectlmodule.c" >> ${WRKSRC}/Modules/Setup.dist
.endif

post-configure:
	@# prepare a subdir for shared build
.for subdir in Modules Parser Python Objects
	${MKDIR} ${SHARED_WRKSRC}/${subdir}
.endfor
	${SED} -e 's,^\(LDLIBRARY=\).*$$,\1libpython$$(VERSION).so,' \
		-e 's,^\(BLDLIBRARY=\).*$$,\1-L. -lpython$$(VERSION),' \
		-e 's,^\(CFLAGSFORSHARED=\).*$$,\1$$(CCSHARED),' \
		-e 's,^\(Makefile Modules/config.c:.*\)Makefile.pre,\1,' \
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
.if !exists(/usr/bin/rpcgen) # the world with NO_NIS
	${GREP} -v 'nis.so$$' ${PKGDIR}/pkg-plist > ${PLIST}
.else
	${CP} ${PKGDIR}/pkg-plist ${PLIST}
.endif

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
	cd ${PREFIX}/bin; \
		${LN} -f ${PYTHON_VERSION:S/thon/thon-shared/} python-shared

	@# additional files installing by ports
	${INSTALL_DATA} ${WRKSRC}/Misc/python-mode.el \
		${PREFIX}/share/emacs/site-lisp
	${INSTALL_SCRIPT} ${WRKDIR}/pydoc2.4 ${WRKDIR}/idle2.4 \
		${WRKDIR}/smtpd2.4.py ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	@${MKDIR} ${TOOLSDIR}
	@cd ${WRKSRC}; tar -c --exclude='*CVS*' -f - Tools | \
		(cd ${TOOLSDIR}; tar xf -)
	@${MKDIR} ${DEMODIR}
	@cd ${WRKSRC}/Demo; tar -c --exclude='*CVS*' -f - * | \
		(cd ${DEMODIR}; tar xf -)
.endif

	@${CAT} ${PKGMESSAGE}

PORTUPGRADE?=	${LOCALBASE}/sbin/portupgrade
PKG_WHICH?=	${LOCALBASE}/sbin/pkg_which
upgrade-site-packages:
	@if [ -x ${PORTUPGRADE} ]; then \
		for ver in 2.1 2.2 2.3; do \
			if [ -d ${PREFIX}/lib/python$$ver ]; then \
				UPD=`${FIND} ${PREFIX}/lib/python$$ver \
						-type f -print0 | \
					${XARGS} -0 ${PKG_WHICH} | \
					${GREP} -Fv '?' | \
					${GREP} -v '^python-2' | \
					${SORT} -u`; \
				if [ "$$UPD" ]; then \
					${PORTUPGRADE} -f $$UPD; \
				fi; \
			fi; \
		done; \
	 else \
		${ECHO_MSG} "Please install sysutils/portupgrade."; \
		${FALSE}; \
	 fi

.include <bsd.port.post.mk>
