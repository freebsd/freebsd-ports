# $FreeBSD$

PORTNAME=	newt
PORTVERSION=	0.52.17
CATEGORIES=	devel
MASTER_SITES=	https://fedorahosted.org/releases/n/e/newt/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Not Eriks Windowing Toolkit: console I/O handling library

LIB_DEPENDS=	libslang.so:${PORTSDIR}/devel/libslang2 \
		libpopt.so:${PORTSDIR}/devel/popt

USES=		gmake
GNU_CONFIGURE=	yes
MAKE_ENV=	PCFLAGS="${CFLAGS}"
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lcurses

PLIST_SUB=	SOVERSION="${SOVERSION}" \
		VERSION="${PORTVERSION}"

SUB_FILES=	pkgIndex.tcl
SUB_LIST=	VERSION="${PORTVERSION}"

OPTIONS_DEFINE=		NLS TCL
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
TCL_USES=		tcl
TCL_CONFIGURE_ENV=	ac_cv_c_tclconfig=${TCL_LIBDIR:Q}
TCL_CONFIGURE_WITH=	tcl
TCL_CPPFLAGS=		-I${TCL_INCLUDEDIR:Q}

SOVERSION=	${PORTVERSION:R:E}

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SONAME/s|=.*|=${SOVERSION}| ; \
		 s|-DUSE_INTERP_RESULT||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|@CPP@|@CC@ -E| ; \
		 s|-I/usr/include/slang|| ; \
		 /^pkgconfigdir/s|=.*|=${PREFIX}/libdata/pkgconfig| ; \
		 s| -g | |g ; \
		 /make -C/s|^|#| ; \
		 /whiptcl.$$(SOEXT)/s|install|${TRUE}|' ${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/whiptail
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnewt.so
.if ${PORT_OPTIONS:MNLS}
	@(cd ${WRKSRC}/po && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} datadir=${STAGEDIR}${PREFIX}/share \
		${INSTALL_TARGET})
.endif
.if ${PORT_OPTIONS:MTCL}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/whip${PORTVERSION}
	(cd ${WRKSRC} && ${INSTALL_LIB} whiptcl.so \
		${STAGEDIR}${PREFIX}/lib/whip${PORTVERSION})
	(cd ${WRKDIR} && ${INSTALL_DATA} pkgIndex.tcl \
		${STAGEDIR}${PREFIX}/lib/whip${PORTVERSION})
.endif

.include <bsd.port.mk>
