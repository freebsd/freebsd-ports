# New ports collection makefile for:    python
# Date created:         08 August 1995
# Whom:                 jkh
#
# $FreeBSD$
#

PORTNAME=	python
PORTVERSION=	2.3.3
PORTREVISION=	1
CATEGORIES=	lang python ipv6
MASTER_SITES=	${PYTHON_MASTER_SITES}
MASTER_SITE_SUBDIR=	${PYTHON_MASTER_SITE_SUBDIR}
DISTFILES=	${PYTHON_DISTFILE}

MAINTAINER=	perky@FreeBSD.org
COMMENT?=	An interpreted object-oriented programming language

DIST_SUBDIR=	python
WRKSRC=		${PYTHON_WRKSRC}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-fpectl
CONFIGURE_ENV=	OPT="${CFLAGS}"
MAKE_ENV=	VPATH="${WRKSRC}"
INSTALL_TARGET=	install
MAN1=		python.1

USE_PYTHON=	yes
PYTHON_VERSION=	python2.3
PYTHON_NO_DEPENDS=	yes
USE_REINPLACE=	yes

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
CONFIGURE_ARGS+=	--without-pymalloc
.endif

.if defined(BUILD_SHARED)
CONFIGURE_ARGS+=	--enable-shared
INSTALLS_SHLIB=		yes
PLIST_SUB+=		SHARED_ONLY=""
.else
PLIST_SUB+=		SHARED_ONLY="@comment "
.endif

DEMODIR=	${PREFIX}/share/examples/${PYTHON_VERSION}
TOOLSDIR=	${PREFIX}/share/${PYTHON_VERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
PLIST_SUB+=	X86_ONLY=""
.else
PLIST_SUB+=	X86_ONLY="@comment "
.endif
.if ${ARCH} == amd64
CFLAGS+=	-fPIC
.endif
.if ${ARCH} == amd64 || ${ARCH} == ia64 || ${ARCH} == sparc64 || ${ARCH} == alpha
PLIST_SUB+=	32BIT_ONLY="@comment "
.else
PLIST_SUB+=	32BIT_ONLY=""
.endif
.if ${ARCH} == sparc64
CFLAGS+=	-DPYTHON_DEFAULT_RECURSION_LIMIT=900
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
		${WRKSRC}/Tools/scripts/pydoc > ${WRKDIR}/pydoc2.3
	${SED} -e '1s,^.*$$,#!${PREFIX}/bin/${PYTHON_VERSION},' \
		${WRKSRC}/Tools/scripts/idle > ${WRKDIR}/idle2.3

post-patch:
	${REINPLACE_CMD} -e \
		's,/usr/doc/python-docs-,${PREFIX}/share/doc/python,g' \
		${WRKSRC}/Lib/pydoc.py

pre-install:
.for platform in ${PLATFORMS}
	${MKDIR} ${PYTHONPREFIX_LIBDIR}/${platform}
.for file in IN.py regen
	${INSTALL_DATA} ${WRKSRC}/Lib/${platform}/${file} \
		${PYTHONPREFIX_LIBDIR}/${platform}/
.endfor
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/Misc/python-mode.el \
		${PREFIX}/share/emacs/site-lisp
	${INSTALL_SCRIPT} ${WRKDIR}/pydoc2.3 ${WRKDIR}/idle2.3 \
		${PREFIX}/bin

.if !defined(NOPORTDOCS)
	@${MKDIR} ${TOOLSDIR}
	@cd ${WRKSRC}; tar -c --exclude='*CVS*' -f - Tools | \
		(cd ${TOOLSDIR}; tar xf -)
	@${MKDIR} ${DEMODIR}
	@cd ${WRKSRC}/Demo; tar -c --exclude='*CVS*' -f - * | \
		(cd ${DEMODIR}; tar xf -)
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
