# $FreeBSD$

PORTNAME=	newt
PORTVERSION=	0.52.15
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://fedorahosted.org/releases/n/e/newt/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Not Erik's Windowing Toolkit: console I/O handling library

LIB_DEPENDS=	slang:${PORTSDIR}/devel/libslang2 \
		popt:${PORTSDIR}/devel/popt

OPTIONS_DEFINE=	PYTHON TCL NLS

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ENV=	PCFLAGS="${CFLAGS}" TCLVERSION="tcl${TCL_VER}"
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lcurses

PLIST_SUB=	SOVERSION="${SOVERSION}" \
		VERSION="${PORTVERSION}"

SUB_LIST=	VERSION="${PORTVERSION}"

MAN1=		whiptail.1

SOVERSION=	${PORTVERSION:R:E}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	-2.7
INSTALLS_EGGINFO=	yes
PLIST_SUB+=	PYTHONOPT=""
SUB_FILES+=	setup.py
.else
PLIST_SUB+=	PYTHONOPT="@comment "
.endif

.if ${PORT_OPTIONS:MTCL}
USE_TCL=	84+
MAKE_ENV+=	TCL_LIBDIR=${TCL_LIBDIR:Q}
CPPFLAGS+=	-I${TCL_INCLUDEDIR:Q}
SUB_FILES+=	pkgIndex.tcl
PLIST_SUB+=	TCLOPT="" TCL_LIBDIR=${TCL_LIBDIR:S,${PREFIX}/,,}
.else
CONFIGURE_ARGS+=--without-tcl
PLIST_SUB+=	TCLOPT="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SONAME/s|=.*|=${SOVERSION}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|@CPP@|@CC@ -E| ; \
		 s|-I/usr/include/slang|| ; \
		 /^PYTHONVERS/s|=.*|=${PYTHON_VERSION}| ; \
		 /^pkgconfigdir/s|=.*|=${PREFIX}/libdata/pkgconfig| ; \
		 s| -g | |g ; \
		 /make -C/s|^|#| ; \
		 /whiptcl.so/s|install|${TRUE}|' ${WRKSRC}/Makefile.in

post-build:	apply-slist
.if ${PORT_OPTIONS:MPYTHON}
	@${LN} -sf libnewt.so.${SOVERSION} ${WRKSRC}/libnewt.so
	@(cd ${WRKSRC} && ${MAKE_ENV} ${PYTHON_CMD} ${WRKDIR}/setup.py \
		build)
.endif

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/whiptail
.if ${PORT_OPTIONS:MNLS}
	@(cd ${WRKSRC}/po && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} datadir=${PREFIX}/share \
		${INSTALL_TARGET})
.endif
.if ${PORT_OPTIONS:MPYTHON}
	@(cd ${WRKSRC} && ${MAKE_ENV} ${PYTHON_CMD} ${WRKDIR}/setup.py \
		install --prefix=${PREFIX})
.endif
.if ${PORT_OPTIONS:MTCL}
	@${MKDIR} ${TCL_LIBDIR}/whip
	(cd ${WRKSRC} && ${INSTALL_DATA} whiptcl.so ${TCL_LIBDIR}/whip)
	(cd ${WRKDIR} && ${INSTALL_DATA} pkgIndex.tcl ${TCL_LIBDIR}/whip)
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} peanuts.py popcorn.py ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
